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

		// 下一次回调时角度就会增大。
		dAngle =dAngle+plus;

			// 指定继续传递参数，
			// 这样 OSG 可以接着执行其它带有回调的节点。
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

		// 下一次回调时角度就会增大。
		dAngle = dAngle + plus;

		// 指定继续传递参数，
		// 这样 OSG 可以接着执行其它带有回调的节点。
		traverse(node, nv);

	}

protected:
	double dAngle,plus;
};