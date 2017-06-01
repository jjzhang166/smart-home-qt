#include "envwindow.h"
#include "ui_envwindow.h"

EnvWindow::EnvWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvWindow)
{
    ui->setupUi(this);
    ui->widget->setVisible(false);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this,  SLOT(timeoutSlot()));
    timer->start(1000);
}

EnvWindow::~EnvWindow()
{
    delete ui;
}

void EnvWindow::timeoutSlot()
{
    temp = qrand()%20;
    hum = qrand()%50;
    ill = qrand()%20;
//    bet = qrand()%3;
    adc = qrand()%100;

    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(temp, 10)));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem(QString::number(hum, 10)));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem(QString::number(ill, 10)));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem(QString::number(adc, 10)));
}

