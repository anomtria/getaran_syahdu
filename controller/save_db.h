#ifndef SAVE_DB_H
#define SAVE_DB_H

#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <stdio.h>

#include "util/setting.h"
#include "model/file_setting.h"

class save_db
{
public:
    save_db();

    void save_database_note(QSqlDatabase db, int kind, QString opt, QString judul, int tipe_data, int ch, QString note);
    void save_database_waveform(QSqlDatabase db, QByteArray bb0, QByteArray bb1, QByteArray bb2, QByteArray bb3, int num, int fmax,  int ref_rpm[JUM_KANAL]);
    void save_database_trend_wave(QSqlDatabase db, double rms[JUM_KANAL], double peakmin[JUM_KANAL], double peakmax[JUM_KANAL], double crest_factor[JUM_KANAL]);
    void save_database_trend_spek(QSqlDatabase db, double rms[JUM_KANAL], double peak[JUM_KANAL]);
};

#endif // SAVE_DB_H
