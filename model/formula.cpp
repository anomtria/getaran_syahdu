#include "formula.h"

formula::formula()
{
}

/* nilai resolusinya saja */
float formula::resolusi_line_to_hz(int line, int fmax){
    float res;
    res = (float) ((float) (fmax / line) );

    return (float) res;
}

float formula::resolusi_line_to_cpm(int line, int fmax){
    float res;
    res = (float) ((float) (fmax / line));
    res = (float) res * (float) (60.0);

    return (float) res;
}

float formula::resolusi_line_to_order(int line, int fmax, int ref_rpm){
    float res;
    res = (float) ((float) (fmax / line));
    res = (float) ((float) res / (float)((float) ref_rpm / (float) 60.00));

    return (float) res;
}


/* sudah dalam nilai conversi */
double formula::conv_line_to_hz(double line, int fmax){
    /* Konversi satuan dari bentuk line_spektrum
       ke bentuk Hertz (Hz) */

    float temp;
    temp = (double) ((double) (fmax / line));

    return (double) temp;
}

double formula::conv_line_to_cpm(double line, int fmax){
    /* Konversi satuan dari bentuk line_spektrum
       ke bentuk cycle per minute (cpm) :

       cpm = (Hz * 60) */

    float temp;
    temp = (double) ((double) (fmax / line));
    temp = (double) temp * (double) (60.00);

    return (double) temp;
}

double formula::conv_line_to_order(double line, int fmax, float reff_rpm){
    /* Konversi satuan dari bentuk line_spektrum
       ke bentuk cycle per minute (cpm) :

       (order = Hz * (ref_rpm/60)) */

    float temp;
    temp = (double) ((double) (fmax/line));
    temp = (double) ((double) temp / (double) ((double) reff_rpm / (double) 60.00));

    return (double) temp;
}

double formula::gen_rms_wave(double *gelombang, int len){
    /* generate nilai rms untuk waveform, analog rms */

    double temp = 0.00;
    double rms = 0.00;

    for (int i = 0; i < len; i++){
        temp += (double)(gelombang[i] * gelombang[i]);
    }
    rms = sqrt(temp/len);

    return (double) rms;
}

double formula::gen_rms_spek(double *gelombang, int len){
    /* generate nilai rms untuk spektrum, digital rms */

    double temp = 0.00;
    double rms = 0.00;

    for (int i = 0; i < len; i++){
        temp += (double) (gelombang[i] * gelombang[i]);
    }

    //rms = (double) (0.8165 * (sqrt(temp/len)));
    rms = (double) (0.8165) * sqrt(temp);

    return (double) rms;
}


/* ----------------------------------------------------------------- */


/* keperluan simpan trend -> "simpan dalam tipe data float" */
float formula::gen_rms_wave_trend(float *gelombang, int len){
    /* generate nilai rms untuk waveform */

    float temp = 0.00;
    float rms = 0.00;

    for (int i = 0; i < len; i++){
        temp += (float)(gelombang[i] * gelombang[i]);
    }
    rms = sqrt(temp/len);

    return (float) rms;
}

float formula::gen_peakmin_wave_trend(float *gelombang, int len){
    float temp = 10000.00;

    for (int i = 0; i < len; i++){
        if (gelombang[i] < temp){
            temp = gelombang[i];
        }
    }

    return (float) temp;
}

float formula::gen_peakmax_wave_trend(float *gelombang, int len){
    float temp = 0.00;

    for (int i = 0; i < len; i++){
        if (gelombang[i] > temp){
            temp = gelombang[i];
        }
    }

    return (float) temp;
}



float formula::gen_rms_spek_trend(float *gelombang, int len){
    /* generate nilai rms untuk spektrum */

    float temp = 0.00;
    float rms = 0.00;

    for (int i = 0; i < len; i++){
        if (gelombang[i] > temp){
            temp = gelombang[i];
        }
    }

    rms = (float) (temp / sqrt(2.00));

    return (float) rms;
}

float formula::gen_peakmin_spek_trend(float *gelombang, int len){
    float temp = 10000.00;

    for (int i = 0; i < len; i++){
        if (gelombang[i] < temp){
            temp = gelombang[i];
        }
    }

    return (float) temp;
}

double formula::gen_peakmax_spek_trend(double *gelombang, int len){
    double temp = 0.00;

    for (int i = 0; i < len; i++){
        if (gelombang[i] > temp){
            temp = gelombang[i];
        }
    }

    return (double) temp;
}

int formula::gen_index_peakmax(double *gelombang, int len){
    double temp = 0.00;
    int index = 0;

    for (int i = 0; i < len; i++){
        if (gelombang[i] > temp){
            temp = gelombang[i];
            index = i;
        }
    }

    return (int) index;
}
