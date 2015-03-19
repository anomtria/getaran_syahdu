#include "mainwindow.h"
#include "ui_mainwindow.h"

extern struct d_global global;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    count_db = 1;

    tipe_window_lama = 1;
    tipe_window = 1;

    /* Inisialisasi Timer */
    this->init_timer();

    /* Inisialisasi udpSocket */
    this->init_udpSocket();

    /* Inisialisasi Util PopUp Button */
    this->init_util_popup();

    /* Inisialisasi User Interface */
    this->init_UserInterface();

    setting = (struct t_setting *) malloc( sizeof (struct t_setting));
    memset( (char *) setting, 0, sizeof(struct t_setting));
    f_set->read_settings(setting);

    spektrum_points = 2.56 * setting->spek.line;

    /* Inisialisasi Grafik */
    init_grafik();

    /* check last_db ada apa kagak */
    dbase->check_db_exist(setting->db_setting.db_directory, count_db);

    cnt_ch1 = 0;
    cnt_ch2 = 0;
    cnt_ch3 = 0;
    cnt_ch4 = 0;

    cnt_save_spek = 0;

    this->ui->tabWidget->removeTab(3);
    this->ui->tabWidget->removeTab(2);

    this->set_memory();

    //sigpro->init_digital_filter();
    sigpro->gen_window_coef(setting, win_coef, spektrum_points);
}

MainWindow::~MainWindow()
{
    delete setting;
    this->free_memory();
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    QObject::connect(pop_copy_grafik[0], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard0()));
    QObject::connect(pop_copy_grafik[1], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard1()));
    QObject::connect(pop_copy_grafik[2], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard2()));
    QObject::connect(pop_copy_grafik[3], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard3()));
    QObject::connect(pop_copy_grafik[4], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard4()));
    QObject::connect(pop_copy_grafik[5], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard5()));
    QObject::connect(pop_copy_grafik[6], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard6()));
    QObject::connect(pop_copy_grafik[7], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard7()));
    QObject::connect(pop_copy_grafik[8], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard8()));
    QObject::connect(pop_copy_grafik[9], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard9()));
    QObject::connect(pop_copy_grafik[10], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard10()));
    QObject::connect(pop_copy_grafik[11], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard11()));
    QObject::connect(pop_copy_grafik[12], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard12()));
    QObject::connect(pop_copy_grafik[13], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard13()));
    QObject::connect(pop_copy_grafik[14], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard14()));
    QObject::connect(pop_copy_grafik[15], SIGNAL(triggered()), this, SLOT(copy_grafik_toclipboard15()));

    /* Band Analisis masih dalam 4 kanal */
    QObject::connect(pop_band_analisis[0], SIGNAL(triggered()), this, SLOT(overlay_band_ch1()));
    QObject::connect(pop_band_analisis[1], SIGNAL(triggered()), this, SLOT(overlay_band_ch2()));
    QObject::connect(pop_band_analisis[2], SIGNAL(triggered()), this, SLOT(overlay_band_ch3()));
    QObject::connect(pop_band_analisis[3], SIGNAL(triggered()), this, SLOT(overlay_band_ch4()));
    QObject::connect(pop_band_analisis[4], SIGNAL(triggered()), this, SLOT(overlay_band_ch5()));
    QObject::connect(pop_band_analisis[5], SIGNAL(triggered()), this, SLOT(overlay_band_ch6()));
    QObject::connect(pop_band_analisis[6], SIGNAL(triggered()), this, SLOT(overlay_band_ch7()));
    QObject::connect(pop_band_analisis[7], SIGNAL(triggered()), this, SLOT(overlay_band_ch8()));

    /* Peak Marker */
    QObject::connect(pop_peak[0], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch1()));
    QObject::connect(pop_peak[1], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch2()));
    QObject::connect(pop_peak[2], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch3()));
    QObject::connect(pop_peak[3], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch4()));
    QObject::connect(pop_peak[4], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch5()));
    QObject::connect(pop_peak[5], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch6()));
    QObject::connect(pop_peak[6], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch7()));
    QObject::connect(pop_peak[7], SIGNAL(triggered()), this, SLOT(show_peak_marker_ch8()));

    /* Harmonic Marker */
    QObject::connect(pop_harmonic[0], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch1()));
    QObject::connect(pop_harmonic[1], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch2()));
    QObject::connect(pop_harmonic[2], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch3()));
    QObject::connect(pop_harmonic[3], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch4()));
    QObject::connect(pop_harmonic[4], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch5()));
    QObject::connect(pop_harmonic[5], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch6()));
    QObject::connect(pop_harmonic[6], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch7()));
    QObject::connect(pop_harmonic[7], SIGNAL(triggered()), this, SLOT(show_harmonic_marker_ch8()));
}

