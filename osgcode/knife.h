#pragma once
//#include <osg/ref_ptr>
//#include <osg/Geode> 
//#include <osg/Geometry>
//#include <osg/Group>
//#include <osg/MatrixTransform> 
class knife
{
public:
	knife();
	osg::ref_ptr<osg::Node>returngeode();
	osg::Vec4 returncolor(int id);



protected:
	int id[4],type[4];
	osg::Vec4 color[4];
	double thickness[4] , length[4], currentrotate[4];
	
}; 