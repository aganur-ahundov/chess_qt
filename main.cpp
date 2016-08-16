#include "mainwindow.h"
#include <QApplication>

#include "igraphicscontroller.h"
#include "board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   w.show();

//    IGraphicsController * g;
//    Board b( g );
//    //b.restart();
//    //g->show();

    return a.exec();
}