void MainWindow::init_util_popup()
{
    this->setContextMenuPolicy(Qt::ActionsContextMenu);

    for(int i = 0; i < JUM_CURVE; i++){
        popMenu[i] = new QMenu(this);
        popMenu[i]->setContextMenuPolicy(Qt::ActionsContextMenu);

        pop_copy_grafik[i] = new QAction("Copy Grafik", popMenu[i]);
        pop_export_data[i] = new QAction("Export Data", popMenu[i]);

        popMenu[i]->addAction(pop_copy_grafik[i]);
        popMenu[i]->addAction(pop_export_data[i]);
    }

    for (int i = 0; i < JUM_PLOT; i++){
        popMenu_spektrum[i] = new QMenu(popMenu[i+8]);

        pop_spektrum_list[i] = new QAction("Spektrum List", popMenu[i+8]);
        pop_spektrum_list[i]->setMenu(popMenu_spektrum[i]);

        pop_separator[i] = new QAction("", popMenu[i+4]);
        pop_separator[i]->setSeparator(true);

        pop_peak[i] = new QAction("Peak", popMenu_spektrum[i]);
        pop_harmonic[i] = new QAction("Harmonics", popMenu_spektrum[i]);
        pop_separator_2[i] = new QAction("", popMenu[i+8]);
        pop_separator_2[i]->setSeparator(true);
        pop_band_analisis[i] = new QAction("Band Analisis", popMenu[i+8]);

        popMenu[i+8]->addAction(pop_separator[i]);

        popMenu[i+8]->addAction(pop_spektrum_list[i]);
        popMenu_spektrum[i]->addAction(pop_peak[i]);
        popMenu_spektrum[i]->addAction(pop_harmonic[i]);

        popMenu[i+8]->addAction(pop_separator_2[i]);
        popMenu[i+8]->addAction(pop_band_analisis[i]);
    }

    this->ui->pop1->setMenu(popMenu[0]);
    this->ui->pop2->setMenu(popMenu[1]);
    this->ui->pop3->setMenu(popMenu[2]);
    this->ui->pop4->setMenu(popMenu[3]);
    this->ui->pop5->setMenu(popMenu[4]);
    this->ui->pop6->setMenu(popMenu[5]);
    this->ui->pop7->setMenu(popMenu[6]);
    this->ui->pop8->setMenu(popMenu[7]);
    this->ui->pop9->setMenu(popMenu[8]);
    this->ui->pop10->setMenu(popMenu[9]);
    this->ui->pop11->setMenu(popMenu[10]);
    this->ui->pop12->setMenu(popMenu[11]);
    this->ui->pop13->setMenu(popMenu[12]);
    this->ui->pop14->setMenu(popMenu[13]);
    this->ui->pop15->setMenu(popMenu[14]);
    this->ui->pop16->setMenu(popMenu[15]);
}

void MainWindow::init_grafik()
{
    int i;

    for (i = 0; i < JUM_CURVE; i++){
        plot[i] = new main_graphic();
        HL[i] = new QHBoxLayout();

        if (i == 0) {ui->VL1->addLayout(HL[i]);}
        else if (i == 1) {ui->VL2->addLayout(HL[i]);}
        else if (i == 2) {ui->VL3->addLayout(HL[i]);}
        else if (i == 3) {ui->VL4->addLayout(HL[i]);}
        else if (i == 4) {ui->VL5->addLayout(HL[i]);}
        else if (i == 5) {ui->VL6->addLayout(HL[i]);}
        else if (i == 6) {ui->VL7->addLayout(HL[i]);}
        else if (i == 7) {ui->VL8->addLayout(HL[i]);}
        else if (i == 8) {ui->VL9->addLayout(HL[i]);}
        else if (i == 9) {ui->VL10->addLayout(HL[i]);}
        else if (i == 10) {ui->VL11->addLayout(HL[i]);}
        else if (i == 11) {ui->VL12->addLayout(HL[i]);}
        else if (i == 12) {ui->VL13->addLayout(HL[i]);}
        else if (i == 13) {ui->VL14->addLayout(HL[i]);}
        else if (i == 14) {ui->VL15->addLayout(HL[i]);}
        else if (i == 15) {ui->VL16->addLayout(HL[i]);}

        if (i < 8){
            s_graph->create_grafik(HL[i], plot[i], &kurva[i], setting, 0.00, 0.00, 0.00, i);
        }
        else{
            s_graph->create_grafik_spek(HL[i], plot[i], &kurva[i], setting, 0.00, 0.00, 0.00, i-8);
        }
    }
}

void MainWindow::init_alarm(int status)
{
    for (int i = 0; i < JUM_CURVE; i++){
        if (i == 0) alarm = this->ui->alarm_1;
        if (i == 1) alarm = this->ui->alarm_2;
        if (i == 2) alarm = this->ui->alarm_3;
        if (i == 3) alarm = this->ui->alarm_4;
        if (i == 4) alarm = this->ui->alarm_5;
        if (i == 5) alarm = this->ui->alarm_6;
        if (i == 6) alarm = this->ui->alarm_7;
        if (i == 7) alarm = this->ui->alarm_8;
        if (i == 8) alarm = this->ui->alarm_9;
        if (i == 9) alarm = this->ui->alarm_10;
        if (i == 10) alarm = this->ui->alarm_11;
        if (i == 11) alarm = this->ui->alarm_12;
        if (i == 12) alarm = this->ui->alarm_13;
        if (i == 13) alarm = this->ui->alarm_14;
        if (i == 14) alarm = this->ui->alarm_15;
        if (i == 15) alarm = this->ui->alarm_16;

        if (status == 1){
            s_alarm->set_default_green_alarm(alarm);
        }
        else{
            s_alarm->set_off_alarm(alarm);
        }
    }
}

