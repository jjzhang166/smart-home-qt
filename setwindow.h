#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QWidget>

namespace Ui {
class SetWindow;
}

class SetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = 0);
    ~SetWindow();

private:
    Ui::SetWindow *ui;
};

#endif // SETWINDOW_H
