
#include <osgText/Text>
#include <osgText/Font>
#include<osgUtil/Optimizer>
#include <osgViewer/ViewerEventHandlers>


extern osg::ref_ptr<osg::Switch> infSwitch;

osg::ref_ptr<osg::Geode> inf(wchar_t words[])
{
	osg::ref_ptr<osgText::Text>text = new osgText::Text;
	osg::ref_ptr<osgText::Font>font = new osgText::Font;
	font = osgText::readFontFile("fonts/simhei.ttf");
	text->setFont(font.get());
	text->setText(words);

	text->setCharacterSize(110.0f);

	text->setAutoRotateToScreen(true);
	text->setColor(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
	osg::Vec3f position = osg::Vec3f(960.0f, 1080.0f, 0.0f);
	text->setPosition(position);
	text->setDrawMode(osgText::Text::TEXT | osgText::Text::BOUNDINGBOX);
	text->setAlignment(osgText::Text::CENTER_TOP);
	text->setAxisAlignment(osgText::Text::SCREEN);
	osg::ref_ptr<osg::Geode>geode = new osg::Geode;
	geode->addDrawable(text.get());

	osg::StateSet* state = geode->getOrCreateStateSet();
	state->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF |
		osg::StateAttribute::PROTECTED);
	state->setMode(GL_LIGHTING, osg::StateAttribute::OFF |
		osg::StateAttribute::PROTECTED);
	return geode.get();

}
osg::ref_ptr<osg::Camera> hud()
{
	osg::ref_ptr<osg::Camera>pCamera = new osg::Camera();
	// set the projection matri
	pCamera->setProjectionMatrix(osg::Matrix::ortho2D(0, 1920, 0, 1080));
	// set the view matrix
	pCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	pCamera->setViewMatrix(osg::Matrix::identity());
	// only clear the depth buffer
	pCamera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// draw subgraph after main camera view.
	pCamera->setRenderOrder(osg::Camera::POST_RENDER);
	// we don't want the camera to grab event focus from the viewers main camera(s).
	pCamera->setAllowEventFocus(false);
	pCamera->setViewport(0, 0, 570, 324);//设置窗口位置大小
	pCamera->setClearColor(osg::Vec4(0, 0.5, 1, 0));
	return pCamera.get();
}
void setinf(std::string name, wchar_t words[])
{
	osg::ref_ptr<osg::Node>plantsinf = inf(words);
	infSwitch->addChild(plantsinf.get(), false);
	plantsinf->setName(name);

}