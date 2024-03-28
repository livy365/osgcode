//#include <osg/ref_ptr> 

#include"eventhandle.h"
#include"orb.h"
#include"plantwithorb.h"
#include"manupulator.h"
#include <osgDB/readFile> 
#include "osgFX/AnisotropicLighting"



osg::ref_ptr<osg::Node> plant(int radius);
void settex(osg::Node* pnode, std::string picturefile);

osg::ref_ptr<osg::Node> circle(int radius, double degree, osg::Vec3 center);
osg::ref_ptr<osg::Node> tail(int radius, double degree, osg::Vec3 center);
/*osg::ref_ptr<osg::Node> createDrawable()
{
	// 创建一个用于保存几何信息的对象
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	// 创建四个顶点的数组
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());
	v->push_back(osg::Vec3(-1.5f, 0.f, -1.5f));
	v->push_back(osg::Vec3(1.5f, 0.f, -1.5f));
	v->push_back(osg::Vec3(1.5f, 0.f, 1.5f));
	v->push_back(osg::Vec3(-1.5f, 0.f, 1.5f));

	osg::ref_ptr<osg::Vec2Array> tc = new osg::Vec2Array;
	geom->setTexCoordArray(0, tc.get());
	tc->push_back(osg::Vec2(0.f, 0.f));
	tc->push_back(osg::Vec2(1.0f, 0.f));
	tc->push_back(osg::Vec2(1.0f, 1.0f));
	tc->push_back(osg::Vec2(0.f, 1.0f));

	osg::ref_ptr<osg::Vec2Array> tc1 = new osg::Vec2Array;
	geom->setTexCoordArray(1, tc1.get());
	tc1->push_back(osg::Vec2(0.f, 0.f));
	tc1->push_back(osg::Vec2(0.5f, 0.f));
	tc1->push_back(osg::Vec2(0.5f, 1.0f));
	tc1->push_back(osg::Vec2(0.f, 1.0f));




	// 创建四种颜色的数组
	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 1.f, 1.f, 1.f));
	


	// 为唯一的法线创建一个数组
	osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array;
	geom->setNormalArray(n.get());
	geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
	n->push_back(osg::Vec3(0.f, -1.f, 0.f));


	// 由保存的数据绘制四个顶点的多边形
	geom->addPrimitiveSet(
		new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));

	// 向 Geode 类添加几何体（Drawable）并返回 Geode 
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geom.get());
	return geode.get();
} */
osg::ref_ptr<osg::Switch> circleSwitch = new osg::Switch;
osg::ref_ptr<osg::Switch> infSwitch = new osg::Switch;
osg::ref_ptr<osg::Node>solarinf = new osg::Node;
osg::ref_ptr<osg::Geode> inf(wchar_t words[]);
osg::ref_ptr<osg::Camera> hud();
void setinf(std::string name, wchar_t words[]);


