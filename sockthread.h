#ifndef SockThread_H
#define SockThread_H

#include <QThread>
#include <QTcpSocket>
#include <QMessageBox>
#include "globalval.h"

class SockThread : public QThread
{
    Q_OBJECT

public:
    SockThread();

signals:
    void connectFail();

private:
    void run();
    QTcpSocket *tcpSocket;
    QWidget *parent;

private slots:
    void connectSlot();
    void receive();
};

#endif // SockThread_H
