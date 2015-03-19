#include "file_setting.h"

file_setting::file_setting()
{
}

void file_setting::get_setting_modul_server(Dialog_setting *d_set, t_setting *setting){
    QString ip_module;
    QString ip_module_ext_1;

    if (d_set->ui->rad_1000->isChecked() == true){
        setting->fmax = 1000;
    }
    else{
        setting->fmax = 4000;
    }

    ip_module.sprintf("%s.%s.%s.%s", d_set->ui->ip_m1_seg1->text().toAscii().data(), d_set->ui->ip_m1_seg2->text().toAscii().data(),
                      d_set->ui->ip_m1_seg3->text().toAscii().data(), d_set->ui->ip_m1_seg4->text().toAscii().data());
    strcpy(setting->modul1_ip, ip_module.toLatin1());

    ip_module_ext_1.sprintf("%s.%s.%s.%s", d_set->ui->ip_m2_seg1->text().toAscii().data(), d_set->ui->ip_m2_seg2->text().toAscii().data(),
                      d_set->ui->ip_m2_seg3->text().toAscii().data(), d_set->ui->ip_m2_seg4->text().toAscii().data());
    strcpy(setting->modul2_ip, ip_module_ext_1.toLatin1());

    if (d_set->ui->ip_module2->isChecked() == true){
        setting->en_modul_ext1 = 1;
    }
    else{
        setting->en_modul_ext1 = 0;
    }

    setting->refresh = d_set->ui->line_refresh->text().toInt();
    setting->protokol_modul = d_set->ui->combo_protocol->currentIndex()+1;
}

void file_setting::get_setting_database(Dialog_setting *d_set, t_setting *setting){
    strcpy (setting->db_setting.db_ip, d_set->ui->line_database_ip->text().toLatin1());
    strcpy (setting->db_setting.db_nama, d_set->ui->line_database_nama->text().toLatin1());
    strcpy (setting->db_setting.db_pass, d_set->ui->line_database_pass->text().toLatin1());
    strcpy (setting->db_setting.db_user, d_set->ui->line_database_user->text().toLatin1());
    setting->db_setting.db_period_simpan = d_set->ui->line_period_simpan->value();
    setting->db_setting.db_buffer = d_set->ui->line_len_buf->text().toInt();
    setting->db_setting.db_hari_ditahan = d_set->ui->line_data_ditahan->text().toInt();
    setting->db_setting.db_driver = d_set->ui->combo_db_driver->currentIndex();
}

