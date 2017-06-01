#ifndef ENVWINDOW_H
#define ENVWINDOW_H

#include <QtWidgets>
#include <QtGlobal>
#include <QTimer>

namespace Ui {
class EnvWindow;
}

class EnvWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EnvWindow(QWidget *parent = 0);
    ~EnvWindow();
    void anolog();

private slots:
    void timeoutSlot();

private:
    Ui::EnvWindow *ui;
    int temp;
    int hum;
    int ill;
    int bet;
    int adc;

    QTimer *timer;
};

#endif // ENVWINDOW_H
