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
    GlobalVal::ip = "192.168.1.254";
    GlobalVal::port = "8888";
    if(tcpSocket->state() == 0)
    {
        tcpSocket->connectToHost(GlobalVal::ip, (quint16)GlobalVal::port.toInt());
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
    qDebug("conver temperature=%0.2f, humidity=%0.2f, ill=%0.2f, bet=%0.2f, adc=%0.2f,", \
           evmMsg->temperature, evmMsg->humidity, evmMsg->ill, evmMsg->bet, evmMsg->adc);
    qDebug(" x=%d, y=%d, z=%d\n", evmMsg->x, evmMsg->y, evmMsg->z);
#endif
    ui->tableWidget->item(0,0)->setText(QString::number(evmMsg->temperature));
    ui->tableWidget->item(1,0)->setText(QString::number(evmMsg->humidity));
    ui->tableWidget->item(2,0)->setText(QString::number(evmMsg->ill));
    ui->tableWidget->item(3,0)->setText(QString::number(evmMsg->bet));
    ui->tableWidget->item(4,0)->setText(QString::number(evmMsg->adc));
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
