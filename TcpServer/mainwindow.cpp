#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QCoreApplication>

#include "db/database.h"
#include "dataanimals.h"
#include <math.h>
#include "Debug/logger.h"

#include <QDateTime>

#include "server.h"
#include "utils/imageview.h"


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
                                                                                      "padding: 4 20000 4 10;"
                                                                                      "}");

    DataSystems::Instance().clear();

    {
        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {
            //QString sql2=QString("TRUNCATE TABLE dataentry_robot;");
            //db_func->sql_exec(sql2, "delete records robot");



            /*
            db_func->sql_exec("DROP TABLE dataentry_robot;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_robot"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "Robot_No text,"
                              "paramfile1 bytea,"
                              "paramfile2 bytea,"
                              "coord_teat_lf text,"
                              "coord_teat_lr text,"
                              "coord_teat_rf text,"
                              "coord_teat_rr text,"
                              "param1 text,"
                              "param2 text,"
                              "param3 text,"
                              "param4 text,"
                              "paramtime1 text,"
                              "paramtime2 text,"
                              "paramtime3 text,"
                              "paramtime4 text"
                              ")", "create table");
            /**/
        }
    }

    server = new Server();

    mTimer=new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),this, SLOT(slotMessageTransferFile()));
    mTimer->start(milliSeconds);
    connect(server, &Server::signalEndLoad, this, &MainWindow::slotImageView);

    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MainWindow::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 7777)){
        ui->lineEdit->setText("server is not started");
    } else {
        ui->lineEdit->setText("server is started !!!!!!!!!!!!!!");
    }



    return;



    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MainWindow::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 5555)){
        ui->lineEdit->setText("server is not started");
    } else {
        ui->lineEdit->setText("server is started !!!!!!!!!!!!!!");
    }

    mTcpServer_file = new QTcpServer(this);

    connect(mTcpServer_file, &QTcpServer::newConnection, this, &MainWindow::slotNewConnection2);

    if(!mTcpServer_file->listen(QHostAddress::Any, 5550)){
        ui->lineEdit->setText("server is not started");
    } else {
        ui->lineEdit->setText("server is started !!!!!!!!!!!!!!");
    }
}

void MainWindow::slotImageView()
{
    logger::WriteLog(" ----------- End load image ---------- size: "+ QString::number(QFile(QApplication::applicationDirPath() + "/" + "star2.jpg").size()));
    ui->lineEdit->setText(" ----------- End load image ----------- size: "+ QString::number(QFile(QApplication::applicationDirPath() + "/" + "star2.jpg").size()));

    //return;

    ImageView *imageView = new ImageView(this);    
    imageView->setDisplayStyle(imageView->STYLE::contain);//
    imageView->setLoadingPixmap(QPixmap(QApplication::applicationDirPath() + "/" + "star2.jpg"));


    if(ui->verticalLayout_2->count()<1)
    {
        //form_dataentry_dataentry___transfer *tf = new form_dataentry_dataentry___transfer(this);
        //ui->verticalLayout_2->addWidget(imageView);
        //return;
    }

    QLayoutItem *child = ui->verticalLayout_2->takeAt(0);
    //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
    if(!child) {return;}
    QWidget* w = child->widget();
    delete child;
    if(!w) {return;}
    ui->verticalLayout_2->removeWidget(w);
    delete w;

    //form_dataentry_dataentry___transfer *tf = new form_dataentry_dataentry___transfer(this);

    ui->verticalLayout_2->addWidget(imageView);
}


void MainWindow::slotMessageTransferFile()
{
    ui->textEdit->setText(DataSystems::Instance().log);
}

MainWindow::~MainWindow()
{
    mTcpServer->close();
    delete ui;
}

void MainWindow::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    //mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MainWindow::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MainWindow::slotClientDisconnected);
}

void MainWindow::slotNewConnection2()
{
    mTcpSocket_file = mTcpServer_file->nextPendingConnection();

    mTcpSocket_file->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket_file, &QTcpSocket::readyRead, this, &MainWindow::slotServerRead2);
    connect(mTcpSocket_file, &QTcpSocket::disconnected, this, &MainWindow::slotClientDisconnected2);
}

