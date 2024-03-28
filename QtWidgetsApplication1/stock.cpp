#include <osg/ref_ptr>
#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/ShapeDrawable>
#include "turn_off.h"
#include "shiftandrotate.h"
#include "stock.h"

#define PI 3.14159265358979323846264338 
extern float R[501];
extern xshift* X;
extern float colors[501][4];

osg::ref_ptr<osg::Node> plant()
{
	// 创建一个用于保存几何信息的对象
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

	// 创建顶点的数组
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());

	osg::ref_ptr<osg::Vec2Array> tc2 = new osg::Vec2Array;
	//geom->setTexCoordArray(0, tc2.get());
	osg::ref_ptr<osg::Vec3Array> rpNormal = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	int count = 0;

	for (int i = -1150; i <= -650; i = i + 1)
	{


		//double hz = (PI / 180) * (i);
		float z = i;
		float r = R[i+1150];
		if (r < 0) r = 0;
		osg::Vec4 Color= osg::Vec4(colors[i + 1150][0], colors[i + 1150][1], colors[i + 1150][2], colors[i + 1150][3]);
		//std::cout << "i + 1150=" << i + 1150 << " " << colors[i + 1150][0] << " " << colors[i + 1150][1] << " " << colors[i + 1150][2] << " " << std::endl;
	
		for (int k = 0; k <= 360; k = k + 10)
		{
			double hk = (PI / 180) * (k);
			float x = r * cos(hk) + 260;
			float y = r * sin(hk) + 240;
			//c->push_back(osg::Vec4(1.0f, 0.f, 0.f, 0.5f));
			c->push_back(Color);
			//std::cout << Color << " "  ;
			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线
			//tc2->push_back(osg::Vec2(double(k) / 360.0, double(i + 90) / 180));
			count++;

		}

	}
	count++;
	v->push_back(osg::Vec3(260, 240, -650));
	rpNormal->push_back(osg::Vec3(260, 240, -650));
	c->push_back(osg::Vec4(colors[500][0], colors[500][1], colors[500][2], colors[500][3]));
	/*for (int i = a; i <= -650; i = i + 1)
	{

		//std::cout << i << "h" << std::endl;
		//double hz = (PI / 180) * (i);
		float z = i;
		float r = R[i + 1150];;//X->returnR()/2;//10;
		//std::cout << "R[i + 1150]  " << R[i + 1150] << "X->returnR() / 2  " << X->returnR() / 2 << std::endl;

		for (int k = 0; k <= 360; k = k + 10)
		{
			double hk = (PI / 180) * (k);
			float x = r * cos(hk) + 260;
			float y = r * sin(hk) + 240;
			//c->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 0.5f));
			c->push_back(osg::Vec4(1.0f, 0.f, 0.f, 0.5f));
			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线
			//tc2->push_back(osg::Vec2(double(k) / 360.0, double(i + 90) / 180));
			count++;

		}

	}*/

	// 创建四种颜色的数组

	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);


	// 为法线创建一个数组
	geom->setNormalArray(rpNormal);
	geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);



	// 由保存的数据绘制四个顶点的多边形

	osg::ref_ptr<osg::DrawElementsUInt> rpFace = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_STRIP);
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j <= 18 * 2; j++) {
			rpFace->push_back(i * (18 * 2 + 1) + j);
			rpFace->push_back((i + 1) * (18 * 2 + 1) + j);
		}
	}
	for (int j = 0; j <= 18 * 2; j++) {
           rpFace->push_back((500) * (18 * 2 + 1) + j);
		   rpFace->push_back((500) * (18 * 2 + 1) + 37);
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
	
	state->setMode(GL_BLEND, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	return geode.get();
}

stocks::stocks()
{
	i = 0;
	stockswitch = new osg::Switch;
	cy1 = new osg::Cylinder;
	osg::ref_ptr<osg::Geode> stock = new osg::Geode;
	cy1->setCenter(osg::Vec3(260, 240, -900));
	cy1->setHeight(500);
	cy1->setRadius(25);
	osg::ref_ptr<osg::ShapeDrawable> sd6 = new osg::ShapeDrawable(cy1);
	sd6->setColor(osg::Vec4(1, 1, 0, 0.5));
	osg::ref_ptr<osg::StateSet>stockstate = stock->getOrCreateStateSet();
	stockstate->setMode(GL_BLEND, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	stockstate->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	stock->addDrawable(sd6.get());
	stockswitch->addChild(stock, true);
}



void stocks::stockgeode()
{
	osg::ref_ptr<osg::Node> stock = plant();
	turn_off invalidgeo(stockswitch);
	stockswitch->accept(invalidgeo);
	//std::cout << a << "h" << std::endl;
	stockswitch->addChild(stock, true);
}
osg::ref_ptr<osg::Switch>stocks::returngeode()
{
	return stockswitch;
}

void stocks::changeRadius(float r, float h, osg::Vec4 co)
{

	radius.push_back(r);
	height.push_back(h);
	center.push_back(osg::Vec3(260, 240, -1150 + 0.5 * h));
	color.push_back(co);

}