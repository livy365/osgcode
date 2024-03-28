#pragma once

class claw1Call : public osg::NodeCallback
{
public:


	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	void start();
	bool return_isend();
protected:
	bool starttag=false;
	bool isend = false;
};
class claw2Call : public osg::NodeCallback
{
public:


	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

protected:

};
class claw3Call : public osg::NodeCallback
{
public:


	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);

protected:

};