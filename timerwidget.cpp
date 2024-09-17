#include "timerwidget.h"
#include<QTimer>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
TimerWidget::TimerWidget(QWidget *parent)
    : QWidget{parent}
{
    QFont font;
    _timer=new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&TimerWidget::onTimerTimeOut);
    _timer->setInterval(1000);
    _timer->start();

    _seconds=new QLabel();
    _minutes=new QLabel();
    _hours=new QLabel();
    font=_seconds->font();
    font.setPointSize(24);
    _seconds->setFont(font);
    _minutes->setFont(font);
    _hours->setFont(font);

    QHBoxLayout*layout=new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    layout->addWidget(_hours);
    layout->addWidget(_minutes);
    layout->addWidget(_seconds);

    _seconds->setText(": "+QString::number(_clock._seconds));
    _minutes->setText(": "+QString::number(_clock._minutes));
    _hours->setText(QString::number(_clock._hours));

    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    move(QPoint(15,15));
}

void TimerWidget::onTimerTimeOut()
{
    _clock.tick();
    _seconds->setText(": "+QString::number(_clock._seconds));
    _minutes->setText(": "+QString::number(_clock._minutes));
    _hours->setText(QString::number(_clock._hours));
};
