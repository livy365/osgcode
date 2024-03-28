#pragma once


#define PI       3.14159265358979323846   

osg::ref_ptr<osg::Node> plant(int radius);
osg::ref_ptr<osg::Node> circle(int radius, double degree, osg::Vec3 center);
void settex(osg::Node* pnode, std::string picturefile);
void leftpick(osg::ref_ptr<osgViewer::Viewer> Viewer, float x, float y);
osg::ref_ptr<osg::Node> tail(int radius, double degree, osg::Vec3 center);
void setinf(std::string name, wchar_t words[]);

class plants
{
   
   public:
      
       void setplantsradiusandname(float a, std::string b, std::string c)
       {
           plantsradius = a;
           name = b;
           texfile = c;
       }
       void setcircle(float radius, float degree,osg::Vec3 center)
       {
           circleradius = radius;
           orbdegree = degree;
           orbdeflectioncenter = center;
           
           if (orbdeflectioncenter == osg::Vec3(1, 0, 0))
           {
               orbrotatecenter = osg::Vec3(0, -sin((PI / 180) * (orbdegree)), cos((PI / 180) * (orbdegree)));
               circleradiusvec = osg::Vec3(circleradius, 0, 0);
           }
           if (orbdeflectioncenter == osg::Vec3(0, 1, 0))
           {
               orbrotatecenter = osg::Vec3(sin((PI / 180) * (orbdegree)), 0, cos((PI / 180) * (orbdegree)));
               circleradiusvec = osg::Vec3(0, circleradius, 0);
           }
           
       }
      void setplantsinf(wchar_t words[])
       {
          setinf(name+"inf", words);

       }


       osg::ref_ptr<osg::MatrixTransform> setplants(float _orbspeed)
       {
           osg::ref_ptr<osg::MatrixTransform> orb = new osg::MatrixTransform;
           osg::ref_ptr<osg::MatrixTransform> selfrotate = new osg::MatrixTransform;
           orbspeed=_orbspeed;
           Orbitalrevolutiontate* rotate = new Orbitalrevolutiontate(orbspeed);
           osg::ref_ptr<osg::Node> plants=plant(plantsradius);
           plants->setName(name);
           osg::ref_ptr<osg::Node>plantscircle = circle(circleradius, orbdegree, orbdeflectioncenter);
           circleSwitch->addChild(plantscircle.get());
           plantscircle->setName(name+"circle");
           std::string file = texfile;
           settex(plants, file);
           selfrotate->setDataVariance(osg::Object::DYNAMIC);
           selfrotate->setUpdateCallback(new rotation);
           selfrotate->addChild(plants);
           orb->setDataVariance(osg::Object::DYNAMIC);
           rotate->setcenter(orbrotatecenter);
           rotate->setradius(circleradiusvec);
           orb->setUpdateCallback(rotate);
           rotate->setName(name + "orb");
           orb->addChild(selfrotate.get());
           osg::ref_ptr<osg::Node> plantstail = tail(circleradius, orbdegree, orbdeflectioncenter);
           osg::ref_ptr<osg::MatrixTransform> tailrotate = new osg::MatrixTransform;
           Orbitalrevolutiontate* tailrotateclass = new Orbitalrevolutiontate(orbspeed);
           tailrotateclass->setcenter(orbrotatecenter);
           tailrotateclass->setradius(osg::Vec3(0, 0, 0));

           tailrotate->setDataVariance(osg::Object::DYNAMIC);
           tailrotate->setUpdateCallback(tailrotateclass);
           tailrotate->addChild(plantstail);
           tailrotate->setName(name + "tail");
           circleSwitch->addChild(tailrotate.get());

           return orb.get();
       }




   protected:
       std::string name,texfile;
       int plantsradius;
       float circleradius,orbdegree,orbspeed;
       osg::Vec3 orbdeflectioncenter,orbrotatecenter, circleradiusvec;
       


};



