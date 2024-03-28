#pragma once
//#include<math.h>
//#include"stock.h"
//extern stocks cy;

//int i = -1,i2=-1,i3=-1;

class zshift : public osg::NodeCallback
{
public:

	zshift();
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	
	void setlength(double a);
	

	void setposition();
	

	bool returnmoving();
	bool returnbusy();
	
	void start();
	
	void onestepstart();
	void recover();
	void mannul();
	void mannulr();
protected:
	int vec = 10;
	std::vector<double> strVec;
	bool moving = false,pause=false,busy = false;
	double shiftlength, plus, originallength;
	double length;
	osg::Vec3 osglength;
};

class xshift : public osg::NodeCallback
{
public:

	xshift();
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	
	void setlength(double a);
	


	void setposition();
	

	bool returnmoving();
	bool returnbusy();
	float returnR();
	
	void start();
	
	void onestepstart();
	

	int returnsize();
	void recover();
	void mannul();
	void mannulp();
protected:
	int vec=15;
	//int i=0;
	std::vector<double> strVec;
	bool moving = false,pause=false,busy = false;
	double shiftlength, plus , originallength,R;
	double length;
	osg::Vec3 osglength;
};

class yrshift : public osg::NodeCallback
{
public:
	yrshift();
	
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	
	
	void setlength(double a);

	bool returnbusy();

	void setposition();
	
	void start();
	
	void onestepstart();
	void recover();
	void mannul();
protected:
	int vec=10;
	bool moving= false,pause=false,busy = false;
	double rotate = 0, plus, currentrotate = 0; int c = 0;
	std::vector<double> strVec;
};