#pragma once

#include <osg/BlendColor>
#include <osg/BlendFunc>

class turn_off_circle : public osg::NodeVisitor
{
public:
	turn_off_circle(osg::ref_ptr<osg::Switch> circleswitch)
		: osg::NodeVisitor( // 遍历所有子节点。
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
		_circleswitch(circleswitch) {}

	virtual void apply(osg::Node &node)
	{
		_node = &node;
		_circleswitch->setChildValue(_node.get(), false);

		// 继续遍历场景图形剩余的部分。
		traverse(node);
	}

	 

protected:
	osg::ref_ptr<osg::Switch> _circleswitch;
	osg::ref_ptr<osg::Node> _node;
};



class turn_on_circle : public osg::NodeVisitor
{
public:
	turn_on_circle(osg::ref_ptr<osg::Switch> circleswitch)
		: osg::NodeVisitor( // 遍历所有子节点。
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
		_circleswitch(circleswitch) {}

	virtual void apply(osg::Node& node)
	{
		_node = &node;
		_circleswitch->setChildValue(_node.get(), true);

		// 继续遍历场景图形剩余的部分。
		traverse(node);
	}



protected:
	osg::ref_ptr<osg::Switch> _circleswitch;
	osg::ref_ptr<osg::Node> _node;
};

class change_circle : public osg::NodeVisitor
{
public:
	change_circle()
		: osg::NodeVisitor( // 遍历所有子节点。
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) {}
		
	virtual void apply(osg::Node& node)
	{
		_node = &node;
		osg::StateSet* state = _node->getOrCreateStateSet();
		osg::ref_ptr<osg::BlendColor> rpBlendColor = new osg::BlendColor();//混合颜色
		state->setAttributeAndModes(rpBlendColor.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//添加混合颜色属性
		rpBlendColor->setConstantColor(osg::Vec4(0.0, 1.0, 0.0, 1.0));

		
		// 继续遍历场景图形剩余的部分。
		traverse(node);
	}



protected:
	
	osg::ref_ptr<osg::Node> _node;
};



class FindNamedNode : public osg::NodeVisitor
{
public:
	FindNamedNode(const std::string& name)
		: osg::NodeVisitor( // 遍历所有子节点。
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
		_name(name) {}

	// 这个方法将调用场景功能图形中的每个节点，
	// 检查其名称是否符合输入的要求。
	// 如果符合的话，将保存节点的地址。
	virtual void apply(osg::Node& node)
	{
		if (node.getName() == _name)
			_node = &node;

		// 继续遍历场景图形剩余的部分。
		traverse(node);
	}

	osg::Node* getNode() { return _node.get(); }

protected:
	std::string _name;
	osg::ref_ptr<osg::Node> _node;
};