void file_setting::get_setting_kanal(Dialog_setting *d_set, t_setting *setting){
    QString judul_y;
    QString judul_x_wave;
    QString judul_x_spek;

    for (int i = 0; i < JUM_KURVA; i++){
        if(d_set->kanal_en[i]->isChecked()){
            setting->plot_set[i].flag_enable = 1;
        }
        else{
            setting->plot_set[i].flag_enable = 0;
        }

        setting->plot_set[i].trend_param = d_set->trend_param[i]->currentIndex();
        setting->plot_set[i].kanal_out = d_set->kanal_out[i]->currentIndex();

        setting->plot_set[i].index_judul_sb_y = d_set->sb_y[i]->currentIndex();

        if (d_set->kanal_out[i]->currentIndex() == 0){
            judul_y.sprintf("Vib. Acc (%s)", d_set->sb_y[i]->currentText().toAscii().data());
            strcpy(setting->plot_set[i].judul_sumbu_y, judul_y.toLatin1());
        }
        else if(d_set->kanal_out[i]->currentIndex() == 1){
            judul_y.sprintf("Vib. Velc (%s)", d_set->sb_y[i]->currentText().toAscii().data());
            strcpy(setting->plot_set[i].judul_sumbu_y, judul_y.toLatin1());
        }
        else if(d_set->kanal_out[i]->currentIndex() == 2){
            judul_y.sprintf("Vib. Disp (%s)", d_set->sb_y[i]->currentText().toAscii().data());
            strcpy(setting->plot_set[i].judul_sumbu_y, judul_y.toLatin1());
        }
        else{
            judul_y.sprintf("Vib. Volt (%s)", d_set->sb_y[i]->currentText().toAscii().data());
            strcpy(setting->plot_set[i].judul_sumbu_y, judul_y.toLatin1());
        }

        setting->plot_set[i].index_judul_sb_x_wave = d_set->sb_x_wave[i]->currentIndex();
        judul_x_wave.sprintf("Time (%s)", d_set->sb_x_wave[i]->currentText().toAscii().data());
        strcpy(setting->plot_set[i].judul_sumbu_x_wave, judul_x_wave.toLatin1());

        setting->plot_set[i].index_judul_sb_x_spek = d_set->sb_x_spek[i]->currentIndex();
        judul_x_spek.sprintf("Frekuensi (%s)", d_set->sb_x_spek[i]->currentText().toAscii().data());
        strcpy(setting->plot_set[i].judul_sumbu_x_spek, judul_x_spek.toLatin1());

        setting->plot_set[i].reff_rpm = d_set->ref_rpm[i]->text().toFloat();
        setting->plot_set[i].alarm_ll = d_set->LL[i]->text().toFloat();
        setting->plot_set[i].alarm_l = d_set->L[i]->text().toFloat();
        setting->plot_set[i].alarm_h = d_set->H[i]->text().toFloat();
        setting->plot_set[i].alarm_hh = d_set->HH[i]->text().toFloat();
        setting->plot_set[i].en_alarm1 = d_set->en_alarm1[i]->currentIndex();
        setting->plot_set[i].en_alarm2 = d_set->en_alarm2[i]->currentIndex();

        strcpy(setting->plot_set[i].judul, d_set->judul[i]->text().toLatin1());
        strcpy(setting->plot_set[i].judul_bawah, d_set->judul_bawah[i]->text().toLatin1());              
        strcpy(setting->plot_set[i].warna, d_set->warna_str[i].toLatin1());

        setting->plot_set[i].resolusi_wave = (float) 1.0;
        setting->plot_set[i].interval_wave = 0;

        if (d_set->sb_x_spek[i]->currentIndex() == 0){
            setting->plot_set[i].resolusi_spek = (float) this->resolusi_line_to_hz(d_set->ui->combo_lines_spektrum->currentText().toInt(), setting->fmax);
            setting->plot_set[i].interval_spek = setting->plot_set[i].reff_rpm / 60.0;
        }
        else if(d_set->sb_x_spek[i]->currentIndex() == 1){
            setting->plot_set[i].resolusi_spek = (float) ((float) this->resolusi_line_to_cpm(d_set->ui->combo_lines_spektrum->currentText().toInt(), setting->fmax) / (float) 1000.0);
            setting->plot_set[i].interval_spek = setting->plot_set[i].reff_rpm / 1000.0;
        }
        else if (d_set->sb_x_spek[i]->currentIndex() == 2){
            setting->plot_set[i].resolusi_spek = (float) this->resolusi_line_to_order(d_set->ui->combo_lines_spektrum->currentText().toInt(), setting->fmax, d_set->ref_rpm[i]->text().toInt());
            setting->plot_set[i].interval_spek = 1;
        }
    }
}

void file_setting::get_setting_waveform(Dialog_setting *d_set, t_setting *setting){
    setting->wave.len = d_set->ui->line_len_waveform->text().toInt();

    if (d_set->ui->rad_auto_len_wave->isChecked() == true){
        setting->wave.en_auto_len = 1;
    }
    else{
        setting->wave.en_auto_len = 0;
    }

    if(d_set->ui->rad_auto_wave->isChecked() == true){
       setting->wave.en_auto_scale = 1;
    }
    else{
       setting->wave.en_auto_scale = 0;
    }

    setting->wave.amp_min = d_set->ui->line_amp_waveform_min->text().toFloat();
    setting->wave.amp_max = d_set->ui->line_amp_waveform_max->text().toFloat();

    if (d_set->ui->cb_en_filter->isChecked() == true){
        setting->wave.en_filter = 1;
    }
    else {
        setting->wave.en_filter = 0;
    }
    setting->wave.f_cutoff = d_set->ui->line_fcutoff->text().toFloat();

}

void file_setting::get_setting_spektrum(Dialog_setting *d_set, t_setting *setting){
    setting->spek.line = d_set->ui->combo_lines_spektrum->currentText().toInt();
    setting->spek.avg = d_set->ui->line_avg_spektrum->text().toInt();
    setting->spek.window = d_set->ui->combo_window_spektrum->currentIndex();
    setting->spek.len = d_set->ui->line_len_spektrum->text().toInt();

    if (d_set->ui->rad_auto_len_spek->isChecked() == true){
        setting->spek.en_auto_len = 1;
    }
    else{
        setting->spek.en_auto_len = 0;
    }

    if(d_set->ui->rad_auto_spek->isChecked() == true){
       setting->spek.en_auto_scale = 1;
    }
    else{
       setting->spek.en_auto_scale = 0;
    }

    setting->spek.amp_min = d_set->ui->line_amp_spektrum_min->text().toFloat();
    setting->spek.amp_max = d_set->ui->line_amp_spektrum_max->text().toFloat();
}

void file_setting::get_setting_band_analysis(Dialog_setting *d_set, t_setting *setting){
    int i, n;

    for (i = 0; i < JUM_KANAL; i++){
        for (n = 0; n < JUM_BAND_AREA; n++){
            setting->band[i].min_freq[n] = d_set->min_frek[i][n];
            setting->band[i].max_freq[n] = d_set->max_frek[i][n];
            setting->band[i].alarm_l[n] = d_set->alarm_l[i][n];
            setting->band[i].alarm_h[n] = d_set->alarm_h[i][n];
        }
    }
}

