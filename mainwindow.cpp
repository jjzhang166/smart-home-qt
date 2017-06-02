#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackWidget = new QStackedWidget;
    ui->horizontalLayout->addWidget(stackWidget);
    ui->horizontalLayout->setStretch(0, 1);
    ui->horizontalLayout->setStretch(1, 10);

    //填充堆栈窗体
    envWindow = new EnvWindow;
    setWindow = new SetWindow;
    ctlWindow = new CtlWindow;
    sysWindow = new SysWindow;

    stackWidget->addWidget(envWindow);
    stackWidget->addWidget(ctlWindow);
    stackWidget->addWidget(setWindow);
    stackWidget->addWidget(sysWindow);

//    connect(sysWindow, SIGNAL(connectSig()), this, SLOT(connectSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_envBtn_clicked()
{
    stackWidget->setCurrentIndex(0);
}

void MainWindow::on_ctlBtn_clicked()
{
    stackWidget->setCurrentIndex(1);
}

void MainWindow::on_setBtn_clicked()
{
    stackWidget->setCurrentIndex(2);
}

void MainWindow::on_sysBtn_clicked()
{
    stackWidget->setCurrentIndex(3);
}
