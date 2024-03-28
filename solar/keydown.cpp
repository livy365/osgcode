
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>
#include <osg/LineWidth>
#include <iostream>
#include <osg/BlendColor>
#include <osg/BlendFunc>
#include "turn_circle.h"

extern osg::ref_ptr<osg::Switch> circleSwitch;
extern osg::ref_ptr<osg::Switch> infSwitch;
extern osg::ref_ptr<osg::Node>solarinf;
extern osg::ref_ptr<osg::Node> overnode ;

void keyd()
{
	turn_on_circle ModelVisitor(circleSwitch);
	circleSwitch->accept(ModelVisitor);
	turn_off_circle offinf(infSwitch);
	infSwitch->accept(offinf);
	infSwitch->setChildValue(solarinf, true);

}

void keya()
{
	std::string name = overnode->getName();
	std::string circlename = name + "circle";
	FindNamedNode changecircle(circlename);
	circleSwitch->accept(changecircle);
	//FeCommon::setColor(changecircle.getNode(), osg::Vec4(0.0, 1.0, 1.0, 1.0));
	osg::StateSet* state = changecircle.getNode()->getOrCreateStateSet();
	osg::BlendColor* pcolorwidth = dynamic_cast<osg::BlendColor*>(state->getAttribute(osg::StateAttribute::BLENDCOLOR));
	osg::Vec4 b = pcolorwidth->getConstantColor();
	if (pcolorwidth&&b== osg::Vec4(1.0, 1.0, 1.0, 1.0))
	{
		
		std::cout << "hhh";
		
		osg::ref_ptr<osg::BlendColor> rpBlendColor = new osg::BlendColor();//混合颜色
		state->setAttributeAndModes(rpBlendColor.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//添加混合颜色属性
		rpBlendColor->setConstantColor(osg::Vec4(0.0, 1.0, 1.0, 1.0));
      
	}
	if (pcolorwidth && b != osg::Vec4(1.0, 1.0, 1.0, 1.0))
	{

		std::cout << "hhh";

		osg::ref_ptr<osg::BlendColor> rpBlendColor = new osg::BlendColor();//混合颜色
		state->setAttributeAndModes(rpBlendColor.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//添加混合颜色属性
		rpBlendColor->setConstantColor(osg::Vec4(1.0, 1.0, 1.0, 1.0));

	}
	
}
void keyplus()
{
	
	std::string name = overnode->getName();
	std::string circlename = name + "circle";
	FindNamedNode changecircle(circlename);
	circleSwitch->accept(changecircle);
	osg::StateSet* state = changecircle.getNode()->getOrCreateStateSet();
	osg::LineWidth* pLinewidth = dynamic_cast<osg::LineWidth*>(state->getAttribute(osg::StateAttribute::LINEWIDTH));
	if (pLinewidth)
	{ float b = pLinewidth->getWidth();
	  std::cout << b;
	  b = b + 0.5;
	  osg::LineWidth* lw = new osg::LineWidth(b);
	  state->setAttribute(lw);
	
	}
	  
}
void keyminus()
{

	std::string name = overnode->getName();
	std::string circlename = name + "circle";
	FindNamedNode changecircle(circlename);
	circleSwitch->accept(changecircle);
	osg::StateSet* state = changecircle.getNode()->getOrCreateStateSet();
	osg::LineWidth* pLinewidth = dynamic_cast<osg::LineWidth*>(state->getAttribute(osg::StateAttribute::LINEWIDTH));
	if (pLinewidth)
	{
		float b = pLinewidth->getWidth();
		std::cout << b;
		b = b - 0.5;
		osg::LineWidth* lw = new osg::LineWidth(b);
		state->setAttribute(lw);
	}


}