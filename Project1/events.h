
#include<osgViewer/ViewerEventHandlers>
#include<iostream>
#include<fstream>
#include<string>

//extern float a[10];
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
			if (ea.getKey() == 'a')
			{

				//a[1] =0;
				std::cout << "kkk";
			}
	

			break;
		}
	
		default:
			break;
		}
		return false;
	}


};