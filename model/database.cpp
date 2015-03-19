#include "database.h"

struct d_global global;

database::database()
{

}

/* ------------- check existing db QSQLITE ----------------*/
void database::check_db_exist(QString fileName, int count_db){
    QFile file(fileName);

    if (file.exists() == true){
        this->load_database(fileName, count_db++);
    }
    else{
        return;
    }
}

/* ----------------- create database ----------------------*/
void database::create_database(QString fileName, int count_db)
{
#if 1
    QString con_name;
    con_name.sprintf("LOC_DB%d", count_db++);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", con_name);
    db.setDatabaseName(fileName+".ovm"); //tambah ekstensi ".ovm" pada nama database

    if (!db.open())
    {
        qDebug() << "db corrupt!";
        return;
    }
    else
    {
        QSqlQuery query( db );
        create_database_awal(&query, SQLITE);
        query.finish();

        global.db = db;
    }
#endif
}

void database::load_database(QString fileName, int count_db)
{
    QString con_name;
    con_name.sprintf("LOC_DB%d", count_db++);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", con_name);
    db.setDatabaseName(fileName);

    if (!db.open()){
        qDebug() << "db corupt!";
        return;
    }
    else{
        global.db = db;
    }
}


/* ----------------- create table ----------------------*/
void database::create_database_awal(QSqlQuery *q, int driver){
    create_tabel_wavefrom(q, driver);
    create_tabel_trend_waveform(q, driver);
    create_tabel_trend_spektrum(q, driver);
    create_tabel_note(q, driver);
}

void database::create_tabel_wavefrom(QSqlQuery *q, int driver)
{
    int i;
    QString query;

    for (i = 0; i < JUM_KANAL; i++){
        query.sprintf("create table waveform_ch%d", i+1);
        q->prepare(query+ " (id integer primary key autoincrement, year DATETIME default(strftime('%Y', 'now', 'localtime')), \
                   month DATETIME default(strftime('%m', 'now', 'localtime')), day DATETIME default(strftime('%d', 'now', 'localtime')),\
                   hour DATETIME default(strftime('%H', 'now', 'localtime')), min DATETIME default(strftime('%M', 'now', 'localtime')),\
                   sec DATETIME default(strftime('%S', 'now', 'localtime')), data BLOB, numsample integer, fmax integer, ref_rpm integer)");
        q->exec();
    }
}

void database::create_tabel_trend_waveform(QSqlQuery *q, int driver){
    int i;
    QString query;

    for (i = 0; i < JUM_KANAL; i++){
        query.sprintf("create table trend_wave_ch%d", i+1);
        q->prepare(query+" (id integer primary key autoincrement, year DATETIME default(strftime('%Y', 'now', 'localtime')), \
                   month DATETIME default(strftime('%m', 'now', 'localtime')), day DATETIME default(strftime('%d', 'now', 'localtime')),\
                   hour DATETIME default(strftime('%H', 'now', 'localtime')), min DATETIME default(strftime('%M', 'now', 'localtime')),\
                   sec DATETIME default(strftime('%S', 'now', 'localtime')), rms float, peakmin float, peakmax float, crest_factor float)");
        q->exec();
    }
}

void database::create_tabel_trend_spektrum(QSqlQuery *q, int driver){
    int i;
    QString query;

    for (i = 0; i < JUM_KANAL; i++){
        query.sprintf("create table trend_spek_ch%d", i+1);
        q->prepare(query+" (id integer primary key autoincrement, year DATETIME default(strftime('%Y', 'now', 'localtime')), \
                   month DATETIME default(strftime('%m', 'now', 'localtime')), day DATETIME default(strftime('%d', 'now', 'localtime')),\
                   hour DATETIME default(strftime('%H', 'now', 'localtime')), min DATETIME default(strftime('%M', 'now', 'localtime')),\
                   sec DATETIME default(strftime('%S', 'now', 'localtime')), rms float, peak float)");
        q->exec();
    }
}

void database::create_tabel_note(QSqlQuery *q, int driver)
{
    int i;
    QString query;

    query.sprintf("create table note (id integer primary key autoincrement, year DATETIME default(strftime('%Y', 'now', 'localtime')), \
                  month DATETIME default(strftime('%m', 'now', 'localtime')), day DATETIME default(strftime('%d', 'now', 'localtime')),\
                  hour DATETIME default(strftime('%H', 'now', 'localtime')), min DATETIME default(strftime('%M', 'now', 'localtime')),\
                  sec DATETIME default(strftime('%S', 'now', 'localtime')), kind integer, opt varchar[64], judul varchar[64], tipe_data integer, ch integer, note varchar[256])");
    q->prepare(query);
    q->exec();
}
