#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    _pOsgWidget = new osgQOpenGLWidget(this);
    _pOsgWidget->setGeometry(22, 1000, 58, 58);
    //    _pOsgWidget->setHidden(true);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onChoseFileButtonClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onChoseDirButtonClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onShowModelButtonClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(_pOsgWidget, SIGNAL(initialized()), this, SLOT(initOsgWindow()));
}

Widget::~Widget()
{
    delete ui;
}

osg::Camera* Widget::backGround(QString sImagePath, int iWidth, int iHeight)
{
    osg::ref_ptr<osg::Camera> camera = new osg::Camera;

    camera->setAllowEventFocus(false);
    camera->setProjectionMatrixAsOrtho2D(0, iWidth, 0, iHeight);
    camera->setViewport(0, 0, iWidth, iHeight);

    camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
    camera->setRenderOrder(osg::Camera::PRE_RENDER);
    camera->setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    camera->setViewMatrix(osg::Matrix::identity());
    //    camera->setRenderOrder(osg::Camera::NESTED_RENDER);

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    //    geode->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
    geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

    osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
    osg::ref_ptr<osg::Vec3Array> vertex = new osg::Vec3Array;
    vertex->push_back(osg::Vec3(0, 0, 0));
    vertex->push_back(osg::Vec3(iWidth, 0, 0));
    vertex->push_back(osg::Vec3(iWidth, iHeight, 0));
    vertex->push_back(osg::Vec3(0, iHeight, 0));
    geometry->setVertexArray(vertex);

    osg::ref_ptr<osg::Vec3Array> normal = new osg::Vec3Array;
    normal->push_back(osg::Vec3(0.0, 0.0, 1.0));
    geometry->setNormalArray(normal);
    geometry->setNormalBinding(osg::Geometry::BIND_OVERALL);

    osg::ref_ptr<osg::Vec2Array> texCoord = new osg::Vec2Array;
    texCoord->push_back(osg::Vec2(0.0, 0.0));
    texCoord->push_back(osg::Vec2(1.0, 0.0));
    texCoord->push_back(osg::Vec2(1.0, 1.0));
    texCoord->push_back(osg::Vec2(0.0, 1.0));
    geometry->setTexCoordArray(0, texCoord);

    geometry->addPrimitiveSet(new osg::DrawArrays(osg::DrawArrays::QUADS, 0, 4));

    osg::ref_ptr<osg::Image> img = osgDB::readImageFile(sImagePath.toStdString());

    osg::ref_ptr<osg::Texture2D> tex = new osg::Texture2D;
    tex->setImage(img);
    //    tex->setUnRefImageDataAfterApply(true);
    geometry->getOrCreateStateSet()->setTextureAttributeAndModes(0, tex.get(), osg::StateAttribute::ON);

    geode->addDrawable(geometry);
    camera->addChild(geode);

    return camera.release();
}

void Widget::resizeEvent(QResizeEvent*)
{
    _pOsgWidget->setGeometry(220, 0, this->width() - 120, this->height() - 20);
    ui->textBrowser->setGeometry(10, 130, 190, this->height() - 150);
    //    initOsgWindow();
}

void Widget::onChoseFileButtonClicked()
{
    _lFileNames.append(QFileDialog::getOpenFileNames(this, "Select osgb files", "C:/Users/Administrator/Deskop", "Osgb(*.stl)"));

    for (auto file : _lFileNames)
    {
        ui->textBrowser->append(file);
        ui->textBrowser->append("\n");
    }
}

void Widget::onChoseDirButtonClicked()
{
    QFileInfoList infoList1 = QDir(QFileDialog::getExistingDirectory()).entryInfoList();
    for (auto file : infoList1)
    {
        if (file.isFile() && file.suffix().toStdString() == "stl")
        {
            _lFileNames.push_back(file.filePath());
            ui->textBrowser->append(file.filePath());
            ui->textBrowser->append("\n");
        }
    }
}

void Widget::onShowModelButtonClicked()
{
    initOsgWindow();
}

void Widget::onClearButtonClicked()
{
    _lFileNames.clear();
    ui->textBrowser->setText("");
    initOsgWindow();
}

void Widget::initOsgWindow()
{
    _viewer = _pOsgWidget->getOsgViewer();

    // +++++++++这一句很重要++++++++++++
    _viewer->getCamera()->setClearMask(GL_DEPTH_BUFFER_BIT);
    // +++++++++这一句很重要++++++++++++

    _viewer->setCameraManipulator(new osgGA::TrackballManipulator);
    osg::ref_ptr<osg::Group> group = new osg::Group;
    group->addChild(backGround("here_add_your_back_ground_image_path", _pOsgWidget->width(), _pOsgWidget->height()));
    for (auto file : _lFileNames)
    {
        group->addChild(osgDB::readNodeFile(file.toStdString()));
    }
    _viewer->setSceneData(group);
}