void MainWindow::init_timer(){
    tim = new QTimer(this);
    tim_db = new QTimer(this);
    QObject::connect( tim, SIGNAL(timeout()), this, SLOT(refresh_plot()));
    QObject::connect( tim_db, SIGNAL(timeout()), this, SLOT(simpan_ke_db()));
    tim->stop();
    tim_db->stop();
}

void MainWindow::init_udpSocket(){
    udpSocket = new QUdpSocket(this);
    udp_data = new QUdpSocket(this);
    pernah_penuh = 0;
    udp_count = 0;

    udp_data->bind(QHostAddress::Any, PORT_CILIWUNG_DATA);
    QObject::connect(udp_data, SIGNAL(readyRead()), this, SLOT(ada_udp_data()));
}

void MainWindow:: init_UserInterface(){
    log = new Form_log(this);
    log->setWindowFlags( Qt::Window );
    log->setWindowTitle("Log (Online Monitoring)");

    sigpro = new signalProcessing();
    mThread = new MyThread();
    tThread = new TrThread();

    for (int i = 0; i < JUM_PLOT; i++){
        peak_stats[i] = IDLE_PEAK;
        harmonic_stats[i] = IDLE_HARMONIC;
    }
}

void MainWindow::set_memory(){
    int i, n;

    sumbu_x = (double *) malloc( (LEN_TEST + BESAR_PAKET) * sizeof(double));
    memset( (char *) sumbu_x, 0, (LEN_TEST + BESAR_PAKET) * sizeof(double));
    for (i=0; i<LEN_TEST; i++){
        sumbu_x[i] = i;
    }

    win_coef = (double *) malloc(MAX_FFT_POINT * sizeof(double));
    memset( (char *) win_coef, 0, MAX_FFT_POINT * sizeof(double));

    hasil_windowing = (double *) malloc(MAX_FFT_POINT * sizeof(double));
    memset( (char *) hasil_windowing, 0, MAX_FFT_POINT * sizeof(double));

    for (i=0; i<JUM_PLOT; i++)
    {
        data_y[i] = (double *) malloc( (LEN_TEST + BESAR_PAKET) * sizeof(double));
        memset( (char *) data_y[i], 0, (LEN_TEST + BESAR_PAKET) * sizeof(double));

        data_y_afterhpf[i] = (double *) malloc( (LEN_TEST + BESAR_PAKET) * sizeof(double));
        memset( (char *) data_y_afterhpf[i], 0, (LEN_TEST + BESAR_PAKET) * sizeof(double));
    }

    for (i = 0; i < JUM_PLOT; i++){
        sb_x[i] = (double *) malloc(MAX_FFT_POINT * sizeof(double));
        memset( (char *) sb_x[i], 0, MAX_FFT_POINT * sizeof(double));

        for (n = 0; n < spektrum_points; n++){
            sb_x[i][n] = n;
        }
    }

    for (i = 0; i<JUM_PLOT; i++){
        fft_re_out[i] = (double *) malloc(MAX_FFT_POINT * sizeof(double));
        memset( (char *) fft_re_out[i], 0, MAX_FFT_POINT *sizeof(double));

        fft_magt[i] = (double *) malloc(MAX_FFT_POINT * sizeof(double));
        memset( (char *) fft_magt[i], 0, MAX_FFT_POINT *sizeof(double));

        fft_im_out[i] = (double *) malloc(MAX_FFT_POINT * sizeof(double));
        memset( (char *) fft_im_out[i], 0, MAX_FFT_POINT *sizeof(double));
    }

    for (int i = 0; i < JUM_PLOT; i++){
        data_save[i] = (float *) malloc(((LEN_TEST + BESAR_PAKET) * setting->db_setting.db_period_simpan) * sizeof(float));
        memset( (char *) data_save[i], 0, (((LEN_TEST + BESAR_PAKET) * setting->db_setting.db_period_simpan) * sizeof(float)));

        data_get[i] = (float *) malloc(MAX_FFT_POINT * sizeof(float));
        memset( (char *) data_get[i], 0, MAX_FFT_POINT * sizeof(float));
    }
}

void MainWindow::flush_memory(){
    int i;

    memset( (char *) sumbu_x, 0, (LEN_TEST + BESAR_PAKET) * sizeof(double));
    memset( (char *) win_coef, 0, MAX_FFT_POINT * sizeof(double));
    memset( (char *) hasil_windowing, 0, MAX_FFT_POINT * sizeof(double));

    for (i = 0; i < JUM_PLOT; i++){
        memset( (char *) data_y[i], 0, (LEN_TEST + BESAR_PAKET) * sizeof(double));
        memset( (char *) data_y_afterhpf[i], 0, (LEN_TEST + BESAR_PAKET) * sizeof(double));
        memset( (char *) sb_x[i], 0, MAX_FFT_POINT * sizeof(double));

        memset( (char *) fft_re_out[i], 0, MAX_FFT_POINT *sizeof(double));
        memset( (char *) fft_magt[i], 0, MAX_FFT_POINT *sizeof(double));
        memset( (char *) fft_im_out[i], 0, MAX_FFT_POINT *sizeof(double));

        memset( (char *) data_save[i], 0, (((LEN_TEST + BESAR_PAKET) * setting->db_setting.db_period_simpan) * sizeof(float)));
        memset( (char *) data_get[i], 0, MAX_FFT_POINT * sizeof(float));
    }

}

