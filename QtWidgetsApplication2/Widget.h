#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDir>

#include <osgQOpenGL/osgQOpenGLWidget>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/Texture2D>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

    osg::Camera* backGround(QString sImagePath, int iWidth, int iHeight);

    void resizeEvent(QResizeEvent* event) override;

protected slots:
    void onChoseFileButtonClicked();
    void onChoseDirButtonClicked();
    void onShowModelButtonClicked();
    void onClearButtonClicked();
    void initOsgWindow();

private:
    Ui::Widget* ui;
    osgQOpenGLWidget* _pOsgWidget;
    osg::ref_ptr<osgViewer::Viewer> _viewer;

    QStringList _lFileNames;
};
#endif // WIDGET_H

