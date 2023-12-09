#include <QCoreApplication>
#include <QApplication>
#include "mytcpserver.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);

    //MyTcpServer server;
    MainWindow w;
    w.show();

    return a.exec();
}

