#include "socketthread.h"
#include <QApplication>
#include <QFile>
#include <QDataStream>
#include "Debug/logger.h"

#include "dataanimals.h"

SocketThread::SocketThread(qintptr descriptor, QObject *parent)
    : QThread(parent),
    m_socketDescriptor(descriptor),
    m_blockSize(0)
{
}

SocketThread::~SocketThread()
{
    delete m_socket;
}

void SocketThread::run()
{
    m_socket = new QTcpSocket;
    m_socket->setSocketDescriptor(m_socketDescriptor);

    connect(m_socket, SIGNAL(readyRead()),    this, SLOT(onReadyRead()),    Qt::DirectConnection);
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);

    exec();
}

void SocketThread::onReadyRead()
{

    DataSystems::Instance().fileNamePicture = QApplication::applicationDirPath() + "/" + "im.jpg";

    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_5_4);

    if (m_blockSize == 0) {
        if (m_socket->bytesAvailable() < 0) //sizeof(quint64))
            return;
        in >> m_blockSize;
        logger::WriteLog("Begin receive bulk [ "+ QString::number(m_socket->bytesAvailable()) + "<" +  QString::number(sizeof(quint32))  +" ] transfer file: " + QString::number(m_blockSize));
    }
    if (m_socket->bytesAvailable() < m_blockSize)
    {
        logger::WriteLog("Begin receive bulk [ "+ QString::number(m_socket->bytesAvailable()) + "<" +  QString::number(m_blockSize)  +" ] transfer file: " + QString::number(m_blockSize));
        logger::WriteLog("Begin receive transfer file: "+ DataSystems::Instance().fileNamePicture);
        return;
    }

    /**/

    //DataSystems::Instance().fileNamePicture = "star2.jpg";
    // get sending file name
    //in >> fileName;
    QByteArray line = m_socket->readAll();

    //QString filePath = QApplication::applicationDirPath(); // your file path for receiving
    //fileName = fileName.section("/", -1);

    QFile target(DataSystems::Instance().fileNamePicture);
    logger::WriteLog("Begin receive transfer file: "+ DataSystems::Instance().fileNamePicture);

    if (!target.open(QIODevice::WriteOnly)) {
        qDebug() << "Can't open file for written";
        logger::WriteLog("Can't open file for written");
        return;
    }
    target.write(line);

    target.close();

    //emit onFinishRecieved();
    m_socket->disconnectFromHost();
    logger::WriteLog("emit WorkFinishRecieved() transfer file: "+ DataSystems::Instance().fileNamePicture);
    emit WorkFinishRecieved();
}

void SocketThread::onDisconnected()
{
    m_socket->close();

    // leave event loop
    quit();
}
