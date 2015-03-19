#include "set_value.h"

set_value::set_value()
{
}

void set_value::set_setting_value(Dialog_setting *d_set, t_setting *set){
    int i, n;

    /* Modul Server */
    if (set->fmax == 1000){
        d_set->ui->rad_1000->setChecked(true);
    }
    else{
        d_set->ui->rad_4000->setChecked(true);
    }

    this->compact_ip_address(set->modul1_ip, d_set->ui->ip_m1_seg1, d_set->ui->ip_m1_seg2, d_set->ui->ip_m1_seg3, d_set->ui->ip_m1_seg4);
    this->compact_ip_address(set->modul2_ip, d_set->ui->ip_m2_seg1, d_set->ui->ip_m2_seg2, d_set->ui->ip_m2_seg3, d_set->ui->ip_m2_seg4);

    d_set->ui->line_refresh->setText( QString::number( set->refresh) );
    d_set->ui->combo_protocol->setCurrentIndex( set->protokol_modul-1 );

    /* Database */
    d_set->ui->line_database_ip->setText( set->db_setting.db_ip );

    if (set->spek.line < 1000){ d_set->ui->line_period_simpan->setMinimum(2); }
    else if (set->spek.line == 1600){ d_set->ui->line_period_simpan->setMinimum(4); }
    else if (set->spek.line == 3200){ d_set->ui->line_period_simpan->setMinimum(6); }
    else if (set->spek.line == 6400){ d_set->ui->line_period_simpan->setMinimum(8); }
    d_set->ui->line_period_simpan->setValue(set->db_setting.db_period_simpan);

    d_set->ui->line_len_buf->setText( QString::number( set->db_setting.db_buffer) );

    d_set->ui->line_database_nama->setText( set->db_setting.db_nama );
    d_set->ui->line_database_pass->setText( set->db_setting.db_pass );
    d_set->ui->line_database_user->setText( set->db_setting.db_user );
    d_set->ui->line_database_lastdir->setText( set->db_setting.db_directory );

    /* Kanal */
    for (i = 0; i < JUM_KURVA; i++){
        d_set->kanal_en[i]->setText(QString::number(i+1));

        d_set->judul[i]->setText(set->plot_set[i].judul);
        d_set->judul_bawah[i]->setText(set->plot_set[i].judul_bawah);

        d_set->trend_param[i]->addItem(QString::fromUtf8("Peak Max"));
        d_set->trend_param[i]->addItem(QString::fromUtf8("Peak Min"));
        d_set->trend_param[i]->addItem(QString::fromUtf8("RMS"));
        d_set->trend_param[i]->addItem(QString::fromUtf8("Peak-Peak"));
        d_set->trend_param[i]->setCurrentIndex(set->plot_set[i].trend_param);

        d_set->kanal_out[i]->addItem(QString::fromUtf8("Acceleration"));
        d_set->kanal_out[i]->addItem(QString::fromUtf8("Velocity"));
        d_set->kanal_out[i]->addItem(QString::fromUtf8("Displacement"));
        d_set->kanal_out[i]->addItem(QString::fromUtf8("Voltage"));
        d_set->kanal_out[i]->setCurrentIndex(set->plot_set[i].kanal_out);

        /* sesuai d_set->kanal_out[i] yang dipilih */
        set_sby_cbvalue(d_set, i, set->plot_set[i].kanal_out, set);
        d_set->sb_y[i]->setCurrentIndex(set->plot_set[i].index_judul_sb_y);

        d_set->sb_x_wave[i]->addItem(QString::fromUtf8("ms"));
        d_set->sb_x_wave[i]->addItem(QString::fromUtf8("s"));
        d_set->sb_x_wave[i]->setCurrentIndex(set->plot_set[i].index_judul_sb_x_wave);

        d_set->sb_x_spek[i]->addItem(QString::fromUtf8("Hz"));
        d_set->sb_x_spek[i]->addItem(QString::fromUtf8("kcpm"));
        d_set->sb_x_spek[i]->addItem(QString::fromUtf8("order"));
        d_set->sb_x_spek[i]->setCurrentIndex(set->plot_set[i].index_judul_sb_x_spek);

        d_set->ref_rpm[i]->setText(QString::number(set->plot_set[i].reff_rpm));

        QString alarms_ll;
        alarms_ll.sprintf("%.2f", (float) set->plot_set[i].alarm_ll);
        d_set->LL[i]->setText(alarms_ll);

        QString alarms_l;
        alarms_l.sprintf("%.2f", (float) set->plot_set[i].alarm_l);
        d_set->L[i]->setText(alarms_l);

        QString alarms_h;
        alarms_h.sprintf("%.2f", (float) set->plot_set[i].alarm_h);
        d_set->H[i]->setText(alarms_h);

        QString alarms_hh;
        alarms_hh.sprintf("%.2f", (float) set->plot_set[i].alarm_hh);
        d_set->HH[i]->setText(alarms_hh);

        d_set->en_alarm1[i]->addItem(QString::fromUtf8("Disabled"));
        d_set->en_alarm1[i]->addItem(QString::fromUtf8("LL"));
        d_set->en_alarm1[i]->addItem(QString::fromUtf8("L"));
        d_set->en_alarm1[i]->addItem(QString::fromUtf8("H"));
        d_set->en_alarm1[i]->addItem(QString::fromUtf8("HH"));
        d_set->en_alarm1[i]->setCurrentIndex(set->plot_set[i].en_alarm1);

        d_set->en_alarm2[i]->addItem(QString::fromUtf8("Disabled"));
        d_set->en_alarm2[i]->addItem(QString::fromUtf8("LL"));
        d_set->en_alarm2[i]->addItem(QString::fromUtf8("L"));
        d_set->en_alarm2[i]->addItem(QString::fromUtf8("H"));
        d_set->en_alarm2[i]->addItem(QString::fromUtf8("HH"));
        d_set->en_alarm2[i]->setCurrentIndex(set->plot_set[i].en_alarm2);


        QPalette pl = d_set->warna[i]->palette();
        pl.setColor(QPalette::Button, QColor(set->plot_set[i].warna));
        d_set->warna[i]->setFlat(true);
        d_set->warna[i]->setPalette(pl);
        d_set->warna[i]->setAutoFillBackground(true);

        d_set->warna_str[i].sprintf("%s", set->plot_set[i].warna);
    }

    /* Band Analysis */
    for (i = 0; i < JUM_KANAL; i++){
        for (n = 0; n < JUM_BAND_AREA; n++){
            if (i == 0){
                d_set->ui->tabel_set_band->setItem(n, 0, new QTableWidgetItem(QString::number(n+1)));
                d_set->ui->tabel_set_band->setItem(n, 1, new QTableWidgetItem(QString::number(set->band[i].min_freq[n])));
                d_set->ui->tabel_set_band->setItem(n, 2, new QTableWidgetItem(QString::number(set->band[i].max_freq[n])));
                d_set->ui->tabel_set_band->setItem(n, 3, new QTableWidgetItem(QString::number(set->band[i].alarm_l[n])));
                d_set->ui->tabel_set_band->setItem(n, 4, new QTableWidgetItem(QString::number(set->band[i].alarm_h[n])));
            }
            d_set->min_frek[i][n] = set->band[i].min_freq[n];
            d_set->max_frek[i][n] = set->band[i].max_freq[n];
            d_set->alarm_l[i][n] = set->band[i].alarm_l[n];
            d_set->alarm_h[i][n] = set->band[i].alarm_h[n];
        }
    }

    /* Waveform */
    d_set->ui->line_len_waveform->setText(QString::number(set->wave.len));

    if (set->wave.en_auto_len == 1){
        d_set->ui->rad_auto_len_wave->setChecked(true);
        d_set->ui->line_len_waveform->setEnabled(false);
    }
    else{
        d_set->ui->rad_fixed_len_wave->setChecked(true);
        d_set->ui->line_len_waveform->setEnabled(true);
    }

    if (set->wave.en_auto_scale == 1){
        d_set->ui->rad_auto_wave->setChecked(true);
        d_set->ui->line_amp_waveform_min->setEnabled(false);
        d_set->ui->line_amp_waveform_max->setEnabled(false);
    }
    else{
        d_set->ui->rad_fixed_wave->setChecked(true);
        d_set->ui->line_amp_waveform_min->setEnabled(true);
        d_set->ui->line_amp_waveform_max->setEnabled(true);
    }
    d_set->ui->line_amp_waveform_min->setText(QString::number(set->wave.amp_min, 'g', 3));
    d_set->ui->line_amp_waveform_max->setText(QString::number(set->wave.amp_max, 'g', 3));

    if (set->wave.en_filter == 1){
        d_set->ui->cb_en_filter->setChecked(true);
        d_set->ui->line_fcutoff->setEnabled(true);
    }
    else{
        d_set->ui->cb_en_filter->setChecked(false);
        d_set->ui->line_fcutoff->setEnabled(false);
    }

    d_set->ui->line_fcutoff->setText(QString::number(set->wave.f_cutoff, 'g', 3));

    /* Spektrum */
    if(set->spek.line == 100) d_set->ui->combo_lines_spektrum->setCurrentIndex(0);
    else if (set->spek.line == 200) d_set->ui->combo_lines_spektrum->setCurrentIndex(1);
    else if (set->spek.line == 400) d_set->ui->combo_lines_spektrum->setCurrentIndex(2);
    else if (set->spek.line == 800) d_set->ui->combo_lines_spektrum->setCurrentIndex(3);
    else if (set->spek.line == 1600) d_set->ui->combo_lines_spektrum->setCurrentIndex(4);
    else if (set->spek.line == 3200) d_set->ui->combo_lines_spektrum->setCurrentIndex(5);
    else if (set->spek.line == 6400) d_set->ui->combo_lines_spektrum->setCurrentIndex(6);

    d_set->ui->line_avg_spektrum->setText(QString::number(set->spek.avg));
    d_set->ui->combo_window_spektrum->setCurrentIndex(set->spek.window);
    d_set->ui->line_len_spektrum->setText(QString::number(set->spek.len));

    if (set->spek.en_auto_len == 1){
        d_set->ui->rad_auto_len_spek->setChecked(true);
        d_set->ui->line_len_spektrum->setEnabled(false);
    }
    else{
        d_set->ui->rad_fixed_len_spek->setChecked(true);
        d_set->ui->line_len_spektrum->setEnabled(true);
    }

    if (set->spek.en_auto_scale == 1){
        d_set->ui->rad_auto_spek->setChecked(true);
        d_set->ui->line_amp_spektrum_min->setEnabled(false);
        d_set->ui->line_amp_spektrum_max->setEnabled(false);
    }
    else{
        d_set->ui->rad_fixed_spek->setChecked(true);
        d_set->ui->line_amp_spektrum_min->setEnabled(true);
        d_set->ui->line_amp_spektrum_max->setEnabled(true);
    }
    d_set->ui->line_amp_spektrum_min->setText(QString::number((float) set->spek.amp_min, 'g', 3));
    d_set->ui->line_amp_spektrum_max->setText(QString::number((float) set->spek.amp_max, 'g', 3));
}