void file_setting::write_settings(t_setting *setting)
{
    QString pth = "setting.ini";
    QSettings sett(pth, QSettings::IniFormat);

    QByteArray BA((char *) setting, sizeof (struct t_setting));
    sett.setValue("global", BA);
}

void file_setting::read_settings(t_setting *setting)
{
    QString pth = "setting.ini";
    QSettings sett(pth, QSettings::IniFormat);

    memcpy( setting, (void *) sett.value("global").toByteArray().data(), sizeof (struct t_setting));

    /* cek */
    if (strcmp( setting->cek_set, SET_CEK) == 0)
    {
        qDebug() << "Setting Oke!";
    }
    else
    {
        memset((char *) setting, 0, sizeof (struct t_setting));
        this->default_settings(setting);
        this->write_settings(setting);
    }
}

void file_setting::default_settings(t_setting *setting){
    int i;

    /* Modul Server */
    sprintf(setting->cek_set, SET_CEK);

    setting->fmax = 1000;
    sprintf(setting->modul1_ip, "192.168.1.240");
    sprintf(setting->modul2_ip, "192.168.1.241");
    setting->en_modul_ext1 = 0;
    setting->refresh = 100;
    setting->protokol_modul = 1;

    /* Database */
    sprintf(setting->db_setting.db_ip, "172.0.0.1");
    sprintf(setting->db_setting.db_nama, "dbe_online");
    sprintf(setting->db_setting.db_user, "monita");
    sprintf(setting->db_setting.db_pass, "v_monita");
    setting->db_setting.db_period_simpan = 4;
    setting->db_setting.db_buffer = 100;
    setting->db_setting.db_hari_ditahan = 300;
    sprintf(setting->db_setting.db_directory, "-L$$PWD/db/tes.ovm");
    setting->db_setting.db_driver = 2;

    /* Kanal */
    for (i = 0; i < JUM_PLOT; i++){
        setting->plot_set[i].flag_enable = 1;
        sprintf(setting->plot_set[i].judul, "Channel %d", i+1);

        setting->plot_set[i].resolusi_wave = 1.00;
        setting->plot_set[i].interval_wave = 0;

        setting->plot_set[i].resolusi_spek = (float)(1000.0 / 800.0);
        setting->plot_set[i].interval_spek = 100;

        setting->plot_set[i].trend_param = 2;
        setting->plot_set[i].kanal_out = 0;

        setting->plot_set[i].index_judul_sb_y = 0;
        sprintf(setting->plot_set[i].judul_sumbu_y, "Vib. Acc (G)");

        setting->plot_set[i].index_judul_sb_x_wave = 0;
        sprintf(setting->plot_set[i].judul_sumbu_x_wave, "Time (ms)");

        setting->plot_set[i].index_judul_sb_x_spek= 0;
        sprintf(setting->plot_set[i].judul_sumbu_x_spek, "Frekuensi (Hz)");

        setting->plot_set[i].reff_rpm = 600;

        /* alarm l, alarm ll, alarm hh, alarm h */

        setting->plot_set[i].en_alarm1 = 0;
        setting->plot_set[i].en_alarm2 = 0;

        sprintf(setting->plot_set[i].warna, "#ff0000");
    }

    /* Band Analysis */

    /* waveform */
    setting->wave.len = 1000;
    setting->wave.amp_min = -5;
    setting->wave.amp_max = 5;
    setting->wave.en_auto_scale = 1;
    setting->wave.en_auto_len = 1;
    setting->wave.en_filter = 0;
    setting->wave.f_cutoff = (float) 10.0;

    /* spektrum */
    setting->spek.line = 800;
    setting->spek.avg = 5;
    setting->spek.window = 0;
    setting->spek.len = 1000;
    setting->spek.amp_min = 0.0;
    setting->spek.amp_max = 1.0;
    setting->wave.en_auto_len = 1;
    setting->spek.en_auto_scale = 1;
}



/* -------------------------------- Rumus Cari Resolusi Conversi ---------------------------*/
float file_setting::resolusi_line_to_hz(int line, int fmax){
    float res;
    res = (float) (((float) fmax / (float) line) );

    return (float) res;
}

float file_setting::resolusi_line_to_cpm(int line, int fmax){
    float res;
    res = (float) (((float) fmax / (float) line));
    res = (float) res * (float) (60.0);

    return (float) res;
}

float file_setting::resolusi_line_to_order(int line, int fmax, int ref_rpm){
    float res;
    res = (float) (((float) fmax / (float) line));
    res = (float) ((float) res / (float)((float) ref_rpm / (float) 60.00));

    return (float) res;
}
