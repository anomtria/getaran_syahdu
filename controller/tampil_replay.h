#ifndef TAMPIL_REPLAY_H
#define TAMPIL_REPLAY_H

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

#include "model/formula.h"

class tampil_replay
{
public:
    tampil_replay();

    formula *form;

    void show_replay(QwtPlot *plot, QwtPlotCurve *kurva, double *df, double *sbx, int len, int index_scale, double min_y, double max_y, double max_x,
                     double interval);

    void set_scale(QwtPlot *plot, int index_scale, float min_y, float max_y, double max_x, double interval);

    void proses_ftt(double *data_y, double *sb_x, double *win_coef, double *hasil_windowing, int spektrum_points, double *fft_re_out, double *fft_im_out,
                        double *fft_magt, double resolusi);

    void gen_window_coef(int spektrum_points, double *win_coef, int index_window);

    double resolusi_line_to_hz(double line, double fmax);
    double resolusi_line_to_cpm(double line, double fmax);
    double resolusi_line_to_order(double line, double fmax, double ref_rpm);

};

#endif // TAMPIL_REPLAY_H
