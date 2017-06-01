#include "syswindow.h"
#include "ui_syswindow.h"

SysWindow::SysWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysWindow)
{
    ui->setupUi(this);
}

SysWindow::~SysWindow()
{
    delete ui;
}

void SysWindow::on_pushButton_clicked()
{
    GlobalVal::ip = ui->ipEdit->text();
    GlobalVal::port = ui->portEdit->text();

    emit connectSig();
}
