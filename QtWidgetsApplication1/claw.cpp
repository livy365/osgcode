#include <osg/ref_ptr>
#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/Group>
#include <osg/MatrixTransform> 
#include <osgGA/CameraManipulator>
#include <osgViewer/Viewer>
#include <iostream>
#include <math.h>       /* cos */
#define PI 3.14159265358979323846264338 
#include"stock.h"
#include"claw.h"
extern stocks cy;
float dis = 0;
void claw1Call::operator()(osg::Node* node, osg::NodeVisitor* nv)
{


	osg::MatrixTransform* mtshift =
		dynamic_cast<osg::MatrixTransform*>(node);
	osg::Matrix mT;
	mT.makeTranslate(osg::Vec3f(0, (-dis), 0));
	mtshift->setMatrix(mT);

	
	if (starttag)
	{ 
	  osg::Vec3 m_vecnewPosition = osg::Vec3f(260, 240, -1150) + osg::Vec3f(0, (-dis), 0);
	  osgUtil::LineSegmentIntersector::Intersections intersections;
	  osg::ref_ptr<osgUtil::LineSegmentIntersector> ls = new osgUtil::LineSegmentIntersector(m_vecnewPosition, osg::Vec3f(260, 240, -1150));
	  osg::ref_ptr<osgUtil::IntersectionVisitor> iv = new osgUtil::IntersectionVisitor(ls);
	  cy.returngeode()->accept(*iv.get());

	  if (!ls->containsIntersections())
	  {

		  //std::cout << "no";
		  dis=dis+10;

  	  }
	  else if (ls->containsIntersections())
	  {
		  starttag = false;
		  isend = true;
	  }

	}
	traverse(node, nv);

}

void claw1Call::start()
{
	starttag = true;

}
bool claw1Call::return_isend()
{
	return isend;

}


void claw2Call::operator()(osg::Node* node, osg::NodeVisitor* nv)
{


	osg::MatrixTransform* mtshift =
		dynamic_cast<osg::MatrixTransform*>(node);
	osg::Matrix mT;
	mT.makeTranslate(osg::Vec3f(dis * sin(60 * PI / 180.0), dis * sin(30 * PI / 180.0), 0));
	mtshift->setMatrix(mT);


	traverse(node, nv);

}
void claw3Call::operator()(osg::Node* node, osg::NodeVisitor* nv)
{


	osg::MatrixTransform* mtshift =
		dynamic_cast<osg::MatrixTransform*>(node);
	osg::Matrix mT;
	mT.makeTranslate(osg::Vec3f(-dis * sin(60 * PI / 180.0), dis * sin(30 * PI / 180.0), 0));
	mtshift->setMatrix(mT);


	traverse(node, nv);

}