#include "mainwindow.h"
#include <QApplication>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//   w.show();

//    IGraphicsController *g = new IGraphicsController();
//    Board b( g );
//    b.restart();
//    g->show();

    Game g;
    g.display();

    return a.exec();
}
