#pragma once
#include <osgViewer/ViewerEventHandlers>



extern osg::ref_ptr<osg::Switch> circleSwitch;
void leftpick(osg::ref_ptr<osgViewer::Viewer> Viewer, float x, float y);
extern osg::ref_ptr<osg::Switch> infSwitch;
extern osg::ref_ptr<osg::Node>solarinf;
osg::ref_ptr<osg::Node> overnode = new osg::Node();
void keyd();
void keya();
void keyplus();
void keyminus();

class  pushhandle : public osgGA::GUIEventHandler
{

protected:
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		osg::ref_ptr<osgViewer::Viewer> rpViewer = dynamic_cast<osgViewer::Viewer*>(&aa);//事件适配器转换成viewer
		if (!rpViewer.valid())return false;
	
		switch (ea.getEventType())//事件类型
		{
		
		   case (osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON):
		    {
			  
			   float x = ea.getX();
			   float y = ea.getY();
			   leftpick(rpViewer.get(), ea.getX(), ea.getY());
			   
			   break;
		    }
		   
		   case (osgGA::GUIEventAdapter::KEYDOWN):
		   {
			   if (ea.getKey()=='o')
			   {
              
				   keyd();

			   }
			   if (ea.getKey() == 'c'&&overnode!=0)
			   {
				   
				   keya();
			   }
			   if (ea.getKey() == 'p' && overnode != 0)
			   {

				   keyplus();
			   }
			   if (ea.getKey() == 'm' && overnode != 0)
			   {

				   keyminus();
			   }
			   break;
		   }
		   default:
			   break;



		}
		return false;
	}

};