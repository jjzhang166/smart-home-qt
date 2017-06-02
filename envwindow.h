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

typedef struct env_msg{
    uint8_t head[3];	 //标识位st:
    uint8_t type;		 //数据类型
    uint8_t snum;		 //仓库编号
    uint8_t temp[2];	 //温度
    uint8_t hum[2];		 //湿度
    uint8_t x;			 //三轴信息
    uint8_t y;
    uint8_t z;
    uint32_t ill;		 //光照
    uint32_t bet;		 //电池电量
    uint32_t adc; 		 //电位器信息
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
