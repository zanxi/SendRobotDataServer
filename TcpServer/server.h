#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QHostAddress host = QHostAddress::Any,
                    quint16 port      =  5550, //Constants::Server::DEFAULT_PORT,
                    QObject *parent   = 0);
    ~Server();

public slots:
    void start();
    void finishLoad();

signals:
    void signalEndLoad();


protected:
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

private:
    QHostAddress m_host;
    quint16      m_port;
};



#endif // SERVER_H
