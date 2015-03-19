#ifndef TAMPIL_TREND_H
#define TAMPIL_TREND_H

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

class tampil_trend
{
public:
    tampil_trend();

    void show_trend(QwtPlot *plot, QwtPlotCurve *kurva, double *peak, double *time, int len);
    void set_scale(QwtPlot *plot, int len);
};

#endif // TAMPIL_TREND_H
