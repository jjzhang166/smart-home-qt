#include "ctlwindow.h"
#include "ui_ctlwindow.h"

CtlWindow::CtlWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtlWindow)
{
    ui->setupUi(this);
}

CtlWindow::~CtlWindow()
{
    delete ui;
}
