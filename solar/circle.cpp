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
	// ����һ�����ڱ��漸����Ϣ�Ķ���
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> rpNormal = new osg::Vec3Array;
	// �������������
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());
	int count = 0;
	int z = 0;
	for (double k = 0; k <= 36000; k++) {
		double hk = (PI / 180) * (k / 100);
		float x = radius * cos(hk);
		float y = radius * sin(hk);
		v->push_back(osg::Vec3(x, y, z));
		rpNormal->push_back(osg::Vec3(x, y, z));//��ӷ���

		count++;
	}

	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 1.f, 1.f, 1.f));

	// Ϊ���ߴ���һ������
	geom->setNormalArray(rpNormal);
	geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::DrawElementsUInt> rpFace = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP);
	for (int i = 0; i < 36000; i++) {
		rpFace->push_back(i);
	}

	geom->addPrimitiveSet(rpFace);

	// �� Geode ����Ӽ����壨Drawable�������� Geode 
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

	osg::ref_ptr<osg::BlendColor> rpBlendColor = new osg::BlendColor();//�����ɫ
	osg::ref_ptr<osg::BlendFunc> rpBlendFunc = new osg::BlendFunc();//��Ϲ���
	rpstate->setAttributeAndModes(rpBlendFunc.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//��ӻ�Ϲ�������
	rpstate->setAttributeAndModes(rpBlendColor.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//��ӻ����ɫ����
	rpBlendFunc->setSource(osg::BlendFunc::CONSTANT_COLOR);//һ��������ɫ
	rpBlendFunc->setDestination(osg::BlendFunc::CONSTANT_ALPHA);//һ������͸����
	osg::Vec4 vecColorNew = osg::Vec4(1.0, 1.0, 1.0, 1.0);
	
	rpBlendColor->setConstantColor(vecColorNew);//������ɫ



	return rpMTTR.get();


}
osg::ref_ptr<osg::Node> tail(int radius, double degree, osg::Vec3 center)
{
	// ����һ�����ڱ��漸����Ϣ�Ķ���
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> rpNormal = new osg::Vec3Array;
	// �������������
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
			rpNormal->push_back(osg::Vec3(x, y, z));//��ӷ���

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
			rpNormal->push_back(osg::Vec3(x, y, z));//��ӷ���

			count++;
		}
	}


	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 0.f, 0.f, 1.f));

	// Ϊ���ߴ���һ������
	geom->setNormalArray(rpNormal);
	geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::DrawElementsUInt> rpFace = new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_STRIP);
	for (int i = 0; i < 2000; i++) {
		rpFace->push_back(i);
	}

	geom->addPrimitiveSet(rpFace);

	// �� Geode ����Ӽ����壨Drawable�������� Geode 
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