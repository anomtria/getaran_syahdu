#ifndef FORM_TREND_H
#define FORM_TREND_H

#include <QDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QDesktopWidget>

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
#include "view/form_note.h"

#include "view/util/show_grafik.h"

#include "controller/tampil_trend.h"
#include "controller/get_db.h"

namespace Ui {
class Form_Trend;
}

class plot_trend : public QwtPlot
{
    Q_OBJECT
public slots:

private slots:

};

class Form_Trend : public QDialog
{
    Q_OBJECT
    
public:
    explicit Form_Trend(QWidget *parent = 0);
    ~Form_Trend();

    QHBoxLayout *HL[ JUM_PLOT ];

    plot_trend *p_trend[JUM_PLOT];

    void init_grafik(struct t_setting *setting);
    
private slots:
    void on_pb_note_clicked();
    void on_pb_gen_clicked();
    void on_pb_close_clicked();

    void on_dtime_from_dateTimeChanged(const QDateTime &date);

    void on_dtime_to_dateTimeChanged(const QDateTime &date);

private:
    Ui::Form_Trend *ui;

    void showEvent(QShowEvent *);

    void set_memory_trend();
    void free_memory_trend();

    bool sudah_set;

    Form_Note *f_note;
    show_grafik *s_graph;
    get_db *get;
    tampil_trend *tampil;

    QwtPlotCurve kurva[JUM_KURVA];

    int len;

    double peak;
    double time;

    double *peaks[JUM_KURVA];
    double *times[JUM_KURVA];

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
};

#endif // FORM_TREND_H
