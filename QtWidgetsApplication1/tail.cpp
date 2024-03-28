#include <osg/ref_ptr>
#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/Group>
#include <osg/MatrixTransform> 
#include <osgGA/CameraManipulator>
#include <osgViewer/Viewer>
#include<iostream>
#include"tail.h"
#include"stock.h"
extern stocks cy;
void tailCall::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	
	
	osg::MatrixTransform* mtshift =
		dynamic_cast<osg::MatrixTransform*>(node);
	osg::Matrix mT;
	mT.makeTranslate(osg::Vec3f(0,0,plus));
	mtshift->setMatrix(mT);

	if(starttag)
	{ 
	    for (int k=0;k<=200;k++)
	    {
	         osg::Vec3 m_vecnewPosition = osg::Vec3f(260, 240, -377.5) + osg::Vec3f(0, 0, plus);
	        osgUtil::LineSegmentIntersector::Intersections intersections;
	        osg::ref_ptr<osgUtil::LineSegmentIntersector> ls = new osgUtil::LineSegmentIntersector(m_vecnewPosition, osg::Vec3f(260, 240, -377.5));
	         osg::ref_ptr<osgUtil::IntersectionVisitor> iv = new osgUtil::IntersectionVisitor(ls);
	        cy.returngeode()->accept(*iv.get());

	    if ((!ls->containsIntersections()))
	    {
	        plus=plus-0.5;
			
	    }
		else if(ls->containsIntersections())
		{
			starttag = false;
			isend = true;
		
		}
        }
    }

	traverse(node, nv);

}
void tailCall::start()
{
	starttag = true;

}
bool tailCall::return_isend()
{
	return isend;

}

void tail_foundation_Call::operator()(osg::Node* node, osg::NodeVisitor* nv)
{


	osg::MatrixTransform* mtshift =
		dynamic_cast<osg::MatrixTransform*>(node);
	osg::Matrix mT;
	mT.makeTranslate(osg::Vec3f(0, 0, plus));
	mtshift->setMatrix(mT);

	if (starttag&&plus>-200)
	{
			
				plus = plus -10;

		
	}

	traverse(node, nv);

}
void tail_foundation_Call::start()
{
	starttag = true;

}