void set_value::set_sby_cbvalue(Dialog_setting *d_set, int idx_cb, int idx_output, t_setting *set){
    d_set->sb_y[idx_cb]->clear();

    if (idx_output == 0){ /* Acceleration */
        d_set->sb_y[idx_cb]->addItem(QString::fromUtf8("G"));
    }
    else if (idx_output == 1){ /* Velocity */
        d_set->sb_y[idx_cb]->addItem(QString::fromUtf8("m/s"));
        d_set->sb_y[idx_cb]->addItem(QString::fromUtf8("IPS"));
    }
    else if (idx_output == 2){ /* Displacement */
        d_set->sb_y[idx_cb]->addItem(QString::fromUtf8("µm"));
        d_set->sb_y[idx_cb]->addItem(QString::fromUtf8("mil"));
    }
    else if (idx_output == 3){ /* Volt */
        d_set->sb_y[idx_cb]->addItem(QString::fromUtf8("Volt"));
    }    
}

void set_value::compact_ip_address(char ip[32], QLineEdit *seg1, QLineEdit *seg2, QLineEdit *seg3, QLineEdit *seg4){
    int i, n;

    QString modul;

    QString temp = "";
    QString m[4];

    modul.sprintf("%s", ip);
    n = 0;
    for (i = 0; i < modul.size(); i++){
        if (ip[i] == '.'){
            n++;
            temp = "";
        }
        else{
            temp.sprintf("%s%c", temp.toAscii().data(), ip[i]);
            m[n] = temp;
        }
    }

    seg1->setText(m[0]);
    seg2->setText(m[1]);
    seg3->setText(m[2]);
    seg4->setText(m[3]);
}
