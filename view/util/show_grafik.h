#ifndef SHOW_GRAFIK_H
#define SHOW_GRAFIK_H

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>

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

class show_grafik
{
public:
    show_grafik();

    void create_grafik(QHBoxLayout *HL, QwtPlot *plot, QwtPlotCurve *kurva, struct t_setting *set, double rms, double peakmin, double peakmax, int index);
    void create_grafik_spek(QHBoxLayout *HL, QwtPlot *plot, QwtPlotCurve *kurva, struct t_setting *set, double rms, double peakmin, double peakmax, int index);

    void update_grafik_wave(QwtPlot *plot, QwtPlotCurve *kurva, struct t_setting *set, int index);
    void update_grafik_spek(QwtPlot *plot, QwtPlotCurve *kurva, struct t_setting *set, int index);

    void update_grafik_info_wave(QwtPlot *plot, t_setting *set, double miny, double maxy, double maxx,
                            double rms, double peakmin, double peakmax, int index);
    void update_grafik_info_spek(QwtPlot *plot, t_setting *set, double miny, double maxy, double maxx,
                            double rms, double peakmax, int index);

    void set_grafik_info_wave(QwtPlot *plot, struct t_setting *set, int index);
    void set_grafik_info_spek(QwtPlot *plot, struct t_setting *set, int index);

    void set_grafik_scale_wave(QwtPlot *plot, struct t_setting *set, double miny, double maxy, double maxx, int index);
    void set_grafik_scale_spek(QwtPlot *plot, struct t_setting *set, double miny, double maxy, double maxx, int index);

    void set_grafik_title_wave(QwtPlot *plot, struct t_setting *set, double rms, double peakmin, double peakmax, int index);
    void set_grafik_title_spek(QwtPlot *plot, struct t_setting *set, double rms, double peakmax, int index);

    void set_grafik_color(QwtPlotCurve *kurva, struct t_setting *set, int index);

    void set_marker_band(QwtPlot *plot, QwtPlotCurve *band_start, QwtPlotCurve *band_start_max, QwtPlotCurve *band_stop, QwtPlotCurve *band_stop_max,
                          QwtPlotCurve *lim_l, QwtPlotCurve *lim_h, float f_min, float f_max, float a_min, float a_max);

    void set_peak_marker(QwtPlot *plot, QwtPlotMarker *peak, double frek, double amplitude, int len, bool stats);
    void set_harmonic_marker(QwtPlot *plot, QwtPlotMarker *harmonic, double frek, double amplitude, int len, bool stats, int index, struct t_setting *set);
};

#endif // SHOW_GRAFIK_H
