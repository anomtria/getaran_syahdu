#include "form_replay.h"
#include "ui_form_replay.h"

extern struct d_global global;

Form_Replay::Form_Replay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_Replay)
{
    ui->setupUi(this);

    f_note = new Form_Note();
    f_note->setWindowTitle("Catatan");
}

Form_Replay::~Form_Replay()
{
    if (sudah_free == false){
        this->free_memory_replay();
        delete tim;
    }
    delete ui;    
}

void Form_Replay::init_grafik(t_setting *setting)
{
    int i;

    for (i = 0; i < JUM_PLOT; i++){
        p_replay[i] = new plot_replay();
        HL[i] = new QHBoxLayout();

        if (i == 0) {ui->VL1->addLayout(HL[i]);}
        else if (i == 1) {ui->VL2->addLayout(HL[i]);}
        else if (i == 2) {ui->VL3->addLayout(HL[i]);}
        else if (i == 3) {ui->VL4->addLayout(HL[i]);}
        else if (i == 4) {ui->VL5->addLayout(HL[i]);}
        else if (i == 5) {ui->VL6->addLayout(HL[i]);}
        else if (i == 6) {ui->VL7->addLayout(HL[i]);}
        else if (i == 7) {ui->VL8->addLayout(HL[i]);}

        s_graph->create_grafik(HL[i], p_replay[i], &kurva[i], setting, 0.00, 0.00, 0.00, i);
    }
}

void Form_Replay::init_timer(){
    tim = new QTimer();
    QObject::connect(this->tim, SIGNAL(timeout()), this, SLOT(refresh_plot()));
    tim->stop();
}

void Form_Replay::init_default_value(){
    flag_auto_w = 0;
    flag_auto_s = 0;
    x_axis_index_w = 0;
    y_axis_index_w = 0;
    x_axis_index_s = 0;
    y_axis_index_s = 0;
    window_index = 0;

    min_y_scale_w = 0.00;
    max_y_scale_w = 0.00;
    min_y_scale_s = 0.00;
    max_y_scale_s = 0.00;

    max_x_scale_w = 1000.00;
    max_x_scale_s = 1000.00;

    sudah_free = true;

    index = 0;
    index_window = 100; // --> hanya pancingan agar gen window sekali di awal
    interval = 100;
}

void Form_Replay::init_user_interface(){
    this->ui->pb_play->setFlat(true);
    this->ui->pb_pause->setFlat(true);
    this->ui->pb_note->setFlat(true);
    this->ui->pb_close->setFlat(true);

    this->ui->rad_auto_w->setChecked(true);
    this->ui->rad_auto_s->setChecked(true);

    this->ui->sb_y_min_w->setText(QString::number(min_y_scale_w, 'g', 3));
    this->ui->sb_y_max_w->setText(QString::number(max_y_scale_w, 'g', 3));

    this->ui->sb_y_min_w->setEnabled(false);
    this->ui->sb_y_max_w->setEnabled(false);


    this->ui->sb_y_min_s->setText(QString::number(min_y_scale_s, 'g', 3));
    this->ui->sb_y_max_s->setText(QString::number(max_y_scale_s, 'g', 3));

    this->ui->sb_y_min_s->setEnabled(false);
    this->ui->sb_y_max_s->setEnabled(false);

    this->ui->combo_x_w->setCurrentIndex(x_axis_index_w);
    this->ui->combo_y_w->setCurrentIndex(y_axis_index_w);

    this->ui->combo_x_s->setCurrentIndex(x_axis_index_s);
    this->ui->combo_y_s->setCurrentIndex(y_axis_index_s);

    this->ui->window->setCurrentIndex(window_index);

    this->ui->dtime_to->setDateTime(QDateTime::currentDateTime());

    bool cek;
    cek = get->check_data_exist(global.db);
    qDebug() << cek;
    if (cek == true){
        qDebug() << cek;

        QSqlQuery q(global.db);

        QString query;
        QString date;

        query.sprintf("select year, month, day, hour, min from waveform_ch1 where id = 1");
        proses_q(&q, query.toAscii().data());

        int year = q.value(0).toInt();
        int month = q.value(1).toInt();
        int day = q.value(2).toInt();
        int hour = q.value(3).toInt();
        int min = q.value(4).toInt();

        date.sprintf("%d %d %d %d:%d:00", year, month, day, hour, min);
        this->ui->dtime_from->setDateTime(QDateTime::fromString(date, "yyyy MM dd hh:mm:ss"));
    }
    else{

    }
}

