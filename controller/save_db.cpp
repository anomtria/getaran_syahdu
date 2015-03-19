#include "save_db.h"

save_db::save_db()
{
}

/* ------------------ save database ------------------- */
void save_db::save_database_note(QSqlDatabase db, int kind, QString opt, QString judul, int tipe_data, int ch, QString note)
{
    QSqlQuery q(db);

    q.prepare("insert into note (kind, opt, judul, tipe_data, ch, note) values (:kind, :opt, :judul, :tipe_data, :ch, :note)");
    q.bindValue(":kind", kind);
    q.bindValue(":opt", opt.toAscii().data());
    q.bindValue(":judul", judul.toAscii().data());
    q.bindValue(":tipe_data", tipe_data);
    q.bindValue(":ch", ch);
    q.bindValue(":note", note.toAscii().data());
    q.exec();
}

void save_db::save_database_waveform(QSqlDatabase db, QByteArray bb0, QByteArray bb1, QByteArray bb2, QByteArray bb3, int num, int fmax, int ref_rpm[JUM_KANAL])
{
    QSqlQuery q(db);

    QString query;

    for (int i = 0; i < JUM_KANAL; i++){
        query.sprintf("insert into waveform_ch%d (data, numsample, fmax, ref_rpm) values(:data, :numsample, :fmax, :ref_rpm)", i+1);
        q.prepare(query);

        if(i == 0){
            q.bindValue(":data", bb0);
        }
        else if (i == 1){
            q.bindValue(":data", bb1);
        }
        else if (i == 2){
            q.bindValue(":data", bb2);
        }
        else{
            q.bindValue(":data", bb3);
        }
        q.bindValue(":numsample", num);
        q.bindValue(":fmax", fmax);
        q.bindValue(":ref_rpm", ref_rpm[i]);

        q.exec();
    }
}

void save_db::save_database_trend_wave(QSqlDatabase db, double rms[JUM_KANAL], double peakmin[JUM_KANAL], double peakmax[JUM_KANAL], double crest_factor[JUM_KANAL])
{
    QSqlQuery q(db);

    QString query;

    for (int i = 0; i < JUM_KANAL; i++){
        query.sprintf("insert into trend_wave_ch%d (rms, peakmin, peakmax, crest_factor) values(:rms, :peakmin, :peakmax, :crest_factor)", i+1);
        q.prepare(query);

        q.bindValue(":rms", (float) rms[i]);
        q.bindValue(":peakmin", (float) peakmin[i]);
        q.bindValue(":peakmax", (float) peakmax[i]);
        q.bindValue(":crest_factor", (float) crest_factor[i]);

        q.exec();
    }
}

void save_db::save_database_trend_spek(QSqlDatabase db, double rms[JUM_KANAL], double peak[JUM_KANAL])
{
    QSqlQuery q(db);

    QString query;

    for (int i = 0; i < JUM_KANAL; i++){
        query.sprintf("insert into trend_spek_ch%d (rms, peak) values(:rms, :peak)", i+1);
        q.prepare(query);

        q.bindValue(":rms", (float) rms[i]);
        q.bindValue(":peak", (float) peak[i]);

        q.exec();
    }
}
