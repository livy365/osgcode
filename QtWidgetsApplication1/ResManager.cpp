#include "ResManager.h"

#include<osgGA/TrackballManipulator>
#include <osgDB/readFile> 
#include <osgViewer/Viewer>
#include <osg/ref_ptr>
#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/ShapeDrawable>





void ResManager::onInitialized()
{
	osg::ref_ptr<osg::Group> rpGroup = new osg::Group;
	osg::ref_ptr<osg::Node> rpCow = osgDB::readNodeFile("´²Éí.stl");
	rpGroup->addChild(rpCow.get());


	



	
	_widget->getOsgViewer()->setSceneData(rpGroup);//osgDB::readNodeFile("cow.osg"));

	_widget->getOsgViewer()->setCameraManipulator(new osgGA::TrackballManipulator);
	//_widget->getOsgViewer()->run();
}