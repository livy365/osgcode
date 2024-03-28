#include <osg/ref_ptr>
#include <osg/Geode> 
#include <osg/Geometry>
#include <osg/Group>
#include <osg/MatrixTransform> 
#include <osgDB/readFile> 

#include"shiftandrotate.h"
#include"stock.h"
#include"knife.h"
#include<stdlib.h>

int readtext();

extern stocks cy;
extern knife knives;
int rot;
extern xshift* X;
float R[501];
float colors[501][4];
int i = -1, i2 = -1, i3 = -1;
//int rot;
zshift::zshift() {
	readtext();
	originallength = 155;
	shiftlength = originallength * vec;
    length = shiftlength;
	setposition();
	//setlength(originallength+strVec[i2]);
	for (int k = 0; k <= 500; k++)
	{
		R[k]=25;
		colors[k][0]= 1.0;
		colors[k][1] = 0.0;
		colors[k][2] =0.0;
		colors[k][3] = 1.0;
		//std::cout <<"k=" << k << " " << colors[k].x() << " " << colors[k].y() << " " << colors[k].z() << " " << std::endl;
	}

}
void zshift::operator()(osg::Node* node, osg::NodeVisitor* nv)
{

	
		osg::MatrixTransform* mtshift =
			dynamic_cast<osg::MatrixTransform*>(node);
		osg::Matrix mT;
		osglength = osg::Vec3(0, 0, shiftlength / vec);
		mT.makeTranslate(osglength);
		mtshift->setMatrix(mT);
			//std::cout << shiftlength / vec << std::endl;
	   
	  
      // cy.stockgeode((shiftlength / vec) - 800);
	if (moving && i2 <= i && i2 <= i3)
	{
		
		int k = shiftlength +vec*(-800 + 1150);
		
 
        for(int m=0;m<=abs(plus);m++)
		{
		  int n = (k + m) / vec;
		  if (n <= (500))
		  {
			
		    if (R[n] > X->returnR() / 2)
		    {
			  R[n] = X->returnR() / 2;
			  colors[n][0] = knives.returncolor(rot).x();
			  colors[n][1] = knives.returncolor(rot).y();
			  colors[n][2] = knives.returncolor(rot).z();
			  colors[n][3] = knives.returncolor(rot).w();

		    }
			
		  }
		
        }
        cy.stockgeode();
		//std::cout << shiftlength << " " << length << std::endl;
		//std::cout << i2 << " " << strVec.size() << std::endl;

		if (shiftlength == length && i2 == strVec.size())
		{
			busy = false;
			moving = false;
			std::cout << "zend";
		}
		else if (shiftlength != length)
		{
			busy = true;
			shiftlength = shiftlength + plus;
			
		}
		else if (shiftlength == length && i2 < strVec.size())
		{
			busy = false;
			setlength(150 + strVec[i2]);
			
		}
		else if (shiftlength == length && i2 == -2)
		{
			busy = false;
		}
	
	}

	traverse(node, nv);

}
void zshift::setlength(double a)
{

	



	length = vec * a;
	moving = true;
	//busy = true;
	plus = (length - shiftlength) / (vec);

	if (!pause) { i2++; }


	//tag = (length / vec) - 800 + 1150;

}


void zshift::setposition()
{
	using namespace std;
	ifstream text;
	text.open("readz.txt", ios::in);


	while (!text.eof())
	{
		string inbuf;
		//getline(text, inbuf, 'E');
		getline(text, inbuf, '\n');
		double num = std::stod(inbuf);
		
		strVec.push_back(num);
	}



}

bool zshift::returnmoving()
{
	return moving;
}
bool zshift::returnbusy()
{
	return busy;
}
void zshift::start()
{
	pause = false;
	setlength(150 + strVec[i2]);

}
void zshift::onestepstart()
{
	pause = true;
	setlength(150 + strVec[i2]);

}
void zshift::recover() {
	moving = false; busy = false;
	shiftlength = originallength * vec;
	
	//setlength(originallength+strVec[i2]);
	for (int k = 0; k <= 500; k++)
	{
		R[k] = 25;
		colors[k][0] = 1.0;
		colors[k][1] = 0.0;
		colors[k][2] = 0.0;
		colors[k][3] = 1.0;


	}
	cy.stockgeode();
}

