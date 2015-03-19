#include "show_alarm.h"

show_alarm::show_alarm()
{
}

void show_alarm::set_default_green_alarm(QLabel *alarm)
{
    alarm->setPixmap(QPixmap(LOW));
}

void show_alarm::set_off_alarm(QLabel *alarm)
{
    alarm->setPixmap(QPixmap(DEFAULT));
}

void show_alarm::update_alarm_wave(QLabel *alarm, t_setting *set, double peak_max, double peak_min, int index)
{
#if 1
    if (peak_max > set->plot_set[index].alarm_hh || peak_min < set->plot_set[index].alarm_ll){
        alarm->setPixmap(QPixmap(HIGH));
        return;
    }
    else if (peak_max > set->plot_set[index].alarm_h || peak_min < set->plot_set[index].alarm_l){
        alarm->setPixmap(QPixmap(MEDIUM));
        return;
    }
    else if (peak_max < set->plot_set[index].alarm_h || peak_min > set->plot_set[index].alarm_h){
        alarm->setPixmap(QPixmap(LOW));
        return;
    }
#endif
}

void show_alarm::update_alarm_spek(QLabel *alarm, t_setting *set, double peak, int index)
{
    /* Band Analisis */
#if 0
    if (peak > 0.010) alarm->setPixmap(QPixmap(HIGH));
    else if (peak < 0.010 && peak > 0.005) alarm->setPixmap(QPixmap(MEDIUM));
    else if (peak < 0.005 && peak > 0.002) alarm->setPixmap(QPixmap(LOW));
#endif
}
