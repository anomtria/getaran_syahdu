#ifndef WINDOWKAN_H
#define WINDOWKAN_H

#ifdef __cplusplus
extern "C" {
#endif

void windowkan(float *in, float *out, float *koef, int len);
void windowkand(double *in, double *out, double *koef, int len);

#ifdef __cplusplus
}
#endif

#endif // WINDOWKAN_H
