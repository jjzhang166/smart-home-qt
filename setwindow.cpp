#include "setWindow.h"
#include "ui_setWindow.h"

SetWindow::SetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWindow)
{
    ui->setupUi(this);
}

SetWindow::~SetWindow()
{
    delete ui;
}
