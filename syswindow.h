#ifndef SYSWINDOW_H
#define SYSWINDOW_H

#include <QWidget>
#include "globalval.h"

namespace Ui {
class SysWindow;
}

class SysWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SysWindow(QWidget *parent = 0);
    ~SysWindow();

signals:
    void connectSig();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SysWindow *ui;
};

#endif // SYSWINDOW_H
