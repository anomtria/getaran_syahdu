#include "tampil_band_analisis.h"

tampil_band_analisis::tampil_band_analisis()
{
}

void tampil_band_analisis::tampil_band_analis(t_setting *set, QwtPlot *plot, QwtPlotCurve *band_start, QwtPlotCurve *band_start_max,
                                              QwtPlotCurve *band_stop, QwtPlotCurve *band_stop_max, QwtPlotCurve *lim_l, QwtPlotCurve *lim_h,
                                              double f_min, double f_max, double a_min, double a_max){

    int i;

    /* bandwidth */
    double *b_start;
    double *b_start_max;
    double *b_stop;
    double *b_stop_max;
    double *l_low;
    double *l_high;

    double *l_low_2;
    double *l_high_2;
    double *rangeband;

    /* limit */
    float band = f_min;
    float minimum = 0.0;
    float maximum = a_min;

    int len = (set->spek.line * 2.56)/2;

    b_start = (double *) malloc(len * sizeof(double));
    memset((char *) b_start, 0, (len * sizeof(double)));

    b_stop = (double *) malloc(len * sizeof(double));
    memset((char *) b_stop, 0, (len * sizeof(double)));

    l_low = (double *) malloc(len * sizeof(double));
    memset((char *) l_low, 0, (len * sizeof(double)));

    l_high = (double *) malloc(len * sizeof(double));
    memset((char *) l_high, 0, (len * sizeof(double)));

    b_start_max = (double *) malloc(len * sizeof(double));
    memset((char *) b_start_max, 0, (len * sizeof(double)));

    b_stop_max = (double *) malloc(len * sizeof(double));
    memset((char *) b_stop_max, 0, (len * sizeof(double)));

    rangeband = (double *) malloc(len * sizeof(double));
    memset((char *) rangeband, 0, (len * sizeof(double)));

    l_low_2 = (double *) malloc(len * sizeof(double));
    memset((char *) l_low_2, 0, (len * sizeof(double)));

    l_high_2 = (double *) malloc(len * sizeof(double));
    memset((char *) l_high_2, 0, (len * sizeof(double)));

    /* set band_start  and band_stop */
    for (i = 0; i < len; i++){
        b_start[i] = (double) f_min;
        b_stop[i] = (double) f_max;

        b_start_max[i] = (double) f_min;
        b_stop_max[i] = (double) f_max;

        l_low[i] = (double) minimum;
        l_high[i] = (double) maximum;

        if (minimum < a_min) minimum++;
        if (maximum < a_max) maximum++;
    }

    band_start->setRawSamples(b_start, l_low, len);
    band_start->setPen(QPen(Qt::red, 2, Qt::SolidLine));

    band_stop->setRawSamples(b_stop, l_low, len);
    band_stop->setPen(QPen(Qt::red, 2, Qt::SolidLine));


    band_start_max->setRawSamples(b_start_max, l_high, len);
    band_start_max->setPen(QPen(Qt::red, 2, Qt::DotLine));

    band_stop_max->setRawSamples(b_stop_max, l_high, len);
    band_stop_max->setPen(QPen(Qt::red, 2, Qt::DotLine));

    for (i = 0; i < len; i++){
        l_low_2[i]  = (double) a_min;
        l_high_2[i] = (double) a_max;

        rangeband[i] = (double) band;

        if (band < f_max) band++;
    }

    lim_l->setRawSamples(rangeband, l_low_2, len);
    lim_l->setPen(QPen(Qt::red, 2, Qt::SolidLine));

    lim_h->setRawSamples(rangeband, l_high_2, len);
    lim_h->setPen(QPen(Qt::red, 2, Qt::DotLine));


    /* attach band alarm */
    band_start->attach(plot);
    band_stop->attach(plot);
    band_start_max->attach(plot);
    band_stop_max->attach(plot);

    lim_l->attach(plot);
    lim_h->attach(plot);

    plot->replot();
}
