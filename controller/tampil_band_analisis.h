#ifndef TAMPIL_BAND_ANALISIS_H
#define TAMPIL_BAND_ANALISIS_H

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

class tampil_band_analisis
{
public:
    tampil_band_analisis();

    void tampil_band_analis(struct t_setting *set, QwtPlot *plot, QwtPlotCurve *band_start, QwtPlotCurve *band_start_max,
                            QwtPlotCurve *band_stop, QwtPlotCurve *band_stop_max, QwtPlotCurve *lim_l, QwtPlotCurve *lim_h,
                            double f_min, double f_max, double a_min, double a_max);


};

#endif // TAMPIL_BAND_ANALISIS_H
