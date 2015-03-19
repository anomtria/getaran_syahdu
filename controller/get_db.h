#ifndef GET_DB_H
#define GET_DB_H

#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <stdio.h>
#include <math.h>

#include "util/setting.h"
#include "model/file_setting.h"

class get_db
{
public:
    get_db();

    QByteArray get_data_waveform(QSqlDatabase db, int ch, int index);
    int get_numsample_waveform(QSqlDatabase db, int ch, int index);
    int get_f_max_waveform(QSqlDatabase db, int ch, int index);
    int get_ref_rpm_waveform(QSqlDatabase db, int ch, int index);

    float get_data_trend(QSqlDatabase db, int ch, int index, QString tipe);
    float get_time_trend(QSqlDatabase db, int ch, int index, QString interval);


    bool check_data_exist(QSqlDatabase db);
    int  get_num_data(QSqlDatabase db, int ch, QString TableName);
    int  get_range_data(QSqlDatabase db, int ch, QString TableName);
    int  get_id_from_dtime(QSqlDatabase db, int ch, QString TableName, int year, int month, int day, int hour, int min);

    void get_firsttime(QSqlDatabase db, int year, int month, int day, int hour, int min);
};

#endif // GET_DB_H
