#ifndef ENVWINDOW_H
#define ENVWINDOW_H

#include <QtWidgets>

namespace Ui {
class EnvWindow;
}

class EnvWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EnvWindow(QWidget *parent = 0);
    ~EnvWindow();

private:
    Ui::EnvWindow *ui;
};

#endif // ENVWINDOW_H
