#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:

public slots:
    void slotImageView();
    void slotNewConnection();
    void slotNewConnection2();
    void slotServerRead();
    void slotServerRead2();
    void slotClientDisconnected();    
    void slotClientDisconnected2();
    void slotMessageTransferFile();


private:    
    QTcpServer * mTcpServer;
    QTcpServer * mTcpServer_file;
    QTcpSocket * mTcpSocket;
    QTcpSocket * mTcpSocket_file;

    Server *server;

    QTimer *mTimer;
    const int milliSeconds=2*8*250;

    void GetData(QString str);

};
#endif // MAINWINDOW_H
