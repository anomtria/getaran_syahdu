#ifndef FORM_REPLAY_H
#define FORM_REPLAY_H

#include <QDialog>
#include <QDebug>
#include <QDesktopWidget>
#include <QTime>
#include <QTimer>
#include <QtCore/QDateTime>

#include <QSqlDatabase>
#include <QFileDialog>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>

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

#include <util/setting.h>
#include <view/form_note.h>

#include <view/util/show_grafik.h>

#include <model/formula.h>

#include "controller/get_db.h"
#include "controller/tampil_replay.h"

namespace Ui {
class Form_Replay;
}

class plot_replay : public QwtPlot
{
    Q_OBJECT
public slots:

private slots:

};

class Form_Replay : public QDialog
{
    Q_OBJECT

public:
    explicit Form_Replay(QWidget *parent = 0);
    ~Form_Replay();

    QHBoxLayout *HL[ JUM_PLOT ];
    plot_replay *p_replay[JUM_PLOT];

    void init_grafik(struct t_setting *setting);

    void init_timer();
    void init_default_value();
    void init_user_interface();

private slots:

    void on_pb_play_clicked();
    void on_pb_pause_clicked();
    void on_pb_note_clicked();
    void on_pb_close_clicked();

    void refresh_plot();
    void on_dtime_from_dateTimeChanged(const QDateTime &date);
    void on_dtime_to_dateTimeChanged(const QDateTime &date);

    void on_rad_fix_s_clicked();
    void on_rad_auto_s_clicked();
    void on_rad_fix_w_clicked();
    void on_rad_auto_w_clicked();

private:
    Ui::Form_Replay *ui;

    void init_memory_replay();
    void free_memory_replay();

    bool sudah_free;

    QwtPlotCurve kurva[JUM_KURVA];

    Form_Note *f_note;
    show_grafik *s_graph;
    get_db *get;
    tampil_replay *tampil;

    formula *form;

    QTimer *tim;

    QByteArray bb;
    int sample;
    int fmax;
    int ref_rpm;

    double *sb_y_wave[JUM_KANAL];
    double *sb_x_wave;

    double *win_coef;

    double *hasil_windowing;
    double *fft_re_out;
    double *fft_im_out;
    double *fft_magt[JUM_KANAL];
    double *sb_x_spek;

    int index;

    int dtime_form_sec;
    int dtime_form_min;
    int dtime_form_hour;
    int dtime_form_day;
    int dtime_form_month;
    int dtime_form_year;

    int dtime_to_sec;
    int dtime_to_min;
    int dtime_to_hour;
    int dtime_to_day;
    int dtime_to_month;
    int dtime_to_year;

    /* konfigurasi */
    int flag_auto_w;
    int flag_auto_s;
    int x_axis_index_w;
    int y_axis_index_w;
    int x_axis_index_s;
    int y_axis_index_s;
    int window_index;

    double min_y_scale_w;
    double max_y_scale_w;
    double min_y_scale_s;
    double max_y_scale_s;

    double max_x_scale_w;
    double max_x_scale_s;

    /* windowing */
    int index_window;

    /* satuan */
    double interval;
    double resolusi;

    void delay(int msec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
};

#endif // FORM_REPLAY_H
