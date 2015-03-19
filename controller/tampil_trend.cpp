#include "tampil_trend.h"

tampil_trend::tampil_trend()
{
}

void tampil_trend::show_trend(QwtPlot *plot, QwtPlotCurve *kurva, double *peak, double *time, int len){
    kurva->setRawSamples(time, peak, len);
    kurva->attach(plot);

    this->set_scale(plot, len);

    plot->replot();
}

void tampil_trend::set_scale(QwtPlot *plot, int len){

}