void Form_Replay::init_memory_replay(){
    for (int i = 0; i < JUM_KANAL; i++){
        sb_y_wave[i] = (double *) malloc( (MAX_LEN_DATA) * sizeof(double));
        memset( (char *) sb_y_wave[i], 0, (MAX_LEN_DATA) * sizeof(double));

        fft_magt[i] = (double *) malloc(MAX_LEN_DATA * sizeof(double));
        memset((char *) fft_magt[i], 0, (MAX_LEN_DATA * sizeof(double)));
    }

    sb_x_wave = (double *) malloc( (MAX_LEN_DATA) * sizeof(double));
    memset( (char *) sb_x_wave, 0, (MAX_LEN_DATA) * sizeof(double));

    sb_x_spek = (double *) malloc( (MAX_LEN_DATA) * sizeof(double));
    memset( (char *) sb_x_spek, 0, (MAX_LEN_DATA) * sizeof(double));

    win_coef = (double *) malloc(MAX_LEN_DATA * sizeof(double));
    memset((char *) win_coef, 0, (MAX_LEN_DATA * sizeof(double)));


    hasil_windowing = (double *) malloc(MAX_LEN_DATA * sizeof(double));
    memset((char *) hasil_windowing, 0, (MAX_LEN_DATA * sizeof(double)));

    fft_re_out = (double *) malloc(MAX_LEN_DATA * sizeof(double));
    memset((char *) fft_re_out, 0, (MAX_LEN_DATA * sizeof(double)));

    fft_im_out = (double *) malloc(MAX_LEN_DATA * sizeof(double));
    memset((char *) fft_im_out, 0, (MAX_LEN_DATA * sizeof(double)));
}

void Form_Replay::free_memory_replay(){
    for (int i = 0; i < JUM_KANAL; i++){
        free(sb_y_wave[i]);
        free(fft_magt[i]);
    }

    free(sb_x_wave);
    free(sb_x_spek);
    free(win_coef);

    free(hasil_windowing);
    free(fft_re_out);
    free(fft_im_out);
}

void Form_Replay::refresh_plot(){
    index++;
    float* data;

    for (int i = 0; i < JUM_KANAL; i++){
        memset((char *) sb_y_wave[i], 0, MAX_LEN_DATA * sizeof(double));
    }
    memset((char *) sb_x_wave, 0, MAX_LEN_DATA * sizeof(double));

    for (int i = 0; i < JUM_KANAL; i++){
        bb = get->get_data_waveform(global.db, i, index);
        sample = get->get_numsample_waveform(global.db, i, index);
        fmax = get->get_f_max_waveform(global.db, i, index);
        ref_rpm = get->get_ref_rpm_waveform(global.db, i, index);

        data = (float *) bb.data();

        for (int n = 0; n < sample; n++){
            sb_y_wave[i][n] = (double) data[n];
            sb_x_wave[n] = n;
        }

        if (index_window != this->ui->window->currentIndex()){
            tampil->gen_window_coef(sample, win_coef, this->ui->window->currentIndex());
            index_window = this->ui->window->currentIndex();
        }

        double line = (double) sample / (double) 2.56;

        if(this->ui->combo_x_s->currentIndex() == 0){
            resolusi = (double) tampil->resolusi_line_to_hz((double) line, (double) fmax);
            interval = (double) 100.00;
        }
        else if(this->ui->combo_x_s->currentIndex() == 1){
            resolusi = (double) tampil->resolusi_line_to_cpm((double) line, (double) fmax);
            interval = (double) ref_rpm;
        }
        else{
            resolusi = (double) tampil->resolusi_line_to_order((double) line, (double) fmax, (double) ref_rpm);
            interval = (double) 1.00;
        }
        max_x_scale_s = (double) (10.00 * (double) interval);

        tampil->show_replay(p_replay[i], &kurva[i], &sb_y_wave[i][0], &sb_x_wave[0], sample, flag_auto_w, min_y_scale_w, max_y_scale_w, max_x_scale_w, 0);

        tampil->proses_ftt(&sb_y_wave[i][0], &sb_x_spek[0], win_coef, hasil_windowing, sample, &fft_re_out[0], &fft_im_out[0], &fft_magt[i][0], resolusi);
        tampil->show_replay(p_replay[i+4], &kurva[i+4], &fft_magt[i][0], &sb_x_spek[0], sample/2, flag_auto_s, min_y_scale_s, max_y_scale_s, max_x_scale_s, interval);
    }
}