void zshift::mannul()
{
	i2 = -2;
	i = -2;
	i3 = -2;
    plus = -vec;
	moving = true;
	length =length-vec;
	//std::cout << shiftlength<<std::endl;
}
void zshift::mannulr()
{
	i2 = -2;
	i = -2;
	i3 = -2;
	plus = vec;
	moving = true;
	length = length +vec;
	//std::cout << shiftlength<<std::endl;
}
xshift::xshift() {
	originallength = 135;
	shiftlength = originallength * vec;
	length = shiftlength;
	setposition();
	R = 320 - 2 * length / vec;
	//setlength(originallength + strVec[i]);


}
void xshift::operator()(osg::Node* node, osg::NodeVisitor* nv)
{



		osg::MatrixTransform* mtshift =
			dynamic_cast<osg::MatrixTransform*>(node);
		osg::Matrix mT;
		osglength = osg::Vec3(shiftlength / vec, 0, 0);
		mT.makeTranslate(osglength);
		mtshift->setMatrix(mT);
		//   std::cout << shiftlength/vec<< std::endl;
		
	if (moving && i <= i2 && i <= i3)
	{
		if (shiftlength == length && i == strVec.size())
		{
			/*if (!pause)
			{
				R = strVec[i - 1];
			}*/
			R = 320 - 2 * length / vec;
			busy = false;
			moving = false;
			std::cout << "xend";
		}
		else if (shiftlength != length)
		{
			/*if (!pause)
			{
				R = strVec[i - 1];
			}
			else
			{
				R = strVec[i];
			}*/
			R = 320 - 2 * length / vec;
			busy = true;
			shiftlength = shiftlength + plus;
		}
		else if (shiftlength == length && i < strVec.size())
		{
			/*if (!pause)
			{
              R = strVec[i-1];
			}
			else
			{
			  R = strVec[i];
			}*/
			R = 320 - 2 * length / vec;
			busy = false;
			setlength(135 - 0.5 * (strVec[i] - 50));
		}
		else if (shiftlength == length && i == -2)
		{
			busy = false;
		}

	}

	traverse(node, nv);

}
void xshift::setlength(double a)
{


	length = vec * a;
	moving = true;
	//busy = true;
	plus = (length - shiftlength) / (vec);
    if (!pause) { i++; }

}


void xshift::setposition()
{
	using namespace std;
	ifstream text;
	text.open("readx.txt", ios::in);


	while (!text.eof())
	{
		string inbuf;
		getline(text, inbuf, '\n');
		//getline(text, inbuf, 'E');
		double num = std::stod(inbuf);

		strVec.push_back(num);
	}



}

bool xshift::returnmoving()
{
	return moving;
}
bool xshift::returnbusy()
{
	return busy;
}
float xshift::returnR()
{
	return R;
}
void xshift::start()
{
	pause = false;
	setlength(135 - 0.5 * (strVec[i] - 50));

}
void xshift::onestepstart()
{
	pause = true;
	setlength(135 - 0.5 * (strVec[i] - 50));

}

int xshift::returnsize()
{
	return strVec.size();
}
void xshift::recover() {
	moving = false; busy = false;
	shiftlength = originallength * vec;

}

void xshift::mannul()
{
	i2 = -2;
	i = -2;
	i3 = -2;
	plus = vec;
	moving = true;
	length=length+vec;
	//std::cout << shiftlength << std::endl;
}
void xshift::mannulp()
{
	i2 = -2;
	i = -2;
	i3 = -2;
	plus = -vec;
	moving = true;
	length = length - vec;
	//std::cout << shiftlength << std::endl;
}
yrshift::yrshift() {


	setposition();
	//setlength(strVec[i3]);


}

void yrshift::operator()(osg::Node* node, osg::NodeVisitor* nv)
{

	
		osg::MatrixTransform* mtshift =
			dynamic_cast<osg::MatrixTransform*>(node);
		osg::Matrix mT, mR, mt;
		mT.makeTranslate(osg::Vec3(75, -410, 693.3259));
		mR.makeRotate(osg::DegreesToRadians(currentrotate / vec), osg::Vec3(0, 1, 0));
		mt.makeTranslate(osg::Vec3(-75, 410, -693.3259));
		mtshift->setMatrix(mT * mR * mt);

    if (moving && i3 <= i2 && i3 <= i)
	{
		if (currentrotate == rotate && i3 == strVec.size())
		{
			/*if (!pause)
			{
				rot = strVec[i3-1];
			}*/
			rot = rotate / (-90 * vec);
			busy = false;
			moving = false;
			std::cout << "end";
		}
		else if (currentrotate != rotate)
		{
			/*if (!pause)
			{
				rot = strVec[i3 - 1];
			}
			else
			{
				rot = strVec[i3];
			}*/
			rot = rotate / (-90 * vec);
			busy = true;
			currentrotate = currentrotate + plus;
			
		}
		else if (currentrotate == rotate && i3 < strVec.size())
		{
			/*if (!pause)
			{
				rot = strVec[i3-1];
			}
			else
			{
				rot = strVec[i3];
			}*/
			rot = rotate / (-90 * vec);
			busy = false;
			setlength(strVec[i3]);
		}
		else if (currentrotate == rotate && i3 == -2)
		{
			busy = false;
		}



	}

	traverse(node, nv);

}

void yrshift::setlength(double a)
{
	

	rotate =-90* vec * a;
	moving = true;
	//busy = true;
	plus = (rotate - currentrotate) / (vec);
    if (!pause) { i3++; }

}


void yrshift::setposition()
{
	using namespace std;
	ifstream text;
	text.open("readr.txt", ios::in);


	while (!text.eof())
	{
		string inbuf;
		getline(text, inbuf, '\n');
		double num = std::stod(inbuf);
	
		strVec.push_back(num);
	}



}
void yrshift::start()
{
	pause = false;
	setlength(strVec[i3]);

}
void yrshift::onestepstart()
{
	pause = true;
	setlength(strVec[i3]);
}
void yrshift::recover() {
	moving = false; busy = false;
	currentrotate = 0;

}
bool yrshift::returnbusy()
{
	return busy;
}
void  yrshift::mannul()
{
	
	i2 = -2;
	i = -2;
	i3 = -2;
     moving = true;
	 c = (c + 1) % 4;
	rotate = -90 * vec * c;
	plus = (rotate - currentrotate) / (vec);
}
