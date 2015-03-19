#include "show_grafik.h"

show_grafik::show_grafik()
{
}

void show_grafik::create_grafik(QHBoxLayout *HL, QwtPlot *plot, QwtPlotCurve *kurva, t_setting *set, double rms,
                                double peakmin, double peakmax, int index){

    this->set_grafik_info_wave(plot, set, index);
    this->set_grafik_title_wave(plot, set, rms, peakmin, peakmax, index);
    this->set_grafik_color(kurva, set, index);

    /* Attach QwtPlot */
    HL->addWidget(plot);

    kurva->attach(plot);
}

void show_grafik::create_grafik_spek(QHBoxLayout *HL, QwtPlot *plot, QwtPlotCurve *kurva, t_setting *set, double rms,
                                     double peakmin, double peakmax, int index){

    this->set_grafik_info_spek(plot, set, index);
    this->set_grafik_title_spek(plot, set, rms, peakmax, index);
    this->set_grafik_color(kurva, set, index);

    /* Attach QwtPlot */
    HL->addWidget(plot);

    kurva->attach(plot);
}

void show_grafik::update_grafik_wave(QwtPlot *plot, QwtPlotCurve *kurva, t_setting *set, int index){
    this->set_grafik_info_wave(plot, set, index);
    this->set_grafik_color(kurva, set, index);

    plot->replot();
}

void show_grafik::update_grafik_spek(QwtPlot *plot, QwtPlotCurve *kurva, t_setting *set, int index){
    this->set_grafik_info_spek(plot, set, index);
    this->set_grafik_color(kurva, set, index);

    plot->replot();
}

void show_grafik::update_grafik_info_wave(QwtPlot *plot, t_setting *set, double miny, double maxy, double maxx,
                                     double rms, double peakmin, double peakmax, int index){

    set_grafik_scale_wave(plot, set, miny, maxy, maxx, index);
    set_grafik_title_wave(plot,set, rms, peakmin, peakmax, index);

    /* Re Plotting QwtPlot */
    plot->replot();
}

void show_grafik::update_grafik_info_spek(QwtPlot *plot, t_setting *set, double miny, double maxy, double maxx,
                                     double rms, double peakmax, int index){
    set_grafik_scale_spek(plot, set, miny, maxy, maxx, index);
    set_grafik_title_spek(plot, set, rms, peakmax, index);

    /* Re Plotting QwtPlot */
    plot->replot();
}

void show_grafik::set_grafik_scale_wave(QwtPlot *plot, struct t_setting *set, double miny, double maxy, double maxx, int index){
    plot->setAxisScale(QwtPlot::xBottom, 0, maxx, (double) set->plot_set[index].interval_wave);
    plot->setAxisScale(QwtPlot::yLeft, miny, maxy, 0);
}

void show_grafik::set_grafik_scale_spek(QwtPlot *plot, struct t_setting *set, double miny, double maxy, double maxx, int index){

    switch (set->plot_set[index].index_judul_sb_x_spek){
    case 0:
        plot->setAxisScale(QwtPlot::xBottom, 0, maxx, (double) 100);
        break;
    case 1:
        plot->setAxisScale(QwtPlot::xBottom, 0, maxx, (double) 2);
        break;
    default :
        plot->setAxisScale(QwtPlot::xBottom, 0, maxx, (double) set->plot_set[index].interval_spek);
        break;
    }

    plot->setAxisScale(QwtPlot::yLeft, miny, maxy, 0);
}

void show_grafik::set_grafik_title_wave(QwtPlot *plot, t_setting *set, double rms, double peakmin, double peakmax, int index){
    /* Set QwtPlot title */
    char title[512];
    char title_bawah[512];

    QString judul;

    float c_factor;

    if (rms != 0.00){
        c_factor = (float) ((float) peakmax / (float) rms);
    }
    else{
        c_factor = 0.0;
    }

    sprintf(title, "%s - %s\n\n", set->plot_set[index].judul, set->plot_set[index].judul_bawah);
    sprintf(title_bawah, "Overall : RMS = %.3f ; Peak Min = %.3f ; Peak Max = %.3f ; Crest Factor = %.3f",(float) rms, (float) peakmin, (float) peakmax, (float) c_factor);

    strcat(title, title_bawah);

    judul.sprintf("%s", title);

    QwtText titles;
    titles.setText(judul);
    titles.setFont(QFont("Heletica", 9, 2, false));

    plot->setTitle(titles);
}

