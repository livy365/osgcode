#include "QtWidgetsApplication1.h"
#include"ResManager.h"
#include <QtWidgets/QApplication>
#include<osgQOpenGL/osgQOpenGLWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    ResManager* resMan = new ResManager;
    QObject::connect(resMan->_widget, SIGNAL(initialized()), resMan, SLOT(onInitialized()));
    
    w.setCentralWidget(resMan->_widget);
    
    w.show();
    return a.exec();
}
