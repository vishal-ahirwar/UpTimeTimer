#include "timerwidget.h"
#include<QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerWidget widget;
    widget.show();
    return a.exec();
}
