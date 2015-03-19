#include "tampil_replay.h"

tampil_replay::tampil_replay()
{
}

void tampil_replay::show_replay(QwtPlot *plot, QwtPlotCurve *kurva, double *df, double *sbx, int len, int index_scale, double min_y, double max_y, double max_x
                                , double interval){

    kurva->setRawSamples(sbx, df, len);
    kurva->attach(plot);

    this->set_scale(plot, index_scale, min_y, max_y, max_x, interval);

    plot->replot();
}

void tampil_replay::set_scale(QwtPlot *plot, int index_scale, float min_y, float max_y, double max_x, double interval){
    plot->setAxisScale(QwtPlot::xBottom, 0, max_x, interval);

    if(index_scale == 0){
        plot->setAxisScale(QwtPlot::yRight, (double) min_y, (double) max_y, 0);
    }
}


/* --------------------- Gen Spektrum Replay -------------------------*/
void tampil_replay::proses_ftt(double *data_y, double *sb_x, double *win_coef, double *hasil_windowing, int spektrum_points,
                               double *fft_re_out, double *fft_im_out, double *fft_magt, double resolusi){
    /* proses FFT */
    windowkand(data_y, hasil_windowing, win_coef, spektrum_points);

    fft_double( spektrum_points, 0, hasil_windowing, 0, fft_re_out, fft_im_out);

    for (int i=0; i< spektrum_points; i++)
    {
        fft_magt[i] = sqrt( (fft_re_out[i] * fft_re_out[i]) + ( fft_im_out[i] * fft_im_out[i]));
        fft_magt[i] = fft_magt[i] / spektrum_points;

        fft_magt[i] = fft_magt[i] * 2.00 ;

        sb_x[i] = (double) ((double) i * (double) resolusi);
    }

    fft_magt[0] = 0.00;
    fft_magt[(spektrum_points/2)-1] = 0.00;
}

void tampil_replay::gen_window_coef(int spektrum_points, double *win_coef, int index_window){
    memset((char *) win_coef, 0, spektrum_points*sizeof(double));

    switch(index_window){
    case 0:
        buat_hanningd(win_coef, spektrum_points);
        break;
    case 1:
        buat_rectangulard(win_coef, spektrum_points);
        break;
    case 2:
        buat_blackmand(win_coef, spektrum_points);
        break;
    default:
        buat_hammingd(win_coef, spektrum_points);
        break;
    }
}

/* nilai resolusinya saja */
double tampil_replay::resolusi_line_to_hz(double line, double fmax){
    double res;
    res = (double) ((double) (fmax / line) );

    return (double) res;
}

double tampil_replay::resolusi_line_to_cpm(double line, double fmax){
    double res;
    res = (double) ((double) (fmax / line));
    res = (double) res * (double) (60.0);

    return (double) res;
}

double tampil_replay::resolusi_line_to_order(double line, double fmax, double ref_rpm){
    double res;
    res = (double) ((double) (fmax / line));
    res = (double) ((double) res / (double)((double) ref_rpm / (double) 60.00));

    return (double) res;
}
