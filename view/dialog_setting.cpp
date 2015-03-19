#include "dialog_setting.h"
#include "ui_dialog_setting.h"

Dialog_setting::Dialog_setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_setting)
{
    ui->setupUi(this);

    this->init_grafik();

    last_idx = 0;

    ui->line_database_pass->setEchoMode( QLineEdit::Password);
    ui->tabel_set_kanal->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Dialog_setting::~Dialog_setting()
{
    delete ui;
}

void Dialog_setting::showEvent(QShowEvent *)
{
    qDebug("%s:", __FUNCTION__);

    QObject::connect(warna[0], SIGNAL(clicked()), this, SLOT(call_dialogColor0()));
    QObject::connect(warna[1], SIGNAL(clicked()), this, SLOT(call_dialogColor1()));
    QObject::connect(warna[2], SIGNAL(clicked()), this, SLOT(call_dialogColor2()));
    QObject::connect(warna[3], SIGNAL(clicked()), this, SLOT(call_dialogColor3()));
    QObject::connect(warna[4], SIGNAL(clicked()), this, SLOT(call_dialogColor4()));
    QObject::connect(warna[5], SIGNAL(clicked()), this, SLOT(call_dialogColor5()));
    QObject::connect(warna[6], SIGNAL(clicked()), this, SLOT(call_dialogColor6()));
    QObject::connect(warna[7], SIGNAL(clicked()), this, SLOT(call_dialogColor7()));

    QObject::connect(kanal_out[0], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox0(int)));
    QObject::connect(kanal_out[1], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox1(int)));
    QObject::connect(kanal_out[2], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox2(int)));
    QObject::connect(kanal_out[3], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox3(int)));
    QObject::connect(kanal_out[4], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox4(int)));
    QObject::connect(kanal_out[5], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox5(int)));
    QObject::connect(kanal_out[6], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox6(int)));
    QObject::connect(kanal_out[7], SIGNAL(currentIndexChanged(int)), this, SLOT(get_sby_cbox7(int)));
}

void Dialog_setting::init_grafik()
{
    p_band = new plot_grafik();
    p_band->setAxisScale(QwtPlot::yLeft, 0, 10, 0);
    p_band->setAxisScale(QwtPlot::xBottom, 0, 1000, 100);

    QwtPlotGrid *grid_band = new QwtPlotGrid;

    #if QT_VERSION >= 0x050000
        grid_band->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine)); // versi 6.1.1
    #else
        grid_band->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    #endif
    grid_band->attach( p_band );

    this->ui->VL_Band->addWidget( p_band );

    p_wave = new plot_grafik();
    p_wave->setAxisScale(QwtPlot::yLeft, 0, 10, 0);
    p_wave->setAxisScale(QwtPlot::xBottom, 0, 1000, 100);

    QwtPlotGrid *grid_wave = new QwtPlotGrid;

    #if QT_VERSION >= 0x050000
        grid_wave->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine)); // versi 6.1.1
    #else
        grid_wave->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    #endif
    grid_wave->attach( p_wave );

    this->ui->VL_Wave->addWidget( p_wave );

    p_spec = new plot_grafik();
    p_spec->setAxisScale(QwtPlot::yLeft, 0, 10, 0);
    p_spec->setAxisScale(QwtPlot::xBottom, 0, 1000, 100);

    QwtPlotGrid *grid_spec = new QwtPlotGrid;

    #if QT_VERSION >= 0x050000
        grid_spec->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine)); // versi 6.1.1
    #else
        grid_spec->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    #endif
    grid_spec->attach( p_spec );

    this->ui->VL_Spek->addWidget( p_spec );
}

void Dialog_setting::init_userinterface(){
    this->ui->ip_m1_seg1->setMaxLength(3);
    this->ui->ip_m1_seg2->setMaxLength(3);
    this->ui->ip_m1_seg3->setMaxLength(3);
    this->ui->ip_m1_seg4->setMaxLength(3);

    this->ui->ip_m2_seg1->setMaxLength(3);
    this->ui->ip_m2_seg2->setMaxLength(3);
    this->ui->ip_m2_seg3->setMaxLength(3);
    this->ui->ip_m2_seg4->setMaxLength(3);
}

void Dialog_setting::on_pushButton_clicked()
{
    qDebug("Test koneksi pada database");
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName( ui->line_database_ip->text() );
    db.setDatabaseName( ui->line_database_nama->text() );
    db.setUserName( ui->line_database_user->text() );
    db.setPassword( ui->line_database_pass->text() );
    bool ok = db.open();

    if (ok)
    {
        qDebug("OPen database OK");
        msg_box("Test database OK !");
    }
    else
    {
        qDebug("OPen database GAGAL");
        error_box("Test database Gagal !");

    }
}