void MainWindow::free_memory(){
    int i;

    delete sumbu_x;
    delete win_coef;
    delete hasil_windowing;

    for (i = 0; i < JUM_PLOT; i++){
        delete data_y[i];
        delete data_y_afterhpf[i];
        delete sb_x[i];

        delete fft_re_out[i] ;
        delete fft_magt[i];
        delete fft_im_out[i];

        delete data_save[i];
        delete data_get[i];
    }
}

void MainWindow::ada_udp_data()
{
    QHostAddress sender;
    int loop = 0;
    struct tt_req2 *p_req2;
    float *p_data;
    int i;
    int i_kanal;
    int y;

    while (udp_data->hasPendingDatagrams())
    {
        loop++;
        QByteArray datagram;
        datagram.resize(udp_data->pendingDatagramSize());
        udp_data->readDatagram(datagram.data(), datagram.size(), &sender, 0);

        p_req2 = (struct tt_req2 *) datagram.data();
        p_data = (float *) p_req2->buf;
        i_kanal = p_req2->cur_kanal;

        if (i_kanal > JUM_KANAL) return;

        /* mengubah data ke double */
        int pos = ((p_req2->request_sample % paket_diharapkan) * BESAR_PAKET_F);

        if (!pernah_penuh)
        {
            for (i=0; i<256; i++)
            {
                data_y[i_kanal][i + ((p_req2->request_sample % paket_diharapkan) * BESAR_PAKET_F)] = (double) p_data[i];

                /* simpan dalam float */
                if (i_kanal == 0){
                    cnt_ch1++;
                    data_save[i_kanal][cnt_ch1] = p_data[i];
                }
                else if (i_kanal == 1){
                    cnt_ch2++;
                    data_save[i_kanal][cnt_ch2] = p_data[i];
                }
                else if (i_kanal == 2){
                    cnt_ch3++;
                    data_save[i_kanal][cnt_ch3] = p_data[i];
                }
                else{
                    cnt_ch4++;
                    data_save[i_kanal][cnt_ch4] = p_data[i];
                }
            }

            switch (setting->wave.en_filter){
            case 0 : /* dengan filter HPF */
                kurva[i_kanal].setRawSamples( &sumbu_x[ 0 ], &data_y[ i_kanal ][ 0 ],  pos);

                proses_fft(&data_y[ i_kanal ][ 0 ], i_kanal);
                kurva[i_kanal+8].setRawSamples( &sb_x[i_kanal][ 0 ], &fft_magt[ i_kanal ][ 0 ], spektrum_points);
                break;
            default : /* tanpa filter HPF */
                sigpro->gen_simple_hpf(&data_y[i_kanal][0], &data_y_afterhpf[i_kanal][0], setting->wave.f_cutoff, pos, setting->fmax);
                kurva[i_kanal].setRawSamples( &sumbu_x[ 0 ], &data_y_afterhpf[ i_kanal ][ 0 ],  pos);
                proses_fft(&data_y_afterhpf[ i_kanal ][ 0 ], i_kanal);
                kurva[i_kanal+8].setRawSamples( &sb_x[i_kanal][ 0 ], &fft_magt[ i_kanal ][ 0 ], spektrum_points);
                break;
            }
        }
        else
        {
            /* data yang diupdate hanya paket terakhir, selebihnya digeser kedepan saja */
            /* digeser dulu */
            for (y=0; y<(paket_diharapkan-1); y++)
            {
                for (i=0; i<256; i++)
                {
                    data_y[i_kanal][ i + (y * BESAR_PAKET_F)] = data_y[ i_kanal ][ i + ((y+1) * BESAR_PAKET_F)];
                }
            }

            /* data paket terakhir */
            for (i=0; i<256; i++)
            {
                data_y[i_kanal][i + (y * BESAR_PAKET_F)] = (double) p_data[i];

                /* simpan dalam float */
                if (i_kanal == 0){
                    cnt_ch1++;
                    data_save[i_kanal][cnt_ch1] = p_data[i];
                }
                else if (i_kanal == 1){
                    cnt_ch2++;
                    data_save[i_kanal][cnt_ch2] = p_data[i];
                }
                else if (i_kanal == 2){
                    cnt_ch3++;
                    data_save[i_kanal][cnt_ch3] = p_data[i];
                }
                else{
                    cnt_ch4++;
                    data_save[i_kanal][cnt_ch4] = p_data[i];
                }
            }

            switch (setting->wave.en_filter){
            case 0 : /* tanpa filter HPF */
                kurva[i_kanal].setRawSamples( &sumbu_x[ 0 ], &data_y[ i_kanal ][ 0 ],  LEN_TEST);
                proses_fft(&data_y[ i_kanal ][ 0 ], i_kanal);
                kurva[i_kanal+8].setRawSamples(&sb_x[i_kanal][ 0 ], &fft_magt[ i_kanal ][ 0 ], spektrum_points);
                break;
            default : /* dengan filter HPF */
                sigpro->gen_simple_hpf(&data_y[i_kanal][0], &data_y_afterhpf[i_kanal][0], setting->wave.f_cutoff, LEN_TEST, setting->fmax);
                kurva[i_kanal].setRawSamples( &sumbu_x[ 0 ], &data_y_afterhpf[ i_kanal ][ 0 ],  LEN_TEST);
                proses_fft(&data_y_afterhpf[ i_kanal ][ 0 ], i_kanal);
                kurva[i_kanal+8].setRawSamples(&sb_x[i_kanal][ 0 ], &fft_magt[ i_kanal ][ 0 ], spektrum_points);
            }
        }
        if (((p_req2->request_sample % paket_diharapkan) + 1) == paket_diharapkan)
        {
            pernah_penuh = 1;
        }
   }
}

