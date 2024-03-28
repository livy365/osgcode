#pragma once

#include <osg/BlendColor>
#include <osg/BlendFunc>

class turn_off_circle : public osg::NodeVisitor
{
public:
	turn_off_circle(osg::ref_ptr<osg::Switch> circleswitch)
		: osg::NodeVisitor( // ���������ӽڵ㡣
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
		_circleswitch(circleswitch) {}

	virtual void apply(osg::Node &node)
	{
		_node = &node;
		_circleswitch->setChildValue(_node.get(), false);

		// ������������ͼ��ʣ��Ĳ��֡�
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
		: osg::NodeVisitor( // ���������ӽڵ㡣
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
		_circleswitch(circleswitch) {}

	virtual void apply(osg::Node& node)
	{
		_node = &node;
		_circleswitch->setChildValue(_node.get(), true);

		// ������������ͼ��ʣ��Ĳ��֡�
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
		: osg::NodeVisitor( // ���������ӽڵ㡣
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) {}
		
	virtual void apply(osg::Node& node)
	{
		_node = &node;
		osg::StateSet* state = _node->getOrCreateStateSet();
		osg::ref_ptr<osg::BlendColor> rpBlendColor = new osg::BlendColor();//�����ɫ
		state->setAttributeAndModes(rpBlendColor.get(), osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);//��ӻ����ɫ����
		rpBlendColor->setConstantColor(osg::Vec4(0.0, 1.0, 0.0, 1.0));

		
		// ������������ͼ��ʣ��Ĳ��֡�
		traverse(node);
	}



protected:
	
	osg::ref_ptr<osg::Node> _node;
};



class FindNamedNode : public osg::NodeVisitor
{
public:
	FindNamedNode(const std::string& name)
		: osg::NodeVisitor( // ���������ӽڵ㡣
			osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
		_name(name) {}

	// ������������ó�������ͼ���е�ÿ���ڵ㣬
	// ����������Ƿ���������Ҫ��
	// ������ϵĻ���������ڵ�ĵ�ַ��
	virtual void apply(osg::Node& node)
	{
		if (node.getName() == _name)
			_node = &node;

		// ������������ͼ��ʣ��Ĳ��֡�
		traverse(node);
	}

	osg::Node* getNode() { return _node.get(); }

protected:
	std::string _name;
	osg::ref_ptr<osg::Node> _node;
};