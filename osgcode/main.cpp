#include <osgDB/readFile> 
#include <osgViewer/Viewer>
#include <osg/ref_ptr>
#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/ShapeDrawable>

#include"shiftandrotate.h"
#include"eventhandle.h"
#include"stock.h"
#include"knife.h"
#include"claw.h"
#include"tail.h"
stocks cy;
zshift* Z = new zshift;
xshift* X = new xshift;
yrshift* YR = new yrshift;
knife knives;
claw1Call* claw1Callback=new claw1Call;
tailCall* tailCallback = new tailCall;
tail_foundation_Call* tail_foundation_back = new tail_foundation_Call;


int main()
{
osg::ref_ptr<osgViewer::Viewer> rpViewer = new osgViewer::Viewer;
osg::ref_ptr<osg::Group> rpGroup = new osg::Group;
osg::ref_ptr<osg::Node> rpCow = osgDB::readNodeFile("´²Éí.stl");
rpGroup->addChild(rpCow.get());


osg::ref_ptr < osg::MatrixTransform >zaxis = new osg::MatrixTransform;
rpGroup->addChild(zaxis.get());
zaxis->setDataVariance(osg::Object::DYNAMIC);
//zshift *Z= new zshift;
zaxis->setUpdateCallback(Z);
//Z->setlength(500.0);
osg::ref_ptr<osg::Node> znode = osgDB::readNodeFile("ZÖá.stl");
zaxis->addChild(znode.get());

osg::ref_ptr < osg::MatrixTransform >xaxis = new osg::MatrixTransform;
zaxis->addChild(xaxis.get());
xaxis->setDataVariance(osg::Object::DYNAMIC);
//xshift* X = new xshift;
xaxis->setUpdateCallback(X);

osg::ref_ptr<osg::Node> xnode = osgDB::readNodeFile("XÖá.stl");
xaxis->addChild(xnode.get());


osg::ref_ptr < osg::MatrixTransform >yraxis = new osg::MatrixTransform;
xaxis->addChild(yraxis.get());
yraxis->setDataVariance(osg::Object::DYNAMIC);
yraxis->setUpdateCallback(YR);
osg::ref_ptr<osg::Node> yrnode = osgDB::readNodeFile("µ¶¼Ü.stl");
yraxis->addChild(yrnode.get());


/*osg::ref_ptr<osg::Box> box = new osg::Box;
box->setCenter(osg::Vec3(30, 215, -790));
box->setHalfLengths(osg::Vec3(70.0, 25.0, 10.0));
osg::ref_ptr<osg::ShapeDrawable> sd1 = new osg::ShapeDrawable(box.get());
sd1->setColor(osg::Vec4(0, 1, 1, 0.5));


box->setCenter(osg::Vec3(-171.6741, 215, -798.3259));
box->setHalfLengths(osg::Vec3(10.0, 25.0, 70.0));
osg::ref_ptr<osg::ShapeDrawable> sd2 = new osg::ShapeDrawable(box.get());
sd2->setColor(osg::Vec4(1, 0, 0, 0.5));


box->setCenter(osg::Vec3(-180, 215, -596.6518));
box->setHalfLengths(osg::Vec3(70.0, 25.0, 10.0));
osg::ref_ptr<osg::ShapeDrawable> sd3 = new osg::ShapeDrawable(box.get());
sd3->setColor(osg::Vec4(0, 1, 0, 0.5));


box->setCenter(osg::Vec3(21.6741, 215, -588.3259));
box->setHalfLengths(osg::Vec3(10.0, 25.0, 70.0));
osg::ref_ptr<osg::ShapeDrawable> sd4 = new osg::ShapeDrawable(box.get());
sd4->setColor(osg::Vec4(0, 0, 0, 0.5));







osg::ref_ptr<osg::Geode> geode = new osg::Geode;
osg::ref_ptr<osg::StateSet>state = geode->getOrCreateStateSet();
state->setMode(GL_BLEND, osg::StateAttribute::ON |
	osg::StateAttribute::PROTECTED);
state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

geode->addDrawable(sd1.get());
geode->addDrawable(sd2.get());
geode->addDrawable(sd3.get());
geode->addDrawable(sd4.get());
yraxis->addChild(geode.get());*/
yraxis->addChild(knives.returngeode());


osg::ref_ptr < osg::MatrixTransform >staticzaxis = new osg::MatrixTransform;
rpGroup->addChild(staticzaxis.get());
osg::ref_ptr<osg::Node> staticznode = osgDB::readNodeFile("Î²×ù1.stl");
osg::ref_ptr<osg::Node> staticznode1 = osgDB::readNodeFile("¶¥¼â.stl");
osg::ref_ptr<osg::MatrixTransform> tail = new osg::MatrixTransform;
osg::ref_ptr<osg::MatrixTransform> tail1 = new osg::MatrixTransform;
tail->setDataVariance(osg::Object::DYNAMIC);
tail->setUpdateCallback(tail_foundation_back);
tail->addChild(staticznode.get());
tail->addChild(tail1);

tail1->setDataVariance(osg::Object::DYNAMIC);
tail1->setUpdateCallback(tailCallback);
tail1->addChild(staticznode1.get());


staticzaxis->addChild(tail.get());




staticzaxis->addChild(cy.returngeode());



osg::ref_ptr < osg::Group >caxis = new osg::Group;
rpGroup->addChild(caxis.get());
osg::ref_ptr<osg::Node> cnode = osgDB::readNodeFile("CÖá.stl");
caxis->addChild(cnode.get());


osg::ref_ptr < osg::Group >spindle = new osg::Group;
caxis->addChild(spindle.get());

osg::ref_ptr < osg::Group >attach = new osg::Group;
spindle->addChild(attach.get());

osg::ref_ptr < osg::Group >fixture = new osg::Group;
attach->addChild(fixture.get());
osg::ref_ptr<osg::Node> mainclaw = osgDB::readNodeFile("¿¨ÅÌ.stl");
osg::ref_ptr<osg::Node> claw1 = osgDB::readNodeFile("×¦1.stl");
osg::ref_ptr<osg::Node> claw2 = osgDB::readNodeFile("×¦2.stl");
osg::ref_ptr<osg::Node> claw3 = osgDB::readNodeFile("×¦3.stl");
fixture->addChild(mainclaw.get());
//fixture->addChild(claw1.get());
//fixture->addChild(claw2.get());
//fixture->addChild(claw3.get());


osg::ref_ptr<osg::MatrixTransform> nclaw1= new osg::MatrixTransform;
osg::ref_ptr<osg::MatrixTransform>  nclaw2 = new osg::MatrixTransform;
osg::ref_ptr<osg::MatrixTransform> nclaw3 = new osg::MatrixTransform;
nclaw1->setDataVariance(osg::Object::DYNAMIC);

nclaw1->setUpdateCallback(claw1Callback);

nclaw1->addChild(claw1.get());
fixture->addChild(nclaw1.get());
nclaw2->setDataVariance(osg::Object::DYNAMIC);
nclaw2->setUpdateCallback(new claw2Call);
nclaw2->addChild(claw2.get());
fixture->addChild(nclaw2.get());
nclaw3->setDataVariance(osg::Object::DYNAMIC);
nclaw3->setUpdateCallback(new claw3Call);
nclaw3->addChild(claw3.get());
fixture->addChild(nclaw3.get());

osg::ref_ptr<osg::MatrixTransform> normalize = new osg::MatrixTransform;
normalize->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0), osg::Vec3(0, 1, 0))* osg::Matrix::rotate(osg::DegreesToRadians(90.0), osg::Vec3(1, 0, 0)));

normalize->addChild(rpGroup);

rpViewer->setSceneData(normalize.get());
rpViewer->addEventHandler(new events);
rpViewer->realize();
rpViewer->run();
}
