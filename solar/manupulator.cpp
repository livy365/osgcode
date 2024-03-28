#include "manupulator.h"
#include<iostream>
extern osg::ref_ptr<osg::Node> sun;

CDriveManupulator::CDriveManupulator()
	:osgGA::CameraManipulator()
	, m_rpMtBall(NULL)
	, m_vecBallPosition(0.0, -20.0, 0.0)
	//设置相机的矩阵
	, m_vecPosition(0.0, -400.0, 0.0)
	, m_vecRotation(osg::PI_2, 0.0f, 0.0f)
	, m_fMoveSpeed(6.0)
	, m_fAnglg(2.5)
{
	m_rpMtBall = new osg::MatrixTransform();
	osg::ref_ptr<osg::Geode> rpGnode = new osg::Geode;
	rpGnode->addDrawable(new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0.0, 0.0, 0.0), 0.5)));
	m_rpMtBall->setMatrix(osg::Matrixd::translate(m_vecBallPosition));
	m_rpMtBall->addChild(rpGnode.get());

}

void CDriveManupulator::ChangePosition(osg::Vec3 vec3Delta)
{

	osg::Vec3 m_vecnewPosition= m_vecPosition + vec3Delta;
	osgUtil::LineSegmentIntersector::Intersections intersections;
	osg::ref_ptr<osgUtil::LineSegmentIntersector> ls = new osgUtil::LineSegmentIntersector(m_vecnewPosition, m_vecPosition);
	osg::ref_ptr<osgUtil::IntersectionVisitor> iv = new osgUtil::IntersectionVisitor(ls);
	sun->accept(*iv.get());

	if (!ls->containsIntersections())
	{
		
		std::cout << "no";
		m_vecPosition += vec3Delta;

	}
	else
	{
		std::cout << "yes";
	}

}

void CDriveManupulator::ChangePositionCar(osg::Vec3 vec3Delta)
{
	osg::Vec3 temp;
	temp = osg::Vec3(m_vecPosition.x(), m_vecPosition.y(), 0.0);
	m_rpMtBall->setMatrix(osg::Matrixd::translate(temp + vec3Delta));
	m_vecBallPosition = temp + vec3Delta;
	
}

void CDriveManupulator::ChangePositionCarLeftRight(osg::Vec3 vec3Delta)
{
	m_vecBallPosition += vec3Delta;
	m_rpMtBall->setMatrix(osg::Matrixd::translate(m_vecBallPosition));
}

bool CDriveManupulator::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us)
{
	switch (ea.getEventType())
	{
	  case osgGA::GUIEventAdapter::KEYDOWN:
	  {
		if (ea.getKey() == 'w' || ea.getKey() == 'W')
		{
				ChangePosition(osg::Vec3(m_fMoveSpeed * cosf(osg::PI_2 + m_vecRotation[2]), m_fMoveSpeed * sinf(osg::PI_2 + m_vecRotation[2]), 0));
				ChangePositionCar(osg::Vec3(m_fMoveSpeed  * 6 * cosf(osg::PI_2 + m_vecRotation[2]), m_fMoveSpeed  * 6 * sinf(osg::PI_2 + m_vecRotation[2]), 0));
		}

	

		if (ea.getKey() == 's' || ea.getKey() == 'S')
		{
		  ChangePosition(osg::Vec3(-m_fMoveSpeed * cosf(osg::PI_2 + m_vecRotation[2]), -m_fMoveSpeed * sinf(osg::PI_2 + m_vecRotation[2]), 0));
		  ChangePositionCar(osg::Vec3(m_fMoveSpeed * 6 * cosf(osg::PI_2 + m_vecRotation[2]), m_fMoveSpeed * 6 * sinf(osg::PI_2 + m_vecRotation[2]), 0));
		}
	    if (ea.getKey() == 'a' || ea.getKey() == 'A')
		{
		  ChangePosition(osg::Vec3(-m_fMoveSpeed * sinf(osg::PI_2 + m_vecRotation[2]), m_fMoveSpeed * cosf(osg::PI_2 + m_vecRotation[2]), 0));
		  ChangePositionCarLeftRight(osg::Vec3(-m_fMoveSpeed * sinf(osg::PI_2 + m_vecRotation[2]), m_fMoveSpeed * cosf(osg::PI_2 + m_vecRotation[2]), 0));
		}
		if (ea.getKey() == 'd' || ea.getKey() == 'D')
		{
		  ChangePosition(osg::Vec3(m_fMoveSpeed * sinf(osg::PI_2 + m_vecRotation[2]), -m_fMoveSpeed * cosf(osg::PI_2 + m_vecRotation[2]), 0));
		  ChangePositionCarLeftRight(osg::Vec3(m_fMoveSpeed * sinf(osg::PI_2 + m_vecRotation[2]), -m_fMoveSpeed * cosf(osg::PI_2 + m_vecRotation[2]), 0));
		}
		if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Right) //右旋转
		{
		  float temp = m_vecRotation._v[2];
		  m_vecRotation._v[2] -= osg::DegreesToRadians(m_fAnglg);
		  ChangePosition(osg::Vec3(12 * sin(m_vecRotation._v[2]) - 12 * sin(temp), 12 * (1 - cos(m_vecRotation._v[2])) - 12 * (1 - cos(temp)), 0));
		}
		if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Left) //左旋转
		{
		  float temp = m_vecRotation._v[2];
		  m_vecRotation._v[2] += osg::DegreesToRadians(m_fAnglg);
		  ChangePosition(osg::Vec3(12 * sin(m_vecRotation._v[2]) - 12 * sin(temp), 12 * (1 - cos(m_vecRotation._v[2])) - 12 * (1 - cos(temp)), 0));
		}
		if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Up) //上旋转
		{
			float temp = m_vecRotation._v[0];
			m_vecRotation._v[0] += osg::DegreesToRadians(m_fAnglg);
		}
		if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Down) //下旋转
		{
			float temp = m_vecRotation._v[0];
			m_vecRotation._v[0] -= osg::DegreesToRadians(m_fAnglg);
		}
		break;
	  }

	  default:
	  break;
	}

	return false;
}
