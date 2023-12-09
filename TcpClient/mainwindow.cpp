#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dataanimals.h"
#include <QDateTime>
#include <math.h>
#include <QFile>
#include <QDir>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");
    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                      "padding: 4 20000 4 10;");


    mTimer=new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),this, SLOT(connectTcp()));
    //mTimer->start(milliSeconds);

    ui->pushButton_start->setEnabled(true);
    ui->pushButton_stop->setEnabled(false);



    //*********************************************

    QString folder = "d:/_download_/";
    folder = "d:/img2/";

    //*********************************************

}

void MainWindow::ViewLog(QString msg)
{
    DataSystems::Instance().log+="\t ("+QString::number(DataSystems::Instance().y)+"): "+ msg + "\t\n";
    ui->textEdit->setText(DataSystems::Instance().log);
    if(DataSystems::Instance().log.size()>700)DataSystems::Instance().log = "";
}

void MainWindow::send(QFile *m_file)
{

}


void MainWindow::send2(QFile *m_file)
{

}



void MainWindow::Convert()
{

        return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectTcp_file_sent()
{

}
void MainWindow::SendR(QString ip, int port, QString values)
{
    QByteArray data = values.toUtf8();
    QTcpSocket *socket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    socket->connectToHost(ip, port);
    if( socket->waitForConnected() ) {
        DataSystems::Instance().log+="Server access!!!!!!!!!!!!" + QString("\n");
        DataSystems::Instance().log+="("+QString::number(DataSystems::Instance().y)+") values robot: "+ values + QString("\n");
        ui->textEdit->setText(DataSystems::Instance().log);
        socket->write( data );
    }
    else
    {
        mTimer->stop();
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_stop->setEnabled(false);
        DataSystems::Instance().log+="("+QString::number(DataSystems::Instance().y)+") Server access denied" + QString("\n");
        ui->textEdit->setText(DataSystems::Instance().log);

    }

    socket->flush();
    socket->close();

    if(DataSystems::Instance().log.size()>700)DataSystems::Instance().log = "";

}

void MainWindow::connectTcp()
{
    DataSystems::Instance().y++;
    QByteArray data; // <-- fill with data
    QDateTime dt1 = QDateTime::currentDateTime();

    //"Robot_No text,"
    double v1 = 0*((DataSystems::Instance().y<80)?(10+(rand()%5)/7.0):(
                    (DataSystems::Instance().y<120)?(20+(rand()%6)/7.0):(
                  (DataSystems::Instance().y<200)?(15+(rand()%4)/7.0):(12+(rand()%4)/7.0))));
    double v2 = 0*((DataSystems::Instance().y<80)?(70+(rand()%8)/7.0):(
                    (DataSystems::Instance().y<120)?(60+(rand()%3)/7.0):(
                 (DataSystems::Instance().y<200)?(65+(rand()%3)/7.0):(68+(rand()%5)/7.0))));
    double v3 = (DataSystems::Instance().y<80)?(70+sin(DataSystems::Instance().y)):(
                    (DataSystems::Instance().y<120)?(60+sin(DataSystems::Instance().y)):(65+2*sin(DataSystems::Instance().y)));

    QString values =
        "Robot_No;"+QString("Robo")+QString::number((rand()%10000))+"|"
                   "coord_teat_lf;"+QString::number(v1)+"|"
                     //"coord_teat_lr;"+QString::number(41.5+(rand()%3)/7.0)+"|"
                     "coord_teat_lr;"+QString::number(v2)+"|"
                     "coord_teat_rf;"+QString::number(v3)+"|"
                                             "coord_teat_rr;"+QString::number(40+(rand()%5)/7.0);
                     //"param1;"+FiletoText;
                    // +"|paramtime2;"+dt1.toString("yyyy-MM-dd hh:mm:ss");

    //SendR("192.168.0.102", 7777, values);
    //SendR("127.0.0.1", 7777, values);

    if(ui->comboBox_hostname->currentText()=="")
    {
        mTimer->stop();
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_stop->setEnabled(false);
    }

    else
    {
        ui->pushButton_start->setEnabled(false);
        ui->pushButton_stop->setEnabled(true);
    }


    SendR(ui->comboBox_hostname->currentText(), ui->lineEdit_port->text().toInt(), values);

}

void MainWindow::readTcpData()
{

}


void MainWindow::on_pushButton_clicked()
{
    connectTcp();    
}


void MainWindow::on_pushButton_stop_clicked()
{
    mTimer->stop();
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_stop->setEnabled(false);
    DataSystems::Instance().log+="Stop sent to server" + QString("\n");
    ui->textEdit->setText(DataSystems::Instance().log);


}


void MainWindow::on_pushButton_start_clicked()
{
    //connectTcp();
    //return;

    mTimer->start(milliSeconds);
    ui->pushButton_start->setEnabled(false);
    ui->pushButton_stop->setEnabled(true);
    DataSystems::Instance().log+="Start sent to server !!!!!!!!!!!" + QString("\n");
    ui->textEdit->setText(DataSystems::Instance().log);
}


void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_comboBox_activated(int index)
{    

}


