#pragma once
#include <QObject>
#include<osgQOpenGL/osgQOpenGLWidget>
class ResManager :
    public QObject
{
    Q_OBJECT
public:
    ResManager()
    {
        _widget = new osgQOpenGLWidget;
      
    }
    osgQOpenGLWidget* _widget;

public slots:
    void onInitialized();
};

