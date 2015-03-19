#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <stdio.h>

#include "model/file_setting.h"

class database
{
public:
    database();

    void create_database_awal(QSqlQuery *q, int driver );

    void check_db_exist(QString fileName, int count_db);
    void create_database(QString fileName, int count_db);
    void load_database(QString fileName, int count_db);

    void create_tabel_wavefrom(QSqlQuery *q, int driver);
    void create_tabel_trend_waveform(QSqlQuery *q, int driver);
    void create_tabel_trend_spektrum(QSqlQuery *q, int driver);
    void create_tabel_note(QSqlQuery *q, int driver);
};

#endif // DATABASE_H
