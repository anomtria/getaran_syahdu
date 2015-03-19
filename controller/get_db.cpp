#include "get_db.h"

get_db::get_db()
{
}

/* ----------------------- get tabel waveform ------------------------ */
QByteArray get_db::get_data_waveform(QSqlDatabase db, int ch, int index){
    QSqlQuery q(db);
    QByteArray bb;

    QString query;
    query.sprintf("select data from waveform_ch%d where id = %d", ch+1, index);

    proses_q(&q, query.toAscii().data());

    bb = q.value(0).toByteArray();

    return (QByteArray) bb;
}

int get_db::get_numsample_waveform(QSqlDatabase db, int ch, int index){
    QSqlQuery q(db);
    int sample;

    QString query;
    query.sprintf("select numsample from waveform_ch%d where id = %d", ch+1, index);

    proses_q(&q, query.toAscii().data());

    sample = q.value(0).toInt();

    return (int) sample;
}

int get_db::get_f_max_waveform(QSqlDatabase db, int ch, int index){
    QSqlQuery q(db);
    int fmax;

    QString query;
    query.sprintf("select fmax from waveform_ch%d where id = %d", ch+1, index);

    proses_q(&q, query.toAscii().data());

    fmax = q.value(0).toInt();

    return (int) fmax;
}

int get_db::get_ref_rpm_waveform(QSqlDatabase db, int ch, int index){
    QSqlQuery q(db);
    int ref_rpm;

    QString query;
    query.sprintf("select ref_rpm from waveform_ch%d where id = %d", ch+1, index);

    proses_q(&q, query.toAscii().data());

    ref_rpm = q.value(0).toInt();

    return (int) ref_rpm;
}


/* --------------------- get tabel trend waveform --------------------- */
float get_db::get_data_trend(QSqlDatabase db, int ch, int index, QString tipe){
    QSqlQuery q(db);
    float peak;

    QString query;
    if (ch < 4){
        query.sprintf("select %s from trend_wave_ch%d where id = %d", tipe.toAscii().data(), ch+1, index+1);
    }
    else{
        query.sprintf("select %s from trend_spek_ch%d where id = %d", tipe.toAscii().data(), ch-3, index+1);
    }
    proses_q(&q, query.toAscii().data());

    if (tipe == TREND_PEAKTOPEAK){
        peak = q.value(0).toFloat() + q.value(1).toFloat();
    }
    else{
        peak = q.value(0).toFloat();
    }

    return (float) peak;
}

float get_db::get_time_trend(QSqlDatabase db, int ch, int index, QString interval){
    QSqlQuery q(db);
    float time;

    QString query;
    if (ch < 4){
        query.sprintf("select %s from trend_wave_ch%d where id = %d", interval.toAscii().data(), ch+1, index+1);
    }
    else{
        query.sprintf("select %s from trend_spek_ch%d where id = %d", interval.toAscii().data(), ch-3, index+1);
    }

    proses_q(&q, query.toAscii().data());
    time = q.value(0).toInt();

    return (float) time;
}



/* ------------------------ get num data from table ----------------------- */
bool get_db::check_data_exist(QSqlDatabase db){
    QSqlQuery q(db);
    bool cek;

    QString query;
    query.sprintf("select id from waveform_ch1");

    proses_q(&q, query.toAscii().data());
    if (!q.exec()){
        qDebug() << "error";
        cek = false;
    }
    else{
        while (q.next()){
            cek = true;
            break;
        }
    }
    return (bool) cek;
}

void get_db::get_firsttime(QSqlDatabase db, int year, int month, int day, int hour, int min){
    QSqlQuery q(db);

    QString query;

    query.sprintf("select year, month, day, hour, min from waveform_ch1 where id = 1");
    proses_q(&q, query.toAscii().data());

    year = q.value(0).toInt();
    month = q.value(1).toInt();
    day = q.value(2).toInt();
    hour = q.value(3).toInt();
    min = q.value(4).toInt();
}

int get_db::get_num_data(QSqlDatabase db, int ch, QString TableName){
    QSqlQuery q(db);
    int num = 0;

    QString query;

    query.sprintf("select count(*) from %s_ch%d where id > 5 and id < 1000", TableName.toAscii().data(), ch+1);

    proses_q(&q, query.toAscii().data());
    num = q.value(0).toInt();

    return (int) num;
}

int get_db::get_range_data(QSqlDatabase db, int ch, QString TableName){
    QSqlQuery q(db);
    qDebug() << ch << TableName.toAscii().data();
}

int get_db::get_id_from_dtime(QSqlDatabase db, int ch, QString TableName, int year, int month, int day, int hour, int min){
    QSqlQuery q(db);
    int id;

    QString query;

    query.sprintf("select id from %s_ch%d where year=%d and month=%d and day=%d and hour=%d and min=%d", TableName.toAscii().data(), ch+1,
                  year, month, day, hour, min);
    proses_q(&q, query.toAscii().data());
    if (!q.exec()){
        qDebug() << "error";
    }
    else{
        while(q.next()){
            id = q.value(0).toInt();
            break;
        }
    }
    return (int) id;
}