//void Dialog_setting::on_buttonBox_accepted()
//{
//    /* tes */
//    QPixmap qPix = QPixmap::grabWidget(this);
//    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
//}

/* isi combobox "sb_y", berdasarkan index combobox "kanal_out" yang dipilih
   QComboBox */

void Dialog_setting::get_sby_cbox(int index, int ch_out){ /* Default dari baca_setting */

    sb_y[index]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[index]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[index]->addItem(QString::fromUtf8("m/s"));
        sb_y[index]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[index]->addItem(QString::fromUtf8("µm"));
        sb_y[index]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[index]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox0(int ch_out){
    sb_y[0]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[0]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[0]->addItem(QString::fromUtf8("m/s"));
        sb_y[0]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[0]->addItem(QString::fromUtf8("µm"));
        sb_y[0]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[0]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox1(int ch_out){

    sb_y[1]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[1]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[1]->addItem(QString::fromUtf8("m/s"));
        sb_y[1]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[1]->addItem(QString::fromUtf8("µm"));
        sb_y[1]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[1]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox2(int ch_out){

    sb_y[2]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[2]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[2]->addItem(QString::fromUtf8("m/s"));
        sb_y[2]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[2]->addItem(QString::fromUtf8("µm"));
        sb_y[2]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[2]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox3(int ch_out){

    sb_y[3]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[3]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[3]->addItem(QString::fromUtf8("m/s"));
        sb_y[3]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[3]->addItem(QString::fromUtf8("µm"));
        sb_y[3]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[3]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox4(int ch_out){

    sb_y[4]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[4]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[4]->addItem(QString::fromUtf8("m/s"));
        sb_y[4]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[4]->addItem(QString::fromUtf8("µm"));
        sb_y[4]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[4]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox5(int ch_out){

    sb_y[5]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[5]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[5]->addItem(QString::fromUtf8("m/s"));
        sb_y[5]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[5]->addItem(QString::fromUtf8("µm"));
        sb_y[5]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[5]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox6(int ch_out){

    sb_y[6]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[6]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[6]->addItem(QString::fromUtf8("m/s"));
        sb_y[6]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[6]->addItem(QString::fromUtf8("µm"));
        sb_y[6]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[6]->addItem(QString::fromUtf8("Volt"));
    }
}

void Dialog_setting::get_sby_cbox7(int ch_out){

    sb_y[7]->clear();

    if (ch_out == 0){ /* Acceleration */
        sb_y[7]->addItem(QString::fromUtf8("G"));
    }
    else if (ch_out == 1){ /* Velocity */
        sb_y[7]->addItem(QString::fromUtf8("m/s"));
        sb_y[7]->addItem(QString::fromUtf8("IPS"));
    }
    else if (ch_out == 2){ /* Displacement */
        sb_y[7]->addItem(QString::fromUtf8("µm"));
        sb_y[7]->addItem(QString::fromUtf8("mil"));
    }
    else if (ch_out == 3){ /* Volt */
        sb_y[7]->addItem(QString::fromUtf8("Volt"));
    }
}


/* Setting warna kurva dan pushbutton
   QColorDialog */

void Dialog_setting::call_dialogColor0()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(0);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[0] = color.name();

    QPalette pl = warna[0]->palette();
    pl.setColor(QPalette::Button, color);

    warna[0]->setFlat(true);
    warna[0]->setPalette(pl);
    warna[0]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor1()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(1);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[1] = color.name();

    QPalette pl = warna[1]->palette();
    pl.setColor(QPalette::Button, color);

    warna[1]->setFlat(true);
    warna[1]->setPalette(pl);
    warna[1]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor2()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(2);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[2] = color.name();

    QPalette pl = warna[2]->palette();
    pl.setColor(QPalette::Button, color);

    warna[2]->setFlat(true);
    warna[2]->setPalette(pl);
    warna[2]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor3()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(3);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[3] = color.name();

    QPalette pl = warna[3]->palette();
    pl.setColor(QPalette::Button, color);

    warna[3]->setFlat(true);
    warna[3]->setPalette(pl);
    warna[3]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor4()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(4);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[4] = color.name();

    QPalette pl = warna[4]->palette();
    pl.setColor(QPalette::Button, color);

    warna[4]->setFlat(true);
    warna[4]->setPalette(pl);
    warna[4]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor5()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(5);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[5] = color.name();

    QPalette pl = warna[5]->palette();
    pl.setColor(QPalette::Button, color);

    warna[5]->setFlat(true);
    warna[5]->setPalette(pl);
    warna[5]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor6()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(6);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[6] = color.name();

    QPalette pl = warna[6]->palette();
    pl.setColor(QPalette::Button, color);

    warna[6]->setFlat(true);
    warna[6]->setPalette(pl);
    warna[6]->setAutoFillBackground(true);
}

void Dialog_setting::call_dialogColor7()
{
    int res;
    QColor color;

    QColorDialog *cd = new QColorDialog(this);
    QString cl = "Pengaturan Warna Kurva "+QString::number(7);
    cd->setWindowTitle(cl);
    cd->setModal(true);

    res = cd->exec();

    if(res == 0)return;

    color = cd->currentColor();
    warna_str[7] = color.name();

    QPalette pl = warna[7]->palette();
    pl.setColor(QPalette::Button, color);

    warna[7]->setFlat(true);
    warna[7]->setPalette(pl);
    warna[7]->setAutoFillBackground(true);
}

void Dialog_setting::on_rad_auto_wave_clicked(){
    this->ui->line_amp_waveform_max->setEnabled(false);
    this->ui->line_amp_waveform_min->setEnabled(false);
}

void Dialog_setting::on_rad_fixed_wave_clicked(){
    this->ui->line_amp_waveform_max->setEnabled(true);
    this->ui->line_amp_waveform_min->setEnabled(true);
}

void Dialog_setting::on_rad_auto_spek_clicked(){
    this->ui->line_amp_spektrum_max->setEnabled(false);
    this->ui->line_amp_spektrum_min->setEnabled(false);
}

void Dialog_setting::on_rad_fixed_spek_clicked(){
    this->ui->line_amp_spektrum_max->setEnabled(true);
    this->ui->line_amp_spektrum_min->setEnabled(true);
}

void Dialog_setting::on_comboBox_currentIndexChanged(int index){
    /* simpan band last channel */
    for (int i = 0; i < JUM_BAND_AREA; i++){
        this->min_frek[last_idx][i] = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 1)).toFloat();
        this->max_frek[last_idx][i] = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 2)).toFloat();
        this->alarm_l[last_idx][i] = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 3)).toFloat();
        this->alarm_h[last_idx][i] = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 4)).toFloat();
    }

    last_idx = index;
    /* buka band new channel */
    for (int i = 0; i < JUM_BAND_AREA; i++){
        this->ui->tabel_set_band->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
        this->ui->tabel_set_band->setItem(i, 1, new QTableWidgetItem(QString::number(this->min_frek[last_idx][i])));
        this->ui->tabel_set_band->setItem(i, 2, new QTableWidgetItem(QString::number(this->max_frek[last_idx][i])));
        this->ui->tabel_set_band->setItem(i, 3, new QTableWidgetItem(QString::number(this->alarm_l[last_idx][i])));
        this->ui->tabel_set_band->setItem(i, 4, new QTableWidgetItem(QString::number(this->alarm_h[last_idx][i])));
    }
}

