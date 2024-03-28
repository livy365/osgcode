#pragma once
//#include <osgDB/readFile> 
//#include <osgViewer/Viewer>


//osg::ref_ptr<osg::Node> plant(float a);
/*
extern xshift* X;
osg::ref_ptr<osg::Node> plant(float a)
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


	for (int i = -1150; i <= a; i = i + 1)
	{


		//double hz = (PI / 180) * (i);
		float z = i;
		float r = 50;


		for (int k = 0; k <= 360; k = k + 10)
		{
			double hk = (PI / 180) * (k);
			float x = r * cos(hk)+260;
			float y = r * sin(hk)+240;
			c->push_back(osg::Vec4(1.0f, 0.f, 0.f, 1.f));
			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线
			//tc2->push_back(osg::Vec2(double(k) / 360.0, double(i + 90) / 180));
			count++;

		}

	}
	for (int i = a+1; i <= -650; i = i + 1)
	{

		std::cout << i<<"h"<<std::endl;
		//double hz = (PI / 180) * (i);
		float z = i;
		float r = X->returnR();//10;
		

		for (int k = 0; k <= 360; k = k + 10)
		{
			double hk = (PI / 180) * (k);
			float x = r * cos(hk)+260;
			float y = r * sin(hk)+240;
			c->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 1.f));
			v->push_back(osg::Vec3(x, y, z));
			rpNormal->push_back(osg::Vec3(x, y, z));//添加法线
			//tc2->push_back(osg::Vec2(double(k) / 360.0, double(i + 90) / 180));
			count++;

		}

	}

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
	geom->addPrimitiveSet(rpFace);



	// 向 Geode 类添加几何体（Drawable）并返回 Geode 
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geom.get());
	osg::StateSet* state = geode->getOrCreateStateSet();
	state->setMode(GL_RESCALE_NORMAL, osg::StateAttribute::ON |
		osg::StateAttribute::PROTECTED);
	state->setMode(GL_LIGHTING, osg::StateAttribute::OFF |
		osg::StateAttribute::PROTECTED);
	return geode.get();
}
*/

class stocks
{
public:
	stocks();
	

	void stockgeode();


	osg::ref_ptr<osg::Switch>returngeode();
	

	void changeRadius(float r, float h, osg::Vec4 co);



protected:
	int i;
	osg::ref_ptr<osg::Switch>stockswitch;
	osg::ref_ptr<osg::Cylinder> cy1;
	
	//osg::Vec3 center;
//	osg::Vec4 color;
	//float radius, height;
	//osg::ref_ptr<osg::Vec4Array> color;
	std::vector<double> radius, height;
	std::vector<osg::Vec3>center;
	std::vector<osg::Vec4>color;
};