void MainWindow::minta_data_lagi()
{
    loop_test++;
    //qDebug("Minta data %d", loop_test);

    struct tt_req2 t_req2;
    sprintf(t_req2.head, "getdata");
    t_req2.request_sample = LEN_TEST;       /* 1000 data saja */
    loop_test = 0;

    /* ingat, paket dalam 32 bit float */
    paket_diharapkan = (LEN_TEST * 4) / BESAR_PAKET;
    //paket_diharapkan += 1;
    //paket_diharapkan = 10;
    paket_masuk = 0;

    QString ip;
    ip.sprintf("%s", setting->modul1_ip);

    udpSocket->writeDatagram((char *) &t_req2, sizeof(t_req2), QHostAddress(ip), PORT_CILIWUNG_SEND);
}

void MainWindow::refresh_plot()
{
    tim_count++;
    if (tim_count > 22)
    {
        tim_count = 0;
        minta_data_lagi();
    }

    for (int i = 0; i < JUM_PLOT; i++){ /* plot 1 - 4 [Waveform] */
        /* Sumbu-Y Waveform */
        switch (setting->wave.en_auto_scale){
        case 0 :
            /* Fixed Scale */
            miny[i] = setting->wave.amp_min;
            maxy[i] = setting->wave.amp_max;
            break;
        default :
            /* Auto Scale */
            miny[i] = kurva[i].minYValue();
            maxy[i] = kurva[i].maxYValue();
            break;
        }

        /* Sumbu-X Waveform */
        switch (setting->wave.en_auto_len){
        case 0 :
            /* Fixed Scale */
            maxx[i] = setting->wave.len;
            break;
        default :
            /* Auto Scale */
            maxx[i] = kurva[i].maxXValue();
            break;
        }

        rms_w = form->gen_rms_wave(&data_y[i][0], kurva[i].maxXValue());
        s_graph->update_grafik_info_wave(plot[i], setting, miny[i], maxy[i], maxx[i], rms_w, kurva[i].minYValue(), kurva[i].maxYValue(), i);

        tThread->rms[i] = (double) rms_w;
        tThread->peakmin[i] = (double) kurva[i].minYValue();
        tThread->peakmax[i] = (double) kurva[i].maxYValue();
        tThread->crest_factor[i] = (double) ((double) tThread->peakmax[i] / (double) tThread->rms[i]);
    }

    for (int i = 0; i < JUM_PLOT; i++){ /* plot 9 - 12 [Spektrum] */
        /* Sumbu-Y Spektrum */
        switch (setting->spek.en_auto_scale){
        case 0 :
            /* Fixed Scale */
            miny_s[i] = (double) setting->spek.amp_min;
            maxy_s[i] = (double) setting->spek.amp_max;
            break;
        default :
            /* Auto Scale */
            miny_s[i] = (double) kurva[i+8].minYValue();
            maxy_s[i] = (double) kurva[i+8].maxYValue();
            break;
        }

        /* Sumbu-X Spektrum */
        switch (setting->spek.en_auto_len){
        case 0 :
            /* Fixed Scale */
            maxx_s[i] = setting->spek.len;
            break;
        default :
            /* Auto Scale */
            maxx_s[i] = setting->plot_set[i].interval_spek * 30.0;
        }

        rms_s = form->gen_rms_spek(&fft_magt[i][0], spektrum_points/2);
        s_graph->update_grafik_info_spek(plot[i+8], setting, miny_s[i], maxy_s[i], maxx_s[i], rms_s, kurva[i+8].maxYValue(), i);

        /* ------------------------------------ set Peak marker ------------------------------------ */
        int index_peakmax;
        switch (peak_stats[i]){
        case SHOW_PEAK :
            index_peakmax = (int) form->gen_index_peakmax(&fft_magt[i][0], spektrum_points/2);
            s_graph->set_peak_marker(plot[i+8], &peak_m[i], sb_x[i][index_peakmax], fft_magt[i][index_peakmax], maxx_s[i], true);
            break;
        case HIDE_PEAK :
            s_graph->set_peak_marker(plot[i+8], &peak_m[i], sb_x[i][index_peakmax], fft_magt[i][index_peakmax], maxx_s[i], false);
            peak_stats[i] = IDLE_PEAK;
            break;
        default :
            break;
        }


        /* ---------------------------------- set Harmonic marker ---------------------------------- */
        double frekuensi_dasar;
        int index_line;
        switch (harmonic_stats[i]){
        case SHOW_HARMONIC :
            for (int n = 0; n < 10; n++){
                switch (setting->plot_set[i].index_judul_sb_x_spek){
                case 0:
                    index_line = ((setting->plot_set[i].reff_rpm / 60.00) / setting->plot_set[i].resolusi_spek) * (n + 1);
                    break;
                case 1:
                    index_line = (((setting->plot_set[i].reff_rpm / 1000.0) / setting->plot_set[i].resolusi_spek) * (n + 1)) + 1;
                    break;
                default:
                    index_line = (( 1 / setting->plot_set[i].resolusi_spek) * (n + 1)) + 1;
                    break;
                }

                frekuensi_dasar = (double) index_line * (double) setting->plot_set[i].resolusi_spek;
                s_graph->set_harmonic_marker(plot[i+8], &harmonic_m[i][n], frekuensi_dasar, fft_magt[i][index_line], maxx_s[i], true, i, setting);
            }
            break;
        case HIDE_HARMONIC :
            for (int n = 0; n < 10; n++){
                s_graph->set_harmonic_marker(plot[i+8], &harmonic_m[i][n], frekuensi_dasar, fft_magt[i][0], maxx_s[i], false, i, setting);
                harmonic_stats[i] = IDLE_HARMONIC;
            }
            break;
        default :
            break;
        }

        tThread->rms_spek[i] = (double) rms_spek[i];
        tThread->peakmax_spek[i] = (double) kurva[i+8].maxYValue();
    }

    tThread->start();

    for (int i = 0; i < JUM_PLOT; i++){
        switch(i){
        case 0:
            alarm_wave = this->ui->alarm_1;
            alarm_spek = this->ui->alarm_9;
            break;
        case 1:
            alarm_wave = this->ui->alarm_2;
            alarm_spek = this->ui->alarm_10;
            break;
        case 2:
            alarm_wave = this->ui->alarm_3;
            alarm_spek = this->ui->alarm_11;
            break;
        default :
            alarm_wave = this->ui->alarm_4;
            alarm_spek = this->ui->alarm_12;
            break;
        }
        s_alarm->update_alarm_wave(alarm_wave, setting, kurva[i].maxYValue(), kurva[i].minYValue(), i);
        s_alarm->update_alarm_spek(alarm_spek, setting, kurva[i+8].maxYValue(), i+8);
    }
}