// read file
void MainWindow::slotServerRead2()
{
    logger::WriteMsg("Read bytes file:  ----------------");

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QFile fileOut (QApplication::applicationDirPath()+"/"+ "star_receive.jpg");
        if (fileOut.exists()){ fileOut.remove(); }

       if (fileOut.open (QIODevice::Append))
       {

        QDataStream streamOut(&fileOut);

        //QByteArray array;
        QString tab = "dataentry_robot";
        while(mTcpSocket_file->bytesAvailable()>0)
        {
            DataSystems::Instance().y++;            
            QByteArray array = mTcpSocket_file->read(mTcpSocket_file->bytesAvailable());
            fileOut.write(array);

            logger::WriteLog(QString::number(DataSystems::Instance().y)+ QString(") Read bytes file: ") + QString::number(array.size())+" ----------------");
            //logger::WriteLog("Read bytes file: " + QString::number(array.size())+" ----------------");
            ui->textEdit->setText(DataSystems::Instance().log);
        }        
       }
       fileOut.close();

       logger::WriteLog("End Read bytes file !!!!!!!!!!!!!!!! ");
       ui->textEdit->setText(DataSystems::Instance().log);
    }

    else
    {
        logger::WriteMsg("Данные робота не записаны, неверные параметры базы данных");
        logger::WriteLog("Данные робота не записаны, неверные параметры базы данных");
        ui->textEdit->setText(DataSystems::Instance().log);
    }

}

void MainWindow::slotServerRead()
{
    qDebug()<<"read";

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_robot";
        while(mTcpSocket->bytesAvailable()>0)
        {
            qDebug()<<"read - save ---------";
            DataSystems::Instance().y++;
            QByteArray array = mTcpSocket->readAll();
            QString values = QString::fromStdString(array.toStdString());
            DataSystems::Instance().log = values+"\n";
            logger::WriteLog("("+QString::number(DataSystems::Instance().y)+"):  "+values);

            ui->textEdit->setText(DataSystems::Instance().log);
            GetData("");

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

        QDateTime dt1 = QDateTime::currentDateTime();
        //db_func->insert_add(tab, "paramtime1", dt1.toString("yyyy-MM-dd hh:mm:ss.ms"));
        QString sql_insert = db_func->insert_add(tab, "paramtime1", dt1.toString("yyyy-MM-dd hh:mm:ss.zzzZ"));
        //QString sql_insert = db_func->insert_add(tab, "param1", "");
        db_func->sql_exec(sql_insert, "add Robot");
            //mTcpSocket->write(array);
    }
    else
    {
        logger::WriteMsg("Данные робота не записаны, неверные параметры базы данных");
        logger::WriteLog("Данные робота не записаны, неверные параметры базы данных");
        ui->textEdit->setText(DataSystems::Instance().log);
    }
}

void MainWindow::GetData(QString str)
{

    DataSystems::Instance().log_t="";
    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.dataentry_cow_card WHERE animals =  '" + QString::number(i) +"';").toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_robot;").toLower();

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
            i++;
            QString dt =  query->value("param2").toString();

            QDateTime date;
            //QString d = QString::fromStdString(result.val_string.substr(0, 19));
            date.setTimeSpec(Qt::UTC);
            //QDateTime date2 = date.fromString(dt,"yyyy:MM:dd hh:mm:ss").toLocalTime();
            //qDebug()<<dt;
            //qDebug()<<dt.length()<<date.toString();

            DataSystems::Instance().log_t+="["+QString::number(query->value("id").toInt())+"]"+ dt+"| date length: "+
                         dt.size()+"| date: "+date.toString() + "\n";
            //break;
        }
    }

    ui->textEdit_2->setText(DataSystems::Instance().log_t);

    /**/

}

void MainWindow::slotClientDisconnected()
{
    mTcpSocket->flush();
    mTcpSocket->close();
}

void MainWindow::slotClientDisconnected2()
{
    mTcpServer_file->close();
}



