#include "envwindow.h"
#include "ui_envwindow.h"

EnvWindow::EnvWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvWindow)
{
    ui->setupUi(this);
    ui->widget->setVisible(false);
    //限制编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    initTable();

    tcpSocket = new QTcpSocket;
    //先进行连接
    connectSlot();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receive()));
}

EnvWindow::~EnvWindow()
{
    delete ui;
}


void EnvWindow::connectSlot()
{
    if(tcpSocket->state() == 0)
    {
        tcpSocket->connectToHost(GlobalVal::ip, GlobalVal::port.toInt());
        if(tcpSocket->waitForConnected(3000))
        {
            qDebug()<<"connect to server success";
        }
        else
        {
            qDebug()<<"connectFail";
            QMessageBox::warning(this, "错误", "网络连接失败，请检查网络设置");
        }
    }
}

void EnvWindow::receive()
{
    envMsg_t *evmMsg;
    QByteArray envData;
    envData = tcpSocket->readAll();
    evmMsg = (envMsg_t *)envData.data();

#ifdef DEBUG_ON
    qDebug("temp = %d\n", evmMsg->temp[0]);
    qDebug("hum = %d\n", evmMsg->hum[0]);
    qDebug("ill = %d\n", evmMsg->ill);
    qDebug("bet = %d\n", evmMsg->bet);
    qDebug("adc = %d\n", evmMsg->adc);
#endif
    ui->tableWidget->item(0,0)->setText(QString::number(evmMsg->temp[0], 10));
    ui->tableWidget->item(1,0)->setText(QString::number(evmMsg->hum[0], 10));
    ui->tableWidget->item(2,0)->setText(QString::number(evmMsg->ill, 10));
    ui->tableWidget->item(3,0)->setText(QString::number(evmMsg->bet, 10));
    ui->tableWidget->item(4,0)->setText(QString::number(evmMsg->adc, 10));
}

void EnvWindow::initTable()
{
    int j = 0;
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
//        for(int j=0; j<ui->tableWidget->colorCount(); j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString()));
//        }
    }
}
