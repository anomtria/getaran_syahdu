#include "show_table.h"

show_table::show_table()
{
}

void show_table::init_table_kanal(Dialog_setting *d_set){
    d_set->ui->tabel_set_kanal->setColumnCount(16);
    d_set->ui->tabel_set_kanal->setRowCount(8);
    d_set->ui->tabel_set_kanal->verticalHeader()->hide();

    d_set->ui->tabel_set_kanal->setColumnWidth(0, 50);
    d_set->ui->tabel_set_kanal->setColumnWidth(1, 180);
    d_set->ui->tabel_set_kanal->setColumnWidth(2, 220);
    d_set->ui->tabel_set_kanal->setColumnWidth(4, 150);
    d_set->ui->tabel_set_kanal->setColumnWidth(6, 150);
    d_set->ui->tabel_set_kanal->setColumnWidth(7, 150);

    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Kanal")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Judul")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Keterangan")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Trend. Param")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(4, new QTableWidgetItem(QString("Kanal Output")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(5, new QTableWidgetItem(QString("Sb. Y")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(6, new QTableWidgetItem(QString("Sb. X Waveform")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(7, new QTableWidgetItem(QString("Sb. X Spektrum")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(8, new QTableWidgetItem(QString("Ref. RPM")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(9, new QTableWidgetItem(QString("LL")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(10, new QTableWidgetItem(QString("L")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(11, new QTableWidgetItem(QString("H")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(12, new QTableWidgetItem(QString("HH")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(13, new QTableWidgetItem(QString("En. Alarm 1")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(14, new QTableWidgetItem(QString("En. Alarm 2")));
    d_set->ui->tabel_set_kanal->setHorizontalHeaderItem(15, new QTableWidgetItem(QString("Warna")));
}

void show_table::init_table_band(Dialog_setting *d_set){
    d_set->ui->tabel_set_band->setColumnCount(5);
    d_set->ui->tabel_set_band->setRowCount(5);
    d_set->ui->tabel_set_band->verticalHeader()->hide();

    d_set->ui->tabel_set_band->setColumnWidth(0, 57);
    d_set->ui->tabel_set_band->setColumnWidth(1, 135);
    d_set->ui->tabel_set_band->setColumnWidth(2, 135);
    d_set->ui->tabel_set_band->setColumnWidth(3, 135);
    d_set->ui->tabel_set_band->setColumnWidth(4, 135);

    d_set->ui->tabel_set_band->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Area")));
    d_set->ui->tabel_set_band->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Freq Min (Hz)")));
    d_set->ui->tabel_set_band->setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Freq Max (Hz)")));
    d_set->ui->tabel_set_band->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Alarm L")));
    d_set->ui->tabel_set_band->setHorizontalHeaderItem(4, new QTableWidgetItem(QString("Alarm H")));
}

void show_table::isi_table_kanal(Dialog_setting *d_set){
    int i;

    for (i = 0; i<JUM_KURVA; i++){
        d_set->kanal_en[i] = new QCheckBox(d_set->ui->tabel_set_kanal);    
        d_set->ui->tabel_set_kanal->setCellWidget(i, 0, d_set->kanal_en[i]);

        d_set->judul[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 1, d_set->judul[i]);

        d_set->judul_bawah[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 2, d_set->judul_bawah[i]);

        d_set->trend_param[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i,3, d_set->trend_param[i]);

        d_set->kanal_out[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i,4, d_set->kanal_out[i]);

        d_set->sb_y[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 5, d_set->sb_y[i]);

        d_set->sb_x_wave[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 6, d_set->sb_x_wave[i]);

        d_set->sb_x_spek[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 7, d_set->sb_x_spek[i]);

        d_set->ref_rpm[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 8, d_set->ref_rpm[i]);

        d_set->LL[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 9, d_set->LL[i]);

        d_set->L[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 10, d_set->L[i]);

        d_set->H[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 11, d_set->H[i]);

        d_set->HH[i] = new QLineEdit(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 12, d_set->HH[i]);

        d_set->en_alarm1[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 13, d_set->en_alarm1[i]);

        d_set->en_alarm2[i] = new QComboBox(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 14, d_set->en_alarm2[i]);

        d_set->warna[i] = new QPushButton(d_set->ui->tabel_set_kanal);
        d_set->ui->tabel_set_kanal->setCellWidget(i, 15, d_set->warna[i]);
        d_set->warna[i]->setFlat(true);
    }
}
