#pragma once

class tailCall : public osg::NodeCallback
{
public:


	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	void start();
	bool return_isend();
protected:
	bool starttag = false;
	float plus=0;
	bool isend = false;
};
class tail_foundation_Call : public osg::NodeCallback
{
public:


	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	void start();
protected:
	bool starttag = false;
	float plus = 0;
	//osg::ref_ptr<osg::Switch>stockswitch;
};