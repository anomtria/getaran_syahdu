#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QClipboard>
#include <QtSql>
#include <QUdpSocket>
#include <QThread>
#include <QMdiSubWindow>
#include <QLayoutItem>
#include <QElapsedTimer>
#include <QProcess>
#include <unistd.h>
#include <math.h>

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

#include "libku/fft/fourier.h"
#include "libku/windowing/buat_filter.h"
#include "libku/windowing/windowkan.h"

#include "model/file_setting.h"
#include "model/database.h"
#include "model/mythread.h"
#include "model/udpsocket.h"
#include "model/signalprocessing.h"

#include "model/formula.h"

#include "view/form_trend.h"
#include "view/form_replay.h"
#include "view/dialog_setting.h"
#include "view/form_log.h"
#include "view/form_lap.h"
#include "view/dialog_report.h"

#include "view/util/set_value.h"
#include "view/util/show_grafik.h"
#include "view/util/show_table.h"
#include "view/util/show_alarm.h"

#include "controller/tampil_band_analisis.h"

namespace Ui {
class MainWindow;
}

class main_graphic : public QwtPlot
{
    Q_OBJECT
public slots:

private slots:

};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    void showEvent(QShowEvent *);

    main_graphic *plot[JUM_CURVE];
    QHBoxLayout *HL[JUM_CURVE];

    int tipe_window;
    int tipe_window_lama;

    QLabel *alarm;
    QLabel *alarm_wave;
    QLabel *alarm_spek;

private slots:
    /* udpsocket */
    void ada_udp_data();
    void minta_data_lagi();
    void refresh_plot();
    void simpan_ke_db();

    /* grab widget */
    void copy_grafik_toclipboard0();
    void copy_grafik_toclipboard1();
    void copy_grafik_toclipboard2();
    void copy_grafik_toclipboard3();
    void copy_grafik_toclipboard4();
    void copy_grafik_toclipboard5();
    void copy_grafik_toclipboard6();
    void copy_grafik_toclipboard7();
    void copy_grafik_toclipboard8();
    void copy_grafik_toclipboard9();
    void copy_grafik_toclipboard10();
    void copy_grafik_toclipboard11();
    void copy_grafik_toclipboard12();
    void copy_grafik_toclipboard13();
    void copy_grafik_toclipboard14();
    void copy_grafik_toclipboard15();

    /* overlay band analisis */
    void overlay_band_ch1();
    void overlay_band_ch2();
    void overlay_band_ch3();
    void overlay_band_ch4();
    void overlay_band_ch5();
    void overlay_band_ch6();
    void overlay_band_ch7();
    void overlay_band_ch8();

    /* show peak marker */
    void show_peak_marker_ch1();
    void show_peak_marker_ch2();
    void show_peak_marker_ch3();
    void show_peak_marker_ch4();
    void show_peak_marker_ch5();
    void show_peak_marker_ch6();
    void show_peak_marker_ch7();
    void show_peak_marker_ch8();

    void show_harmonic_marker_ch1();
    void show_harmonic_marker_ch2();
    void show_harmonic_marker_ch3();
    void show_harmonic_marker_ch4();
    void show_harmonic_marker_ch5();
    void show_harmonic_marker_ch6();
    void show_harmonic_marker_ch7();
    void show_harmonic_marker_ch8();

    /* Action Trigger */
    void on_actionExit_triggered();
    void on_actionRun_triggered();
    void on_actionTrending_triggered();
    void on_actionRe_Play_triggered();
    void on_actionSetting_triggered();
    void on_actionLog_triggered();
    void on_actionReport_triggered();

    void on_actionNew_Database_triggered();
    void on_actionOpen_Database_triggered();
    void on_actionModulConfigurator_triggered();

private:
    struct t_setting *setting;

    QTimer *tim;
    QTimer *tim_db;

    /* udp network */
    QUdpSocket *udpSocket;
    QUdpSocket *udp_data;

    int loop_test;
    int paket_diharapkan;   /* jumlah paket yang diharapkan */
    int paket_masuk;
    int pernah_penuh;
    int udp_count;
    int tim_count;

    /* plot grafik */
    QwtPlotCurve kurva[JUM_CURVE];

    /* plot peak */
    QwtPlotMarker peak_m[JUM_PLOT];
    int peak_stats[JUM_PLOT];

    /* plot harmonic */
    QwtPlotMarker harmonic_m[JUM_PLOT][10];
    int harmonic_stats[JUM_PLOT];

    /* plot band analisis */
    QwtPlotCurve band_start_min[JUM_KANAL][JUM_BAND_AREA];
    QwtPlotCurve band_start_max[JUM_KANAL][JUM_BAND_AREA];
    QwtPlotCurve band_stop_min[JUM_KANAL][JUM_BAND_AREA];
    QwtPlotCurve band_stop_max[JUM_KANAL][JUM_BAND_AREA];
    QwtPlotCurve limit_low[JUM_KANAL][JUM_BAND_AREA];
    QwtPlotCurve limit_high[JUM_KANAL][JUM_BAND_AREA];

    double *data_y[JUM_PLOT];
    double *data_y_afterhpf[JUM_PLOT];
    double *sumbu_x;

    /* proses fft */
    int spektrum_points;

    double *fft_re_out[JUM_PLOT];
    double *fft_im_out[JUM_PLOT];
    double *fft_magt[JUM_PLOT];
    double *sb_x[JUM_PLOT];

    double *hasil_windowing;
    double *win_coef;

    /* simpan ke db */
    int cnt_ch1;
    int cnt_ch2;
    int cnt_ch3;
    int cnt_ch4;

    int cnt_save_spek;

    float *data_save[JUM_PLOT];
    float *data_get[JUM_PLOT];

    /* Lain-lain */
    Form_Trend *f_trn;
    Form_Replay *f_rpl;
    Dialog_setting *d_set;
    Form_log *log;
    Form_lap *lap;

    UdpSocket *s_udp;
    set_value *s_value;
    show_grafik *s_graph;
    show_table *s_table;
    file_setting *f_set;
    database *dbase;
    show_alarm *s_alarm;
    MyThread *mThread;
    TrThread *tThread;

    signalProcessing *sigpro;
    formula *form;
    tampil_band_analisis *band;

    int count_db;

    void init_timer();
    void init_grafik();
    void init_alarm(int status);
    void init_udpSocket();
    void init_util_popup();
    void init_UserInterface();

    void set_memory();
    void flush_memory();
    void free_memory();

    void proses_fft(double *wave_y, int index);

    QMenu *popMenu[JUM_CURVE];
    QMenu *popMenu_spektrum[JUM_PLOT];

    QAction *pop_copy_grafik[JUM_CURVE];
    QAction *pop_export_data[JUM_CURVE];

    QAction *pop_separator[JUM_PLOT];
    QAction *pop_separator_2[JUM_PLOT];
    QAction *pop_spektrum_list[JUM_PLOT];
    QAction *pop_peak[JUM_PLOT];
    QAction *pop_harmonic[JUM_PLOT];
    QAction *pop_band_analisis[JUM_PLOT];

    int cnt_led;

    void delay(int msec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    /* simpan ke database */
    double rms_spek[JUM_PLOT];
    double peakmin_spek[JUM_PLOT];
    double peakmax_spek[JUM_PLOT];

    /* refrash tampilan */
    double miny[JUM_PLOT];
    double maxy[JUM_PLOT];
    double maxx[JUM_PLOT];

    double miny_s[JUM_PLOT];
    double maxy_s[JUM_PLOT];
    double maxx_s[JUM_PLOT];

    double rms_w;
    double rms_s;
};

#endif // MAINWINDOW_H
