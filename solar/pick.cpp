#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>
#include "osgGA/GUIEventHandler"
#include "osgGA/GUIEventAdapter"
#include "osgGA/GUIActionAdapter"
#include "osgFX/Scribe"
#include "turn_circle.h"

#include<iostream>

//extern osg::ref_ptr<osg::Node> earthcircle;
extern osg::ref_ptr<osg::Switch> circleSwitch;
extern osg::ref_ptr<osg::Switch> infSwitch ;
extern osg::ref_ptr<osg::Node>solarinf;
extern osg::ref_ptr<osg::Node> overnode;

void leftpick(osg::ref_ptr<osgViewer::Viewer> Viewer,float x,float y) {
	osg::ref_ptr<osg::Node> node = new osg::Node();
	osg::ref_ptr<osg::Group> parent = new osg::Group();
	osgUtil::LineSegmentIntersector::Intersections intersections;
	if (Viewer->computeIntersections(x, y, intersections))
	{
		osgUtil::LineSegmentIntersector::Intersection intersection = *intersections.begin();//获取碰撞检测结果
		osg::NodePath& nodePath = intersection.nodePath;//获取节点集合
		node = (nodePath.size() >= 1) ? nodePath[nodePath.size() - 1] : 0;
		parent = (nodePath.size() >= 2) ? dynamic_cast<osg::Group*> (nodePath[nodePath.size() - 2]) : 0;
		
		if (node!=0) {

			turn_off_circle ModelVisitor(circleSwitch);
			circleSwitch->accept(ModelVisitor);
			turn_off_circle offinf(infSwitch);
			infSwitch->accept(offinf);
			std::string name = node->getName();
			std::string circlename =name+"circle";
			std::string infname = name + "inf";
			std::string tailname = name + "tail";
			std::cout << circlename;
			FindNamedNode turnoncircle(circlename);
			circleSwitch->accept(turnoncircle);
			circleSwitch->setChildValue(turnoncircle.getNode(), true);
			FindNamedNode turnoninf(infname);
			infSwitch->accept(turnoninf);
			infSwitch->setChildValue(turnoninf.getNode(), true);
			infSwitch->setChildValue(solarinf, false);
			FindNamedNode turnontail(tailname);
			circleSwitch->accept(turnontail);
			circleSwitch->setChildValue(turnontail.getNode(), true);

		}
		
	     
		/*if (parent.get() && node.get())
		{
			osg::ref_ptr< osgFX::Scribe> rpScribe = dynamic_cast<osgFX::Scribe*>(parent.get());//高亮节点
			if (!rpScribe) {

				osg::ref_ptr< osgFX::Scribe> scribe = new osgFX::Scribe;
				scribe->addChild(node.get());
				parent->replaceChild(node.get(), scribe.get());
	
			}
			else {
				osg::Node::ParentList parentList = rpScribe->getParents();
				for (osg::Node::ParentList::iterator itr = parentList.begin(); itr != parentList.end(); ++itr)
				{
					(*itr)->replaceChild(rpScribe.get(), node.get());

				}
				
			}
			

		}
		*/
		overnode = node;
	}
	else
	{
		turn_off_circle ModelVisitor(circleSwitch);
		circleSwitch->accept(ModelVisitor);
		turn_off_circle offinf(infSwitch);
		infSwitch->accept(offinf);
		infSwitch->setChildValue(solarinf, true);
		overnode = 0;
	}
}