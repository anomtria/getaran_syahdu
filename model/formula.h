#ifndef FORMULA_H
#define FORMULA_H

#include "math.h"
#include "util/setting.h"

#include <QDebug>

class formula
{
public:
    formula();

    /* Konversi */
    float resolusi_line_to_hz(int line, int fmax);
    float resolusi_line_to_cpm(int line, int fmax);
    float resolusi_line_to_order(int line, int fmax, int ref_rpm);

    double conv_line_to_hz(double line, int fmax);
    double conv_line_to_cpm(double line, int fmax);
    double conv_line_to_order(double line, int fmax, float reff_rpm);

    /* Generate Nilai */
    double gen_rms_wave(double *gelombang, int len);
    double gen_rms_spek(double *gelombang, int len);


    /* khusus untuk simpan trend -> tipe data float */
    float gen_rms_wave_trend(float *gelombang, int len);
    float gen_peakmin_wave_trend(float *gelombang, int len);
    float gen_peakmax_wave_trend(float *gelombang, int len);

    float gen_rms_spek_trend(float *gelombang, int len);
    float gen_peakmin_spek_trend(float *gelombang, int len);
    double gen_peakmax_spek_trend(double *gelombang, int len);


    int gen_index_peakmax(double *gelombang, int len);
};

#endif // FORMULA_H
