#include <osg/ref_ptr> 
#include<math.h>
#include <osgText/Text>
#include <osg/MatrixTransform>
#include <osg/LineWidth>
#include <osg/BlendColor>
#include <osg/BlendFunc>
#define PI       3.14159265358979323846   

osg::ref_ptr<osg::Node> circle(int radius, double degree, osg::Vec3 center)
{
	// 创建一个用于保存几何信息的对象
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> rpNormal = new osg::Vec3Array;
	// 创建顶点的数组
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());
	int count = 0;
	int z = 0;
	for (double k = 0; k <= 36000; k++) {
		double hk = (PI / 180) * (k / 100);
		float x = radius * cos(hk);
		float y = radius * sin(hk);
		v->push_back(osg::Vec3(x, y, z));
		rpNormal->push_back(osg::Vec3(x, y, z));//添加法线

		count++;
	}

	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 1.f, 1.f, 1.f));

	// 为法线创建一个数组
	geom->setNormalArray(rpNormal);
	geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::DrawElementsUInt> rpFace = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP);
	for (int i = 0; i < 36000; i++) {
		rpFace->push_back(i);
	}

	geom->addPrimitiveSet(rpFace);

	// 向 Geode 类添加几何体（Drawable）并返回 Geode 
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geom.get());
	osg::StateSet* state = geode->getOrCreateStateSet();
	state->setMode(GL_RESCALE_NORMAL, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	state->setMode(GL_LIGHTING, osg::StateAttribute::OFF |
		osg::StateAttribute::PROTECTED);
	
	osg::ref_ptr<osg::MatrixTransform> rpMTTR = new osg::MatrixTransform;
	rpMTTR->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(degree), center));
	rpMTTR->addChild(geode.get());
	osg::StateSet* rpstate = rpMTTR->getOrCreateStateSet();
	osg::LineWidth* lw = new osg::LineWidth(1.f);
	rpstate->setAttribute(lw);

	osg::ref_ptr<osg::BlendColor> rpBlendColor = new osg::BlendColor();//混合颜色
	osg::ref_ptr<osg::BlendFunc> rpBlendFunc = new osg::BlendFunc();//混合功能
	rpstate->setAttributeAndModes(rpBlendFunc.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//添加混合功能属性
	rpstate->setAttributeAndModes(rpBlendColor.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//添加混合颜色属性
	rpBlendFunc->setSource(osg::BlendFunc::CONSTANT_COLOR);//一减常量颜色
	rpBlendFunc->setDestination(osg::BlendFunc::CONSTANT_ALPHA);//一减常量透明度
	osg::Vec4 vecColorNew = osg::Vec4(1.0, 1.0, 1.0, 1.0);
	
	rpBlendColor->setConstantColor(vecColorNew);//设置颜色



	return rpMTTR.get();


}
osg::ref_ptr<osg::Node> tail(int radius, double degree, osg::Vec3 center)
{
	// 创建一个用于保存几何信息的对象
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> rpNormal = new osg::Vec3Array;
	// 创建顶点的数组
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());
	int count = 0;
	int z = 0;

	if (center == osg::Vec3(1, 0, 0))
	{
		for (double k = -2000; k <= 0; k++) {
			double hk = (PI / 180) * (k / 100);
			float x = radius * cos(hk);
			float y = radius * sin(hk);
			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线

			count++;
		}
	}
	if (center == osg::Vec3(0, 1, 0))
	{
		for (double k = 7000; k <= 9000; k++) {
			double hk = (PI / 180) * (k / 100);
			float x = radius * cos(hk);
			float y = radius * sin(hk);
			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线

			count++;
		}
	}


	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 0.f, 0.f, 1.f));

	// 为法线创建一个数组
	geom->setNormalArray(rpNormal);
	geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::DrawElementsUInt> rpFace = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP);
	for (int i = 0; i < 2000; i++) {
		rpFace->push_back(i);
	}

	geom->addPrimitiveSet(rpFace);

	// 向 Geode 类添加几何体（Drawable）并返回 Geode 
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geom.get());
	osg::StateSet* state = geode->getOrCreateStateSet();
	state->setMode(GL_RESCALE_NORMAL, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	state->setMode(GL_LIGHTING, osg::StateAttribute::OFF |
		osg::StateAttribute::PROTECTED);
	osg::LineWidth* lw = new osg::LineWidth(5.f);
	state->setAttribute(lw);

	osg::ref_ptr<osg::MatrixTransform> rpMTTR = new osg::MatrixTransform;
	rpMTTR->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(degree), center));
	rpMTTR->addChild(geode.get());
	return rpMTTR.get();


}