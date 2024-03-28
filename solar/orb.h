#pragma once

 
#include <osg/MatrixTransform> 

class Orbitalrevolutiontate : public osg::NodeCallback
{
public:
	Orbitalrevolutiontate(double _plus) :dAngle(0.), plus(_plus){}
	
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
	{
		osg::MatrixTransform* mtLeft =
			dynamic_cast<osg::MatrixTransform*>(node);
		osg::Matrix mR,mT;
		mT.makeTranslate(radius);
		mR.makeRotate(dAngle, center);
		mtLeft->setMatrix(mT*mR);

		// ��һ�λص�ʱ�ǶȾͻ�����
		dAngle =dAngle+plus;

			// ָ���������ݲ�����
			// ���� OSG ���Խ���ִ���������лص��Ľڵ㡣
			traverse(node, nv);
	
	}
	void setcenter(osg::Vec3 a)
	{
		center = a; 
	}
	void setradius(osg::Vec3 a)
	{
		radius = a;
	}
	
protected:
	double dAngle;
	double plus;
	osg::Vec3 radius, center;
};

class rotation : public osg::NodeCallback
{
public:
	rotation(double a) :dAngle(0.),plus(a) {}
	rotation() :dAngle(0.),plus(0.1) {}
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
	{
		osg::MatrixTransform* mtLeft =
			dynamic_cast<osg::MatrixTransform*>(node);
		osg::Matrix mR;
		mR.makeRotate(dAngle, osg::Vec3(0., 0., 1.));
		mtLeft->setMatrix(mR);

		// ��һ�λص�ʱ�ǶȾͻ�����
		dAngle = dAngle + plus;

		// ָ���������ݲ�����
		// ���� OSG ���Խ���ִ���������лص��Ľڵ㡣
		traverse(node, nv);

	}

protected:
	double dAngle,plus;
};