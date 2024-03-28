#include <osg/ref_ptr> 
//#include <osgDB/Registry> 
//#include <osgDB/WriteFile> 
#include <osgDB/readFile> 
#include <iostream> 
#include <osgViewer/Viewer>
#include<math.h>
#include <osg/StateAttribute>
#include <osgText/Text>
//#include <osg/Texture2D> 
//#include <osg/Image>
#include "osgFX/AnisotropicLighting"
#define PI       3.14159265358979323846   


osg::ref_ptr<osg::Node> plant(int radius)
{
	// 创建一个用于保存几何信息的对象
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	// 创建顶点的数组
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());

	osg::ref_ptr<osg::Vec2Array> tc2 = new osg::Vec2Array;
	geom->setTexCoordArray(0, tc2.get());
	osg::ref_ptr<osg::Vec3Array> rpNormal = new osg::Vec3Array;

	int count = 0;
	for (int i = -90; i <= 90; i = i + 10)
	{
		double hz = (PI / 180) * (i);
		float z = radius * sin(hz);
		float r = radius * cos(hz);


		for (int k = 0; k <= 360; k = k + 10)
		{
			double hk = (PI / 180) * (k);
			float x = r * cos(hk);
			float y = r * sin(hk);

			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线
			tc2->push_back(osg::Vec2(double(k) / 360.0, double(i + 90) / 180));
			count++;

		}

	}


	// 创建四种颜色的数组
	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 1.f, 1.f, 1.f));

	// 为法线创建一个数组
	geom->setNormalArray(rpNormal);
	geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);



	// 由保存的数据绘制四个顶点的多边形

	osg::ref_ptr<osg::DrawElementsUInt> rpFace = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_STRIP);
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j <= 18 * 2; j++) {
			rpFace->push_back(i * (18 * 2 + 1) + j);
			rpFace->push_back((i + 1) * (18 * 2 + 1) + j);
		}
	}
	geom->addPrimitiveSet(rpFace);



	// 向 Geode 类添加几何体（Drawable）并返回 Geode 
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geom.get());
	osg::StateSet* state = geode->getOrCreateStateSet();
	state->setMode(GL_RESCALE_NORMAL, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	state->setMode(GL_LIGHTING, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	return geode.get();
}
void settex(osg::Node* pnode, std::string picturefile)
{
	osg::ref_ptr<osg::Image> a = osgDB::readImageFile(picturefile);
	osg::StateSet* state = pnode->getOrCreateStateSet();

	state->setMode(GL_BLEND, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	osg::ref_ptr<osg::Texture2D> tex2 = new osg::Texture2D;

	tex2->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);//设置S方向的环绕模式
	tex2->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);//设置R方向的环绕模式
	tex2->setImage(a.get());
	state->setTextureAttributeAndModes(0, tex2, osg::StateAttribute::ON);


}
