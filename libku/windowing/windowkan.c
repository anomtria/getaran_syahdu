/*

 windowkan

 melakukan konvolusi (perkalian) antara sinyal
 dengan koefisien window filter

 furkan jadid
 4 Des 2012
 daun biru engineering

*/

#include "windowkan.h"

void windowkan(float *in, float *out, float *koef, int len)
{
    int i;

    for (i=0; i<=len; i++)
    {
        out[i] = in[i] * koef[i];
    }
}

void windowkand(double *in, double *out, double *koef, int len)
{
    int i;

    for (i=0; i<=len; i++)
    {
        out[i] = in[i] * koef[i];
    }
}
