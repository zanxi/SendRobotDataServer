#include "server.h"
#include "socketthread.h"
#include "Debug/logger.h"

Server::Server(QHostAddress host, quint16 port, QObject *parent)
    : QTcpServer(parent),
    m_host(host),
    m_port(port)
{
    //...
    // your settings init there
    start();
}

void Server::start()
{
    if ( this->listen(m_host, m_port) )
    {
        qDebug() << "Server started at " << m_host.toString() << ":" << m_port;
        logger::WriteLog("Server started at " + m_host.toString() + ":" + QString::number(m_port));
    }
    else
    {
        qDebug() << "Can't start server";
        logger::WriteLog("Can't start server");
    }
}

void Server::finishLoad()
{
    logger::WriteLog("Server::finishLoad()");
    emit signalEndLoad();
}

void Server::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection = " << handle;
    SocketThread *thread = new SocketThread(handle);
    connect(thread, SIGNAL(WorkFinishRecieved()), this, SLOT(finishLoad()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    //connect(thread, SIGNAL(finished()), thread, SLOT(finishLoad()));

    thread->start();
}

Server::~Server()
{

}
