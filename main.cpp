#include "mainwindow.h"
#include <QApplication>
#include "global.h"
#include "objecttracker.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setFixedSize(395,300);
    //w.showMaximized();
    w.move(200,50);
    w.show();

    GlobalData::isEdge = false;

    EdgeDetect edgeDetect;
    edgeDetect.runner();

//    ObjectTracker ot;
//    ot.runner();

   // a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));


    return a.exec();
}
