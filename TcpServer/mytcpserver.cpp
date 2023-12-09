#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

#include "db/database.h"
#include "dataanimals.h"
#include <math.h>
#include "Debug/logger.h"


MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    DataSystems::Instance().clear();

    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 5555)){
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_robot";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();        
        QString values = QString::fromStdString(array.toStdString());        
        QStringList list= values.split("|", QString::SkipEmptyParts);
        for(QString val: list)
        {
            //qDebug()<<" --- value: "<<val;
            logger::WriteMsg("client val: "+val.toStdString());
            QStringList list_two_value= val.split(";", QString::SkipEmptyParts);
            qDebug()<<list_two_value[0]<<" = "<<list_two_value[1];
            {
                db_func->insert_add(tab, list_two_value[0], list_two_value[1]);
            }
        }
    }
    QString sql_insert = db_func->insert_add(tab, "param1", "");
    db_func->sql_exec(sql_insert, "add Robot");
        //mTcpSocket->write(array);
    }
    else
    {
        logger::WriteMsg("Данные робота не записаны, неверные параметры базы данных");
    }
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}

