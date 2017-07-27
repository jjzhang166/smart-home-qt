#ifndef ENVWINDOW_H
#define ENVWINDOW_H

#include <QtWidgets>
#include <QtGlobal>
#include <QTimer>
#include <QTcpSocket>
#include "globalval.h"

namespace Ui {
class EnvWindow;
}

//环境信息
typedef struct env_info {
    int snum;		 //仓库编号
    float temperature;	 //温度
    float humidity;		 //湿度
    float ill;		 //光照
    float bet;		 //电池电量
    float adc; 		 //电位器信息

    signed char x;			 //三轴信息
    signed char y;
    signed char z;
}envMsg_t;


class EnvWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EnvWindow(QWidget *parent = 0);
    ~EnvWindow();
    void anolog();

private slots:
    void connectSlot();
    void receive();

private:
    Ui::EnvWindow *ui;
    QTcpSocket *tcpSocket;
    QTimer *timer;

    void initTable();
};

#endif // ENVWINDOW_H
