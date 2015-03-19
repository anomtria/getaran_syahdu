#ifndef FILE_SETTING_H
#define FILE_SETTING_H

#include <QTimer>
#include <QSettings>

#include "util/setting.h"

#include "view/dialog_setting.h"
#include "ui_dialog_setting.h"

class graphic_display : public QwtPlot
{
    Q_OBJECT

public slots:

private slots:

};


class file_setting
{
public:
    file_setting();

    void get_setting_modul_server(Dialog_setting *d_set, struct t_setting *setting);
    void get_setting_database(Dialog_setting *d_set, struct t_setting *setting);
    void get_setting_kanal(Dialog_setting *d_set, struct t_setting *setting);
    void get_setting_waveform(Dialog_setting *d_set, struct t_setting *setting);
    void get_setting_spektrum(Dialog_setting *d_set, struct t_setting *setting);
    void get_setting_band_analysis(Dialog_setting *d_set, struct t_setting *setting);

    void write_settings(struct t_setting *setting);
    void read_settings(struct t_setting *setting);
    void default_settings(struct t_setting *setting);

    void simpan_data_setting(Dialog_setting *d_set, struct t_setting *setting);

    /* rumus cari resolusi */
    float resolusi_line_to_hz(int line, int fmax);
    float resolusi_line_to_cpm(int line, int fmax);
    float resolusi_line_to_order(int line, int fmax, int ref_rpm);

};

#endif // FILE_SETTING_H
