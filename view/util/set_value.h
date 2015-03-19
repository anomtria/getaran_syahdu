#ifndef SET_VALUE_H
#define SET_VALUE_H

#include "util/setting.h"

#include "view/dialog_setting.h"
#include "ui_dialog_setting.h"

class set_value
{
public:
    set_value();

    void set_setting_value(Dialog_setting *d_set, struct t_setting *set);
    void compact_ip_address(char ip[32], QLineEdit *seg1, QLineEdit *seg2, QLineEdit *seg3, QLineEdit *seg4);

    void set_sby_cbvalue(Dialog_setting *d_set, int idx_cb, int idx_output, struct t_setting *set);
};

#endif // SET_VALUE_H
