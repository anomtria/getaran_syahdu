#ifndef SHOW_TABLE_H
#define SHOW_TABLE_H


#include <QTableWidget>

#include "util/setting.h"

#include "view/dialog_setting.h"
#include "ui_dialog_setting.h"

class show_table
{
public:
    show_table();

    void init_table_kanal(Dialog_setting *d_set);
    void isi_table_kanal(Dialog_setting *d_set);

    void init_table_band(Dialog_setting *d_set);
};

#endif // SHOW_TABLE_H
