#include "sockthread.h"

SockThread::SockThread()
{
    tcpSocket = new QTcpSocket;
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receive()));
}

void SockThread::run()
{
    //默认启动连接
    connectSlot();
    QThread::sleep(10);
}

void SockThread::connectSlot()
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
            emit connectFail();
        }
    }
}

void SockThread::receive()
{
    QByteArray data;
    data = tcpSocket->readAll();
    QString str(data);
    qDebug()<<"收到数据：" + str;
}
