#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QObject>
#include <QWidget>
struct Clock{
    uint16_t _seconds{};
    uint16_t _minutes{};
    uint16_t _hours{};

    void tick()
    {
        ++_seconds;
        if(_seconds==59)
        {
            _seconds=0;
            ++_minutes;
            if(_minutes==59)
            {
                _minutes=0;
                ++_hours;
            };
        }
    }
};

class QLabel;
class TimerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimerWidget(QWidget *parent = nullptr);

signals:
private:
    Clock _clock;
    QTimer*_timer{};
    QLabel*_minutes{};
    QLabel*_seconds{};
    QLabel*_hours{};
    void onTimerTimeOut();
};

#endif // TIMERWIDGET_H