void MainWindow::simpan_ke_db(){
    int i;
    for (i = 0; i < JUM_KANAL; i++){
        memcpy(&data_get[i][0], &data_save[i][cnt_ch1-(spektrum_points)], spektrum_points * sizeof(float));
    }

    QByteArray array0((char *) &data_get[0][0], spektrum_points * sizeof(float));
    QByteArray array1((char *) &data_get[1][0], spektrum_points * sizeof(float));
    QByteArray array2((char *) &data_get[2][0], spektrum_points * sizeof(float));
    QByteArray array3((char *) &data_get[3][0], spektrum_points * sizeof(float));

    /* tabel_waveform */
    mThread->bb0 = array0;
    mThread->bb1 = array1;
    mThread->bb2 = array2;
    mThread->bb3 = array3;
    mThread->num = spektrum_points;
    mThread->fmax = setting->fmax;

    /* tabel_trend waveform & spektrum */
    for (int i = 0; i < JUM_KANAL; i++){
        mThread->ref_rpm[i] = setting->plot_set[i].reff_rpm;
    }

    mThread->start();

    /* clear memory and variable */
    cnt_ch1 = 0;
    cnt_ch2 = 0;
    cnt_ch3 = 0;
    cnt_ch4 = 0;

    array0.clear();
    array1.clear();
    array2.clear();
    array3.clear();

    for (int i = 0; i < JUM_KANAL; i++){
        memset( (char *) data_save[i], 0, (((LEN_TEST + BESAR_PAKET) * setting->db_setting.db_period_simpan) * sizeof(float)));
        memset( (char *) data_get[i], 0, spektrum_points * sizeof(float));
    }
}

