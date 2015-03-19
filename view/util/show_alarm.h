#ifndef SHOW_ALARM_H
#define SHOW_ALARM_H

#include <QLabel>
#include <QDebug>

#include "util/setting.h"

class show_alarm
{
public:
    show_alarm();

    void set_default_green_alarm(QLabel *alarm);
    void set_off_alarm(QLabel *alarm);

    void update_alarm_wave(QLabel *alarm, struct t_setting *set, double peak_max, double peak_min, int index);
    void update_alarm_spek(QLabel *alarm, struct t_setting *set, double peak, int index);
};

#endif // SHOW_ALARM_H
