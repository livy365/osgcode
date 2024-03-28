#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osg/ref_ptr>
#include"knife.h"

knife::knife()
{

	color[0] = osg::Vec4(0, 1, 1, 0.5);
	color[1] = osg::Vec4(1, 0, 0, 0.5);
	color[2] = osg::Vec4(0, 1, 0, 0.5);
	color[3] = osg::Vec4(0, 0, 0, 0.5);
}
osg::ref_ptr<osg::Node>knife::returngeode() {
	osg::ref_ptr<osg::Box> box = new osg::Box;
	box->setCenter(osg::Vec3d(30, 215, -790));
	box->setHalfLengths(osg::Vec3(70.0, 25.0, 10.0));
	osg::ref_ptr<osg::ShapeDrawable> sd1 = new osg::ShapeDrawable(box.get());
	sd1->setColor(color[0]);


	box->setCenter(osg::Vec3d(-171.6741, 215, -798.3259));
	box->setHalfLengths(osg::Vec3(10.0, 25.0, 70.0));
	osg::ref_ptr<osg::ShapeDrawable> sd2 = new osg::ShapeDrawable(box.get());
	sd2->setColor(color[1]);


	box->setCenter(osg::Vec3d(-180, 215, -596.6518));
	box->setHalfLengths(osg::Vec3(70.0, 25.0, 10.0));
	osg::ref_ptr<osg::ShapeDrawable> sd3 = new osg::ShapeDrawable(box.get());
	sd3->setColor(color[2]);


	box->setCenter(osg::Vec3d(21.6741, 215, -588.3259));
	box->setHalfLengths(osg::Vec3(10.0, 25.0, 70.0));
	osg::ref_ptr<osg::ShapeDrawable> sd4 = new osg::ShapeDrawable(box.get());
	sd4->setColor(color[3]);







	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::StateSet>state = geode->getOrCreateStateSet();
	state->setMode(GL_BLEND, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

	geode->addDrawable(sd1.get());
	geode->addDrawable(sd2.get());
	geode->addDrawable(sd3.get());
	geode->addDrawable(sd4.get());
	return geode;
}

osg::Vec4 knife::returncolor(int id)
{
	return color[id];
}
