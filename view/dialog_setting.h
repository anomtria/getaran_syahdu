#ifndef DIALOG_SETTING_H
#define DIALOG_SETTING_H

#include <QDialog>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlDatabase>
#include <QClipboard>
#include <QColorDialog>

#include "qwt_plot.h"
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include "qwt_plot_grid.h"
#include <qwt.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include <qwt_legend.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

#include "util/setting.h"
#include "util/msg_box.h"

#include "view/util/show_grafik.h"

namespace Ui {
class Dialog_setting;
}

class plot_grafik : public QwtPlot
{
    Q_OBJECT    
public slots:

private slots:

};

class Dialog_setting : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_setting(QWidget *parent = 0);
    ~Dialog_setting();
    Ui::Dialog_setting *ui;
    void showEvent(QShowEvent *);

    QComboBox *trend_param[JUM_KURVA];
    QComboBox *kanal_out[JUM_KURVA];
    QComboBox *tipe_data[JUM_KURVA];
    QComboBox *sb_y[JUM_KURVA];
    QComboBox *sb_x_wave[JUM_KURVA];
    QComboBox *sb_x_spek[JUM_KURVA];
    QComboBox *en_alarm1[JUM_KURVA];
    QComboBox *en_alarm2[JUM_KURVA];

    QLineEdit *judul[JUM_KURVA];
    QLineEdit *judul_bawah[JUM_KURVA];
    QLineEdit *ref_rpm[JUM_KURVA];
    QLineEdit *LL[JUM_KURVA];
    QLineEdit *L[JUM_KURVA];
    QLineEdit *H[JUM_KURVA];
    QLineEdit *HH[JUM_KURVA];

    QCheckBox *kanal_en[JUM_KURVA];

    QPushButton *warna[JUM_KURVA];
    QString warna_str[JUM_KURVA];

    float min_frek[JUM_KANAL][JUM_BAND_AREA];
    float max_frek[JUM_KANAL][JUM_BAND_AREA];
    float alarm_l[JUM_KANAL][JUM_BAND_AREA];
    float alarm_h[JUM_KANAL][JUM_BAND_AREA];

    int last_idx;

public slots:

private:
    plot_grafik *p_band;
    plot_grafik *p_wave;
    plot_grafik *p_spec;

    show_grafik *s_graph;

    QwtPlotCurve marker[JUM_BAND_AREA][6];

    void init_grafik();

    double x_axis[1000];
    double y_axis[1000];

    int idx_change;

private slots:
    void on_pushButton_clicked();
    //void on_buttonBox_accepted();

    void get_sby_cbox(int index, int ch_out);

    /* ComboBox Kanal Ouput Changed */
    void get_sby_cbox0(int ch_out);
    void get_sby_cbox1(int ch_out);
    void get_sby_cbox2(int ch_out);
    void get_sby_cbox3(int ch_out);
    void get_sby_cbox4(int ch_out);
    void get_sby_cbox5(int ch_out);
    void get_sby_cbox6(int ch_out);
    void get_sby_cbox7(int ch_out);

    /* PushButton Color */
    void call_dialogColor0();
    void call_dialogColor1();
    void call_dialogColor2();
    void call_dialogColor3();
    void call_dialogColor4();
    void call_dialogColor5();
    void call_dialogColor6();
    void call_dialogColor7();
    void on_pb_update_band_clicked();

    void on_rad_auto_wave_clicked();
    void on_rad_fixed_wave_clicked();
    void on_rad_auto_spek_clicked();
    void on_rad_fixed_spek_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_combo_lines_spektrum_currentIndexChanged(const QString &arg1);
    void on_rad_auto_len_spek_clicked();
    void on_rad_fixed_len_spek_clicked();
    void on_rad_auto_len_wave_clicked();
    void on_rad_fixed_len_wave_clicked();
    void on_ip_module2_clicked(bool checked);

    void init_userinterface();
    void on_cb_en_filter_clicked(bool checked);
};

#endif // DIALOG_SETTING_H
