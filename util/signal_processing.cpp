#include "signal_processing.h"

Signal_processing::Signal_processing()
{
}

int Signal_processing::sin_waveform_dummy(int s_rate, float frek, float amplitudo, float fasa, float *sinout, int pjg)
{
    int i;
    int periode;

    periode = (int) ((s_rate * 1.0)/frek);

    int offset;

    offset = (int) ((fasa/360.00) * periode);

    if (offset < 0) offset = 0;
    if (fasa == 0) offset = 0;

    double t;
    double d_frek = frek;
    double d_amplitudo = amplitudo;
    double d_offset = offset;
    float temp_kotak;

    for (i = 0; i < pjg; i++){
        t = ((double)i + d_offset) / (double) s_rate;
        t *= -1.0;

        sinout[i] += (float)(d_amplitudo * sin(2.00 * M_PI * d_frek * t));
    }

    return periode;
}