void Dialog_setting::on_combo_lines_spektrum_currentIndexChanged(const QString &arg1)
{
    int lines;
    lines = arg1.toInt();

    if (lines < 1000){
        this->ui->line_period_simpan->setMinimum(2);
    }
    else if (lines == 1600){
        this->ui->line_period_simpan->setMinimum(4);
    }
    else if (lines == 3200){
        this->ui->line_period_simpan->setMinimum(6);
    }
    else if (lines == 6400){
        this->ui->line_period_simpan->setMinimum(8);
    }
}

void Dialog_setting::on_pb_update_band_clicked()
{
    int i = 0;
    float fmin;
    float fmax;
    float l_min;
    float l_max;

    for (i = 0; i < JUM_BAND_AREA; i++){
        fmin  = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 1)).toFloat();
        fmax  = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 2)).toFloat();
        l_min = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 3)).toFloat();
        l_max = this->ui->tabel_set_band->model()->data(this->ui->tabel_set_band->model()->index(i, 4)).toFloat();

        s_graph->set_marker_band(p_band, &marker[i][0], &marker[i][1], &marker[i][2], &marker[i][3], &marker[i][4], &marker[i][5],
                                 fmin, fmax, l_min, l_max);
    }
}

void Dialog_setting::on_rad_auto_len_spek_clicked()
{
    this->ui->line_len_spektrum->setEnabled(false);
}

void Dialog_setting::on_rad_fixed_len_spek_clicked()
{
    this->ui->line_len_spektrum->setEnabled(true);
}

void Dialog_setting::on_rad_auto_len_wave_clicked()
{
    this->ui->line_len_waveform->setEnabled(false);
}

void Dialog_setting::on_rad_fixed_len_wave_clicked()
{
    this->ui->line_len_waveform->setEnabled(true);
}

void Dialog_setting::on_ip_module2_clicked(bool checked)
{
    this->ui->ip_m2_seg1->setEnabled(checked);
    this->ui->ip_m2_seg2->setEnabled(checked);
    this->ui->ip_m2_seg3->setEnabled(checked);
    this->ui->ip_m2_seg4->setEnabled(checked);
}

void Dialog_setting::on_cb_en_filter_clicked(bool checked)
{
    this->ui->line_fcutoff->setEnabled(checked);
}
