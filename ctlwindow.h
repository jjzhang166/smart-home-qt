#ifndef CTLWINDOW_H
#define CTLWINDOW_H

#include <QWidget>

namespace Ui {
class CtlWindow;
}

class CtlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CtlWindow(QWidget *parent = 0);
    ~CtlWindow();

private:
    Ui::CtlWindow *ui;
};

#endif // CTLWINDOW_H