void MainWindow::proses_fft(double *wave_y, int index)
{
    /* proses FFT */
    windowkand(&wave_y[0], hasil_windowing, win_coef, spektrum_points);

    fft_double(spektrum_points, 0, hasil_windowing, 0, &fft_re_out[index][0], &fft_im_out[index][0]);

    for (int i=0; i< spektrum_points; i++)
    {
        fft_magt[index][i] = sqrt( (fft_re_out[index][i] * fft_re_out[index][i]) + ( fft_im_out[index][i] * fft_im_out[index][i]));
        fft_magt[index][i] = fft_magt[index][i] / (spektrum_points);

        //fft_magt[index][i] = fft_magt[index][i] * 2.00;
        sb_x[index][i] = (double) ((double)i * (double) setting->plot_set[index].resolusi_spek);
    }
    fft_magt[index][0] = 0.00;
    fft_magt[index][spektrum_points-1] = 0.00;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionRun_triggered()
{
   /* alarm ON */
   init_alarm(ON);

   if (!tim->isActive())
   {
       this->ui->actionRun->setIcon(QIcon(":icon/icon_stop.png"));
       this->ui->actionRun->setToolTip("Stop");

       tim_count = 0;
       pernah_penuh = 0;

       minta_data_lagi();
       tim->start(setting->refresh);
       tim_db->start(setting->db_setting.db_period_simpan * 1000);
   }
   else
   {
       tim->stop();
       tim_db->stop();
       this->ui->actionRun->setIcon(QIcon(":icon/icon_play.png"));
       this->ui->actionRun->setToolTip("Run");

       init_alarm(OFF);
   }
}

void MainWindow::on_actionTrending_triggered()
{
    f_trn = new Form_Trend(this);
    f_trn->setWindowTitle("Trending Peak Value (Online Monitoring");

    f_trn->init_grafik(setting);

    f_trn->showMaximized();
}

void MainWindow::on_actionRe_Play_triggered()
{
    f_rpl = new Form_Replay(this);
    f_rpl->setWindowTitle("Replay Snapshoot (Online Monitoring");

    f_rpl->init_grafik(setting);
    f_rpl->init_timer();
    f_rpl->init_default_value();
    f_rpl->init_user_interface();

    f_rpl->showMaximized();
}

void MainWindow::on_actionSetting_triggered()
{
    int res;

    d_set = new Dialog_setting(this);
    d_set->setWindowTitle("Setting (Online Monitoring)");

    s_table->init_table_kanal(d_set);
    s_table->isi_table_kanal(d_set);
    s_table->init_table_band(d_set);

    s_value->set_setting_value(d_set, setting);

    d_set->show();

    res = d_set->exec();

    if (res == 0) return;

    for (int i = 0; i < JUM_BAND_AREA; i++){
        d_set->min_frek[d_set->last_idx][i] = d_set->ui->tabel_set_band->model()->data(d_set->ui->tabel_set_band->model()->index(i, 1)).toFloat();
        d_set->max_frek[d_set->last_idx][i] = d_set->ui->tabel_set_band->model()->data(d_set->ui->tabel_set_band->model()->index(i, 2)).toFloat();
        d_set->alarm_l[d_set->last_idx][i] = d_set->ui->tabel_set_band->model()->data(d_set->ui->tabel_set_band->model()->index(i, 3)).toFloat();
        d_set->alarm_h[d_set->last_idx][i] = d_set->ui->tabel_set_band->model()->data(d_set->ui->tabel_set_band->model()->index(i, 4)).toFloat();
    }

    f_set->get_setting_modul_server(d_set, setting);
    f_set->get_setting_database(d_set, setting);
    f_set->get_setting_kanal(d_set, setting);
    f_set->get_setting_waveform(d_set, setting);
    f_set->get_setting_spektrum(d_set, setting);
    f_set->get_setting_band_analysis(d_set, setting);
    f_set->write_settings(setting);

    spektrum_points = setting->spek.line * 2.56;
    for (int i = 0; i < JUM_PLOT; i++){
        s_graph->set_grafik_info_wave(plot[i], setting, i);
        s_graph->set_grafik_info_spek(plot[i+8], setting, i);
    }

    /* gen ulang window coef */
    sigpro->gen_window_coef(setting, win_coef, spektrum_points);



    /* set ulang timer access database */
    tim_db->stop();
    tim_db->start(setting->db_setting.db_period_simpan * 1000);
}

void MainWindow::on_actionLog_triggered()
{
    log->move( 400, 300);
    log->show();
    log->raise();
}

void MainWindow::on_actionReport_triggered()
{
    lap = new Form_lap();
    lap->setWindowTitle("Report (Online Monitoring)");

    lap->move(400,100);
    lap->show();
}

void MainWindow::on_actionNew_Database_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Buat Database Baru"), "(*.ovm)");

    if (fileName.isEmpty()){
        return;
    }
    else{
        dbase->create_database(fileName, count_db);
        fileName = fileName+".ovm";

        /* set last db directory open */
        strcpy(setting->db_setting.db_directory, fileName.toLatin1());
        f_set->write_settings(setting);
    }
}

void MainWindow::on_actionOpen_Database_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Buat Database Baru"), "(*.ovm)");

    if (fileName.isEmpty()){
        return;
    }
    else{
        dbase->load_database(fileName, count_db);

        /* set last db directory open */
        strcpy(setting->db_setting.db_directory, fileName.toLatin1());
        f_set->write_settings(setting);
    }
}

