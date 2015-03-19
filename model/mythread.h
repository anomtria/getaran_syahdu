#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>
#include <QDebug>

#include "util/setting.h"
#include "controller/save_db.h"

class MyThread : public QThread
{
public:
    MyThread();
    save_db *base;

    void run();

    QByteArray bb0;
    QByteArray bb1;
    QByteArray bb2;
    QByteArray bb3;
    int num;
    int fmax;
    int ref_rpm[JUM_KANAL];
};

class TrThread : public QThread
{
public:
    TrThread();
    save_db *tbase;

    void  run();

    double rms[JUM_PLOT];
    double peakmin[JUM_PLOT];
    double peakmax[JUM_PLOT];
    double crest_factor[JUM_PLOT];

    double rms_spek[JUM_PLOT];
    double peakmax_spek[JUM_PLOT];
};

#endif // MYTHREAD_H