void show_grafik::set_grafik_title_spek(QwtPlot *plot, t_setting *set, double rms, double peakmax, int index){
    /* Set QwtPlot title */
    char title[512];
    char title_bawah[512];

    QString judul;

    sprintf(title, "%s - %s\n\n", set->plot_set[index].judul, set->plot_set[index].judul_bawah);
    sprintf(title_bawah, "Overall : RMS = %.3f ; Peak = %.3f",(float) rms, (float) peakmax);

    strcat(title, title_bawah);

    judul.sprintf("%s", title);

    QwtText titles;
    titles.setText(judul);
    titles.setFont(QFont("Heletica", 9, 2, false));

    plot->setTitle(titles);
}

void show_grafik::set_grafik_info_wave(QwtPlot *plot, t_setting *set, int index){
    QwtPlotGrid *grid = new QwtPlotGrid;

    char title_y[32];
    char title_x[32];

    sprintf(title_y, "%s", set->plot_set[index].judul_sumbu_y);
    sprintf(title_x, "%s", set->plot_set[index].judul_sumbu_x_wave);

    QString sb_y_title;
    QString sb_x_title;

    sb_y_title.sprintf("%s", title_y);
    sb_x_title.sprintf("%s", title_x);

    QwtText kiri;
    kiri.setText(sb_y_title);
    kiri.setFont(QFont("Helvetica", 10));
    kiri.setColor( Qt::red);
    plot->setAxisTitle(QwtPlot::yLeft, kiri);

    QwtText bawah;
    bawah.setText(sb_x_title);
    bawah.setFont(QFont("Helvetica", 10));
    bawah.setColor( Qt::red );
    plot->setAxisTitle(QwtPlot::xBottom, bawah);

    grid->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach( plot );
}

void show_grafik::set_grafik_info_spek(QwtPlot *plot, t_setting *set, int index){
    QwtPlotGrid *grid = new QwtPlotGrid;

    char title_y[32];
    char title_x[32];

    sprintf(title_y, "%s", set->plot_set[index].judul_sumbu_y);
    sprintf(title_x, "%s", set->plot_set[index].judul_sumbu_x_spek);

    QString sb_y_title;
    QString sb_x_title;

    sb_y_title.sprintf("%s", title_y);
    sb_x_title.sprintf("%s", title_x);

    QwtText kiri;
    kiri.setText(sb_y_title);
    kiri.setFont(QFont("Helvetica", 10));
    kiri.setColor( Qt::red);
    plot->setAxisTitle(QwtPlot::yLeft, kiri);

    QwtText bawah;
    bawah.setText(sb_x_title);
    bawah.setFont(QFont("Helvetica", 10));
    bawah.setColor( Qt::red );
    plot->setAxisTitle(QwtPlot::xBottom, bawah);

    grid->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach( plot );

}

void show_grafik::set_grafik_color(QwtPlotCurve *kurva, t_setting *set, int index){
    kurva->setPen(QPen(QColor(set->plot_set[index].warna)));
}

/* ---------------------------- Marker (Peak, PEak Harmonics, etc) --------------------------*/
void show_grafik::set_peak_marker(QwtPlot *plot, QwtPlotMarker *peak, double frek, double amplitude, int len, bool stats){
    QString value;
    value.sprintf("X (%.1f, %.1f)", (float) frek, (float) amplitude);

    QwtText p_text;
    p_text.setText(value);
    p_text.setFont(QFont("Helvetica", 8));
    p_text.setColor(QColor(Qt::blue));

    peak->setValue((double) ((float)frek - (float) (len / 100.0)), amplitude);
    peak->setLabel(p_text);
    peak->setLabelAlignment(Qt::AlignRight);

    if (stats == true){
        peak->attach(plot);
    }
    else{
        peak->detach();
    }

    plot->replot();
}