void MainWindow::copy_grafik_toclipboard0()
{
    QPixmap qPix = QPixmap::grabWidget(plot[0]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard1()
{
    QPixmap qPix = QPixmap::grabWidget(plot[1]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard2()
{
    QPixmap qPix = QPixmap::grabWidget(plot[2]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard3()
{
    QPixmap qPix = QPixmap::grabWidget(plot[3]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard4()
{
    QPixmap qPix = QPixmap::grabWidget(plot[4]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard5()
{
    QPixmap qPix = QPixmap::grabWidget(plot[5]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard6()
{
    QPixmap qPix = QPixmap::grabWidget(plot[6]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard7()
{
    QPixmap qPix = QPixmap::grabWidget(plot[7]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}


void MainWindow::copy_grafik_toclipboard8()
{
    QPixmap qPix = QPixmap::grabWidget(plot[8]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard9()
{
    QPixmap qPix = QPixmap::grabWidget(plot[9]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard10()
{
    QPixmap qPix = QPixmap::grabWidget(plot[10]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard11()
{
    QPixmap qPix = QPixmap::grabWidget(plot[11]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard12()
{
    QPixmap qPix = QPixmap::grabWidget(plot[12]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard13()
{
    QPixmap qPix = QPixmap::grabWidget(plot[13]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard14()
{
    QPixmap qPix = QPixmap::grabWidget(plot[14]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void MainWindow::copy_grafik_toclipboard15()
{
    QPixmap qPix = QPixmap::grabWidget(plot[15]);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}


/* -------------------------------------- Band Analisi ---------------------------------------- */
void MainWindow::overlay_band_ch1(){
    log->out("Overlay Band Analisis Ch.1");
    double f_min;
    double f_max;
    double a_min;
    double a_max;

    double resolusi = (double) form->conv_line_to_hz((double) setting->spek.line, FMAX);

    for (int i = 0; i < JUM_BAND_AREA; i++){
        f_min = (double) (setting->band[0].min_freq[i] / resolusi);
        f_max = (double) (setting->band[0].max_freq[i] / resolusi);
        a_min = (double) (setting->band[0].alarm_l[i] / resolusi);
        a_max = (double) (setting->band[0].alarm_h[i] / resolusi);

        band->tampil_band_analis(setting, plot[8], &band_start_min[0][0], &band_start_max[0][0], &band_stop_min[0][0], &band_stop_max[0][0],
                                 &limit_low[0][0], &limit_high[0][0], f_min, f_max, a_min, a_max);
    }
}

void MainWindow::overlay_band_ch2(){
    log->out("Overlay Band Analisis Ch.2");
}

void MainWindow::overlay_band_ch3(){
    log->out("Overlay Band Analisis Ch.3");
}

void MainWindow::overlay_band_ch4(){
    log->out("Overlay Band Analisis Ch.4");
}

void MainWindow::overlay_band_ch5(){
    log->out("Overlay Band Analisis Ch.5");
}

void MainWindow::overlay_band_ch6(){
    log->out("Overlay Band Analisis Ch.6");
}

void MainWindow::overlay_band_ch7(){
    log->out("Overlay Band Analisis Ch.7");
}

void MainWindow::overlay_band_ch8(){
    log->out("Overlay Band Analisis Ch.8");
}

/* ---------------------------------------- Peak Marker --------------------------------------- */
void MainWindow::show_peak_marker_ch1(){
    pop_peak[0]->setCheckable(true);

    if (peak_stats[0] == IDLE_PEAK){
        pop_peak[0]->setChecked(true);
        peak_stats[0] = SHOW_PEAK;
    }
    else if (peak_stats[0] == SHOW_PEAK){
        pop_peak[0]->setChecked(false);
        peak_stats[0] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch2(){
    pop_peak[1]->setCheckable(true);

    if (peak_stats[1] == IDLE_PEAK){
        pop_peak[1]->setChecked(true);
        peak_stats[1] = SHOW_PEAK;
    }
    else if (peak_stats[1] == SHOW_PEAK){
        pop_peak[1]->setChecked(false);
        peak_stats[1] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch3(){
    pop_peak[2]->setCheckable(true);

    if (peak_stats[2] == IDLE_PEAK){
        pop_peak[2]->setChecked(true);
        peak_stats[2] = SHOW_PEAK;
    }
    else if (peak_stats[2] == SHOW_PEAK){
        pop_peak[2]->setChecked(false);
        peak_stats[2] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch4(){
    pop_peak[3]->setCheckable(true);

    if (peak_stats[3] == IDLE_PEAK){
        pop_peak[3]->setChecked(true);
        peak_stats[3] = SHOW_PEAK;
    }
    else if (peak_stats[3] == SHOW_PEAK){
        pop_peak[3]->setChecked(false);
        peak_stats[3] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch5(){
    pop_peak[4]->setCheckable(true);

    if (peak_stats[4] == IDLE_PEAK){
        pop_peak[4]->setChecked(true);
        peak_stats[4] = SHOW_PEAK;
    }
    else if (peak_stats[4] == SHOW_PEAK){
        pop_peak[4]->setChecked(false);
        peak_stats[4] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch6(){
    pop_peak[5]->setCheckable(true);

    if (peak_stats[5] == IDLE_PEAK){
        pop_peak[5]->setChecked(true);
        peak_stats[5] = SHOW_PEAK;
    }
    else if (peak_stats[5] == SHOW_PEAK){
        pop_peak[5]->setChecked(false);
        peak_stats[5] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch7(){
    pop_peak[6]->setCheckable(true);

    if (peak_stats[6] == IDLE_PEAK){
        pop_peak[6]->setChecked(true);
        peak_stats[6] = SHOW_PEAK;
    }
    else if (peak_stats[6] == SHOW_PEAK){
        pop_peak[6]->setChecked(false);
        peak_stats[6] = HIDE_PEAK;
    }
}

void MainWindow::show_peak_marker_ch8(){
    pop_peak[7]->setCheckable(true);

    if (peak_stats[7] == IDLE_PEAK){
        pop_peak[7]->setChecked(true);
        peak_stats[7] = SHOW_PEAK;
    }
    else if (peak_stats[7] == SHOW_PEAK){
        pop_peak[7]->setChecked(false);
        peak_stats[7] = HIDE_PEAK;
    }
}


/* ---------------------------------------- Harmonics Marker ------------------------------------ */
void MainWindow::show_harmonic_marker_ch1(){
    pop_harmonic[0]->setCheckable(true);

    if (harmonic_stats[0] == IDLE_HARMONIC){
        pop_harmonic[0]->setChecked(true);
        harmonic_stats[0] = SHOW_HARMONIC;
    }
    else if (harmonic_stats[0] == SHOW_HARMONIC){
        pop_harmonic[0]->setChecked(false);
        harmonic_stats[0] = HIDE_HARMONIC;
    }
}

void MainWindow::show_harmonic_marker_ch2(){

}

void MainWindow::show_harmonic_marker_ch3(){

}

void MainWindow::show_harmonic_marker_ch4(){

}

void MainWindow::show_harmonic_marker_ch5(){

}

void MainWindow::show_harmonic_marker_ch6(){

}

void MainWindow::show_harmonic_marker_ch7(){

}

void MainWindow::show_harmonic_marker_ch8(){

}
