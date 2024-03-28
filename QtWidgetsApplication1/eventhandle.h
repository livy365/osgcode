#pragma once
#include<osgViewer/ViewerEventHandlers>
#include"shiftandrotate.h"
#include"stock.h"
#include"claw.h"
#include"tail.h"
extern stocks cy;
extern zshift* Z;
extern xshift* X;
extern yrshift* YR;
extern int i, i2, i3;
extern claw1Call* claw1Callback;
extern tailCall* tailCallback;
extern tail_foundation_Call* tail_foundation_back;
class events :public osgGA::GUIEventHandler
{
public:
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		osg::ref_ptr<osgViewer::Viewer> rpViewer = dynamic_cast<osgViewer::Viewer*>(&aa);//事件适配器转换成viewer
		if (!rpViewer.valid())return false;

		switch (ea.getEventType())
		{
		case (osgGA::GUIEventAdapter::KEYDOWN):
		{
			if (ea.getKey() == 's')
			{

				claw1Callback->start();
				tailCallback->start();
				tail_foundation_back->start();
			}


			if (ea.getKey() == 'a')
			{
				
			  if(!(X->returnbusy())&& !(YR->returnbusy())&& !(Z->returnbusy())&& claw1Callback->return_isend()&& tailCallback->return_isend())
			  {
				if(i<=-1||i >=(X->returnsize()-1)){i=0; i3=0; i2=0;}
				Z->start();
				X->start();
				YR->start();
			  }
			  else {
				  std::cout << "busying";
			  }
			}
			if (ea.getKey() == 'b')
			{
			
				//std::cout << X->returnsize()<<" " <<i2 ;
				if (!(X->returnbusy()) && !(YR->returnbusy()) && !(Z->returnbusy()) && claw1Callback->return_isend() && tailCallback->return_isend())
				{
					
				  if (i2 < (X->returnsize())-1)
				  {
					if (i2 == -2 ) { i = -1; i3 = -1; i2 = -1; }
                    i++; i3++; i2++;
					Z->onestepstart();
				    X->onestepstart();
				    YR->onestepstart();
				  
				// std::cout << i << " " << i2 << " " << i3 << std::endl;
				  }
				}
				else {
					std::cout << "busying";
				}
			}
			if (ea.getKey() == 'r')
			{
			
				i = -1; i3 = -1; i2 = -1;
				Z->recover();
				X->recover();
				YR->recover();
			}
			if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Left)
			{

				Z->mannul();
			
			}
			if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Right)
			{


				Z->mannulr();
				
			}

			if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Up)
			{


				X->mannul();
			
			}
			if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Down)
			{


				X->mannulp();
				
			}
			if (ea.getKey() == 'n')
			{


				YR->mannul();
			
			}
			break;
		}
		case (osgGA::GUIEventAdapter::PUSH):
		{
		
		}

		default:
			break;
		}
		return false;
	}

};