void Form_Replay::on_pb_play_clicked()
{
    /* coba 0.4 second ..
       data real update dalam 0.1 second, tapi periode penyimpanan di set
       setiap 4 second.

       masih hardcode = 0.1 * 4 = 0.4s. */

    if (!tim->isActive()){
        this->ui->pb_play->setIcon(QIcon(":icon/icon_stop.png"));
        //this->ui->actionRun->setToolTip("Stop");

        this->init_memory_replay();
        tim->start(400);

        sudah_free = false;
    }
    else{
        this->ui->pb_play->setIcon(QIcon(":icon/icon_play.png"));
        //this->ui->actionRun->setToolTip("Run");

        tim->stop();

        this->free_memory_replay();
        sudah_free = true;
    }

    //int num = get->get_num_data(global.db, 0, "trend_wave");
    int f_id = get->get_id_from_dtime(global.db, 0, "waveform", dtime_form_year, dtime_form_month, dtime_form_day, dtime_form_hour, dtime_form_min);
}

void Form_Replay::on_pb_pause_clicked()
{

}

void Form_Replay::on_pb_note_clicked()
{
    f_note->move(400, 100);
    f_note->show();
}

void Form_Replay::on_pb_close_clicked()
{
    this->close();
}

void Form_Replay::on_dtime_from_dateTimeChanged(const QDateTime &date)
{
    dtime_form_sec   = date.toString("ss").toInt();
    dtime_form_min   = date.toString("mm").toInt();
    dtime_form_hour  = date.toString("hh").toInt();
    dtime_form_day   = date.toString("dd").toInt();
    dtime_form_month = date.toString("MM").toInt();
    dtime_form_year  = date.toString("yyyy").toInt();
}

void Form_Replay::on_dtime_to_dateTimeChanged(const QDateTime &date)
{
    dtime_to_sec   = date.toString("ss").toInt();
    dtime_to_min   = date.toString("mm").toInt();
    dtime_to_hour  = date.toString("hh").toInt();
    dtime_to_day   = date.toString("dd").toInt();
    dtime_to_month = date.toString("MM").toInt();
    dtime_to_year  = date.toString("yyyy").toInt();
}

void Form_Replay::on_rad_fix_s_clicked()
{
    this->ui->rad_auto_s->setChecked(false);
    this->ui->rad_fix_s->setChecked(true);

    this->ui->sb_y_min_s->setEnabled(true);
    this->ui->sb_y_max_s->setEnabled(true);
}

void Form_Replay::on_rad_auto_s_clicked()
{
    this->ui->rad_auto_s->setChecked(true);
    this->ui->rad_fix_s->setChecked(false);

    this->ui->sb_y_min_s->setEnabled(false);
    this->ui->sb_y_max_s->setEnabled(false);
}

void Form_Replay::on_rad_fix_w_clicked()
{
    this->ui->rad_auto_w->setChecked(false);
    this->ui->rad_fix_w->setChecked(true);

    this->ui->sb_y_min_w->setEnabled(true);
    this->ui->sb_y_max_w->setEnabled(true);
}

void Form_Replay::on_rad_auto_w_clicked()
{
    this->ui->rad_auto_w->setChecked(true);
    this->ui->rad_fix_w->setChecked(false);

    this->ui->sb_y_min_w->setEnabled(false);
    this->ui->sb_y_max_w->setEnabled(false);
}
