#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void connectTcp();    
    void connectTcp_file_sent();
    void Convert();


    void on_pushButton_stop_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    QTcpSocket *_pSocket;
    QTcpSocket *_pSocket_file_sent;

    QTimer *mTimer;
    const int milliSeconds=250/2;

    QString fileNamePicture = "";

    void readTcpData();
    void send(QFile *m_file);
    void send2(QFile *m_file);
    void ViewLog(QString msg);
    void SendR(QString ip, int port, QString values);

};
#endif // MAINWINDOW_H
