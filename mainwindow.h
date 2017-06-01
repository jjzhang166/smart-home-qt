#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "envwindow.h"
#include "setwindow.h"
#include "ctlwindow.h"
#include "syswindow.h"
#include "globalval.h"
#include "sockthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_envBtn_clicked();

    void on_ctlBtn_clicked();

    void on_setBtn_clicked();

    void on_sysBtn_clicked();

    void connectFailSlot();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackWidget;
    EnvWindow *envWindow;
    SetWindow *setWindow;
    CtlWindow *ctlWindow;
    SysWindow *sysWindow;
    SockThread *sockThread;
};

#endif // MAINWINDOW_H