void show_grafik::set_harmonic_marker(QwtPlot *plot, QwtPlotMarker *harmonic, double frek, double amplitude, int len, bool stats, int index, t_setting *set){
    QString value;
    //value.sprintf("X (%.1f,%.1f)", (float) ((float) index + 1.0) * frek, (float) amplitude);
    value.sprintf("X");

    QwtText p_text;
    p_text.setText(value);
    p_text.setFont(QFont("Helvetica", 8));
    p_text.setColor(QColor(Qt::blue));

    switch (set->plot_set[index].index_judul_sb_x_spek){
    case 0 :
        harmonic->setValue((double) ((float)frek - (float) (len / 100.0)), amplitude);
        break;
    case 1 :
        harmonic->setValue((double) ((float)frek - ((float) (len / 100.0))), amplitude);
        break;
    default :
        harmonic->setValue((double) ((float)frek - (float) (len / 100.0)), amplitude);
        break;
    }

    harmonic->setLabel(p_text);
    harmonic->setLabelAlignment(Qt::AlignRight);

    if (stats == true){
        harmonic->attach(plot);
    }
    else{
        harmonic->detach();
    }

    plot->replot();
}

/* --------------------------------- Grafik Band Analysis --------------------------------- */
void show_grafik::set_marker_band(QwtPlot *plot, QwtPlotCurve *band_start, QwtPlotCurve *band_start_max,
                                  QwtPlotCurve *band_stop, QwtPlotCurve *band_stop_max, QwtPlotCurve *lim_l, QwtPlotCurve *lim_h,
                                  float f_min, float f_max, float a_min, float a_max){
 #if 1
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

    b_start = (double *) malloc(1000 * sizeof(double));
    memset((char *) b_start, 0, (1000 * sizeof(double)));

    b_stop = (double *) malloc(1000 * sizeof(double));
    memset((char *) b_stop, 0, (1000 * sizeof(double)));

    l_low = (double *) malloc(1000 * sizeof(double));
    memset((char *) l_low, 0, (1000 * sizeof(double)));

    l_high = (double *) malloc(1000 * sizeof(double));
    memset((char *) l_high, 0, (1000 * sizeof(double)));

    b_start_max = (double *) malloc(1000 * sizeof(double));
    memset((char *) b_start_max, 0, (1000 * sizeof(double)));

    b_stop_max = (double *) malloc(1000 * sizeof(double));
    memset((char *) b_stop_max, 0, (1000 * sizeof(double)));

    rangeband = (double *) malloc(1000 * sizeof(double));
    memset((char *) rangeband, 0, (1000 * sizeof(double)));

    l_low_2 = (double *) malloc(1000 * sizeof(double));
    memset((char *) l_low_2, 0, (1000 * sizeof(double)));

    l_high_2 = (double *) malloc(1000 * sizeof(double));
    memset((char *) l_high_2, 0, (1000 * sizeof(double)));

    /* set band_start  and band_stop */
    for (i = 0; i < 1000; i++){
        b_start[i] = (double) f_min;
        b_stop[i] = (double) f_max;

        b_start_max[i] = (double) f_min;
        b_stop_max[i] = (double) f_max;

        l_low[i] = (double) minimum;
        l_high[i] = (double) maximum;

        if (minimum < a_min) minimum++;
        if (maximum < a_max) maximum++;
    }

    band_start->setRawSamples(b_start, l_low, 1000);
    band_start->setPen(QPen(Qt::red, 2, Qt::SolidLine));

    band_stop->setRawSamples(b_stop, l_low, 1000);
    band_stop->setPen(QPen(Qt::red, 2, Qt::SolidLine));


    band_start_max->setRawSamples(b_start_max, l_high, 1000);
    band_start_max->setPen(QPen(Qt::red, 2, Qt::DotLine));

    band_stop_max->setRawSamples(b_stop_max, l_high, 1000);
    band_stop_max->setPen(QPen(Qt::red, 2, Qt::DotLine));

    for (i = 0; i < 1000; i++){
        l_low_2[i]  = (double) a_min;
        l_high_2[i] = (double) a_max;

        rangeband[i] = (double) band;

        if (band < f_max) band++;
    }

    lim_l->setRawSamples(rangeband, l_low_2, 1000);
    lim_l->setPen(QPen(Qt::red, 2, Qt::SolidLine));

    lim_h->setRawSamples(rangeband, l_high_2, 1000);
    lim_h->setPen(QPen(Qt::red, 2, Qt::DotLine));


    /* attach band alarm */
    band_start->attach(plot);
    band_stop->attach(plot);
    band_start_max->attach(plot);
    band_stop_max->attach(plot);

    lim_l->attach(plot);
    lim_h->attach(plot);

    plot->replot();
#endif
}
