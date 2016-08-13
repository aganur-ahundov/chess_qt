#include "mainwindow.h"
#include <QApplication>

#include "igraphicscontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    IGraphicsController c;
    c.show();

    return a.exec();
}
