#include "mythread.h"

extern struct d_global global;

MyThread::MyThread()
{
}

void MyThread::run()
{
    base->save_database_waveform(global.db, bb0, bb1, bb2, bb3, num, fmax, &ref_rpm[0]);
}

TrThread::TrThread()
{
}

void TrThread::run()
{
    tbase->save_database_trend_wave(global.db, &rms[0], &peakmin[0], &peakmax[0], &crest_factor[0]);
    tbase->save_database_trend_spek(global.db, &rms_spek[0], &peakmax_spek[0]);
}
