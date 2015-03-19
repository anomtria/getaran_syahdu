#include "form_trend.h"
#include "ui_form_trend.h"

extern struct d_global global;

Form_Trend::Form_Trend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Trend)
{
    ui->setupUi(this);

    f_note = new Form_Note();
    f_note->setWindowTitle("Catatan");

    len = 0;

    this->ui->dtime_from->setDateTime(QDateTime::currentDateTime());
    this->ui->dtime_to->setDateTime(QDateTime::currentDateTime());

    sudah_set = false;

    this->ui->pb_gen->setFlat(true);
    this->ui->pb_note->setFlat(true);
    this->ui->pb_close->setFlat(true);
}

Form_Trend::~Form_Trend()
{
    if (sudah_set == true){
        this->free_memory_trend();
    }

    delete ui;
}

void Form_Trend::showEvent(QShowEvent *)
{
    qDebug("%s:", __FUNCTION__);
}

void Form_Trend::init_grafik(t_setting *setting)
{   
    int i;

    for (i = 0; i < JUM_PLOT; i++){
        p_trend[i] = new plot_trend();
        HL[i] = new QHBoxLayout();

        if (i == 0) {ui->VL1->addLayout(HL[i]);}
        else if (i == 1) {ui->VL2->addLayout(HL[i]);}
        else if (i == 2) {ui->VL3->addLayout(HL[i]);}
        else if (i == 3) {ui->VL4->addLayout(HL[i]);}
        else if (i == 4) {ui->VL5->addLayout(HL[i]);}
        else if (i == 5) {ui->VL6->addLayout(HL[i]);}
        else if (i == 6) {ui->VL7->addLayout(HL[i]);}
        else if (i == 7) {ui->VL8->addLayout(HL[i]);}

        s_graph->create_grafik(HL[i], p_trend[i], &kurva[i], setting, 0.00, 0.00, 0.00, i);
    }
}

void Form_Trend::on_pb_note_clicked()
{
    f_note->show();
}

void Form_Trend::on_pb_gen_clicked()
{
    if (sudah_set == false){
        this->set_memory_trend();

        sudah_set = true;
    }

    int n;
    double temp = 0.00;

    len = 10;

    for (int i = 0; i < JUM_PLOT; i++){
        n = 0;
        temp = 0;

        memset((char *) peaks[i], 0, (MAX_LEN_DATA * sizeof(double)));
        memset((char *) times[i], 0, (MAX_LEN_DATA * sizeof(double)));

        for (int x = 0; x < len; x++){
            peaks[i][n] = (double) get->get_data_trend(global.db, i, x, TREND_RMS);
            times[i][n] = (double) temp + get->get_time_trend(global.db, i, x, SEC);

            temp = times[i][n];

            n++;
        }
        tampil->show_trend(p_trend[i], &kurva[i], &peaks[i][0], &times[i][0], len);
    }
}

void Form_Trend::on_pb_close_clicked()
{
    this->close();
}

void Form_Trend::on_dtime_from_dateTimeChanged(const QDateTime &date)
{
    dtime_form_sec   = date.toString("ss").toInt();
    dtime_form_min   = date.toString("mm").toInt();
    dtime_form_hour  = date.toString("hh").toInt();
    dtime_form_day   = date.toString("DD").toInt();
    dtime_form_month = date.toString("MM").toInt();
    dtime_form_year  = date.toString("YYYY").toInt();
}

void Form_Trend::on_dtime_to_dateTimeChanged(const QDateTime &date)
{
    dtime_to_sec   = date.toString("ss").toInt();
    dtime_to_min   = date.toString("mm").toInt();
    dtime_to_hour  = date.toString("hh").toInt();
    dtime_to_day   = date.toString("DD").toInt();
    dtime_to_month = date.toString("MM").toInt();
    dtime_to_year  = date.toString("YYYY").toInt();
}

void Form_Trend::set_memory_trend(){
    for (int i = 0; i < JUM_KURVA; i++){
        peaks[i] = (double *) malloc(MAX_LEN_DATA * sizeof(double));
        memset((char *) peaks[i], 0, (MAX_LEN_DATA * sizeof(double)));

        times[i] = (double *) malloc(MAX_LEN_DATA * sizeof(double));
        memset((char *) times[i], 0, (MAX_LEN_DATA * sizeof(double)));
    }
}

void Form_Trend::free_memory_trend(){
    for (int i = 0; i < JUM_KURVA; i++){
        free(peaks[i]);
        free(times[i]);
    }
}