osg::ref_ptr<osg::LightSource> pLightSource() {

	osg::ref_ptr<osg::LightSource> pLightSource = new osg::LightSource;
	osg::ref_ptr<osg::Light> light = new osg::Light;
	light->setAmbient(osg::Vec4(.1f, .1f, .1f, 1.f));
	light->setDiffuse(osg::Vec4(.8f, .8f, .8f, 1.f));
	light->setSpecular(osg::Vec4(.8f, .8f, .8f, 1.f)); 
	light->setPosition(osg::Vec4(0.f, 0.f, 0.f,1.0f));
	light->setDirection(osg::Vec3(0.f, 1.f, 0.f));

	// 设置散射光颜色: 红光/白光
	light->setDiffuse(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	// 设置常量衰减指数
	light->setConstantAttenuation(1.0);
	// 设置线行衰减指数
	light->setLinearAttenuation(0.0);
	// 设置二次衰减指数
	light->setQuadraticAttenuation(0.0);
	
	pLightSource->setLight(light.get());

	return pLightSource;
}

osg::ref_ptr<osg::Node> sun = plant(10);
int main()
{
	
	osg::ref_ptr<osg::Group> rpGroup = new osg::Group;
	osg::ref_ptr<osgViewer::Viewer> rpViewer = new osgViewer::Viewer;
	
	

	//osg::ref_ptr<osg::Node> sun =plant(10);
	std::string sunfile = "SolarSystem/2k_sun.jpg";
	settex(sun, sunfile);
	osg::ref_ptr<osg::MatrixTransform> sunselfrotate = new osg::MatrixTransform;
	sunselfrotate->setDataVariance(osg::Object::DYNAMIC);
	sunselfrotate->setUpdateCallback(new rotation(0.005));
	sunselfrotate->addChild(sun);
	sun->setName("sun");
	osg::StateSet* state = sun->getOrCreateStateSet();
	state->setMode(GL_LIGHTING, osg::StateAttribute::OFF |
		osg::StateAttribute::PROTECTED);
	
	osg::ref_ptr<osg::Node> earth = plant(5);
	osg::ref_ptr<osg::Node> earthcircle = circle(100, 0.0, osg::Vec3(1, 0, 0));
	
	
	osg::ref_ptr<osg::Node> earthtail = tail(100, 0.0, osg::Vec3(1, 0, 0));
	
	osg::ref_ptr<osg::MatrixTransform> earthtailrotate = new osg::MatrixTransform;
	earthtailrotate->setDataVariance(osg::Object::DYNAMIC);
	earthtailrotate->setUpdateCallback(new rotation(0.006));
	earthtailrotate->addChild(earthtail);
	earthtailrotate->setName("earthtail");
	
	earth->setName("earth");
	earthcircle->setName("earthcircle");
	osg::ref_ptr<osg::MatrixTransform> earthorb = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> earthselfrotate = new osg::MatrixTransform;
	
    
	std::string earthfile = "Images/land_shallow_topo_2048.jpg";
	settex(earth,earthfile);
	earthorb->setDataVariance(osg::Object::DYNAMIC);
	Orbitalrevolutiontate *earthrotate=new Orbitalrevolutiontate(0.006);
	earthrotate->setcenter(osg::Vec3(0, 0, 1));
	earthrotate->setradius(osg::Vec3(100, 0, 0));
	earthorb->setUpdateCallback(earthrotate);
	earthselfrotate->setDataVariance(osg::Object::DYNAMIC);
	earthselfrotate->setUpdateCallback(new rotation);
	earthselfrotate->addChild(earth);
	earthorb->addChild(earthselfrotate.get());
	rpGroup->addChild(earthorb.get());
	
	osg::ref_ptr<osg::Node> mars = plant(3.5);
	osg::ref_ptr<osg::Node> marscircle = circle(120, 30.0, osg::Vec3(1, 0, 0));
	mars->setName("mars");
	marscircle->setName("marscircle");
	std::string marsfile = "SolarSystem/mars256128.jpg";
	settex(mars, marsfile);
	osg::ref_ptr<osg::MatrixTransform> marsorb = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> marsselfrotate = new osg::MatrixTransform;
	marsorb->setDataVariance(osg::Object::DYNAMIC);
	Orbitalrevolutiontate* marsrotate = new Orbitalrevolutiontate(0.0055);
	marsrotate->setcenter(osg::Vec3(0, -sin((PI / 180) * (30)), cos((PI / 180) * (30))));
	marsrotate->setradius(osg::Vec3(120, 0, 0));
	marsorb->setUpdateCallback(marsrotate);
	marsselfrotate->setDataVariance(osg::Object::DYNAMIC);
	marsselfrotate->setUpdateCallback(new rotation);
	marsselfrotate->addChild(mars);
	marsorb->addChild(marsselfrotate.get());
	rpGroup->addChild(marsorb.get());

	osg::ref_ptr<osg::Node> marstail = tail(120, 30.0, osg::Vec3(1, 0, 0));
	osg::ref_ptr<osg::MatrixTransform> marstailrotate = new osg::MatrixTransform;
	Orbitalrevolutiontate* marstailrotateclass = new Orbitalrevolutiontate(0.0055);
	marstailrotateclass->setcenter(osg::Vec3(0, -sin((PI / 180) * (30)), cos((PI / 180) * (30))));
	marstailrotateclass->setradius(osg::Vec3(0, 0, 0));
	marstailrotate->setDataVariance(osg::Object::DYNAMIC);
	marstailrotate->setUpdateCallback(marstailrotateclass);
	marstailrotate->addChild(marstail);
	marstailrotate->setName("marstail");


	
	circleSwitch->setNewChildDefaultValue(false);
	circleSwitch->addChild(earthcircle.get());
	circleSwitch->addChild(marscircle.get());
	circleSwitch->addChild(earthtailrotate.get());
	circleSwitch->addChild(marstailrotate.get());
	osg::ref_ptr<osg::LightSource> LightSource = pLightSource();
	rpGroup->addChild(LightSource.get());

	plants venus;
	venus.setplantsradiusandname(3, "venus", "SolarSystem/venus256128.jpg");
	venus.setcircle(80, 30, osg::Vec3(0, 1, 0));
	venus.setplantsinf(L"金星\n");
	rpGroup->addChild(venus.setplants(0.0065).get());
	

	plants mercury;
	mercury.setplantsradiusandname(4, "mercury", "SolarSystem/mercury256128.jpg");
	mercury.setcircle(60, 60, osg::Vec3(1, 0, 0));
	mercury.setplantsinf(L"水星\n");
	rpGroup->addChild(mercury.setplants(0.007).get());
	

	plants Jupiter;
	Jupiter.setplantsradiusandname(4, "Jupiter", "SolarSystem/Jupiter256128.jpg");
	Jupiter.setcircle(140, 90, osg::Vec3(1, 0, 0));
	Jupiter.setplantsinf(L"木星\n");
	rpGroup->addChild(Jupiter.setplants(0.005).get());
	
	plants Saturn;
	Saturn.setplantsradiusandname(4, "Saturn", "SolarSystem/Saturn256128.jpg");
	Saturn.setcircle(160, 60, osg::Vec3(0, 1, 0));
	Saturn.setplantsinf(L"土星\n");
	rpGroup->addChild(Saturn.setplants(0.004).get());

	plants Uranus;
	Uranus.setplantsradiusandname(4, "Uranus", "SolarSystem/Uranus256128.jpg");
	Uranus.setcircle(180, 90, osg::Vec3(0, 1, 0));
	Uranus.setplantsinf(L"天王星\n");
	rpGroup->addChild(Uranus.setplants(0.003).get());


	plants Neptune;
	Neptune.setplantsradiusandname(4, "Neptune", "SolarSystem/Neptune256128.jpg");
	Neptune.setcircle(200, 120, osg::Vec3(0, 1, 0));
	Neptune.setplantsinf(L"海王星\n");
	rpGroup->addChild(Neptune.setplants(0.001).get());

	solarinf = inf(L"太阳系\n");
	osg::ref_ptr<osg::Node>suninf = inf(L"太阳\n");
	osg::ref_ptr<osg::Camera> texthud= hud();
	infSwitch->addChild(solarinf.get(),true);
	infSwitch->addChild(suninf.get(), false);
	suninf->setName("suninf");
	
	setinf("earthinf", L"地球\n");
	setinf("marsinf", L"火星\n");  
	
	

	texthud->addChild(infSwitch.get());
	rpGroup->addChild(texthud.get());
	rpGroup->addChild(sunselfrotate.get());
	rpGroup->addChild(circleSwitch.get());
	rpViewer->setSceneData(rpGroup.get());
	rpViewer->addEventHandler(new pushhandle);
	rpViewer->getCamera()->setClearColor(osg::Vec4(0, 0, 0, 1));
	osg::ref_ptr< CDriveManupulator> rpDriveMp = new CDriveManupulator();
	rpViewer->setCameraManipulator(rpDriveMp.get()/*new osgGA::TrackballManipulator()*/);
	//rpGroup->addChild(rpDriveMp->getBallNode());

	rpViewer->realize();
	rpViewer->run();
	
	
	




	return 0;
}