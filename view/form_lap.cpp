#include "form_lap.h"
#include "ui_form_lap.h"

Form_lap::Form_lap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_lap)
{
    ui->setupUi(this);

    QMenu *menu = new QMenu(this);
    this->setContextMenuPolicy(Qt::ActionsContextMenu);

    QAction *copy;
    copy = new QAction("Copy", menu);

    QAction *exp;
    exp = new QAction("Export", menu);

    this->addAction(copy);
    this->addAction(exp);

    QObject::connect( copy, SIGNAL(triggered()), this, SLOT(copy_clipboard()));

}

Form_lap::~Form_lap()
{
    delete ui;
}

void Form_lap::copy_clipboard()
{
    qDebug("%s", __PRETTY_FUNCTION__);

    QPixmap qPix = QPixmap::grabWidget(this);
    QApplication::clipboard()->setPixmap( qPix, QClipboard::Clipboard);
}

void Form_lap::info_teks(QPainter *pnt)
{
    pnt->setPen( Qt::black );
    QPen pen = pnt->pen();
    pen.setWidth( 1 );
    pnt->setPen( pen );

    QFont fnt;
    fnt.setFamily("Ubuntu");
    fnt.setPixelSize( 30 );

    pnt->setFont( fnt );

#if 0
    /* pasang judul */
       kan->Brush->Style = bsClear;
       kan->Font->Name = "Arial";
       kan->Font->Color = clBlack;
       //sTem = "Kondisi Pembakaran";
       sTem = judul_lap;
       kan->Font->Size = t_font_judul;
       letak = 20;
       dari_atas = t_font_judul-5;
       kan->TextOutA(letak, dari_atas, sTem);
       kan->Font->Size = 10; //besar font untuk nama mesin dll
       dari_atas = dari_atas +t_font_judul + 8;
       kan->TextOutA(letak, dari_atas, nama_mesin+", "+model_mesin+", "+nama_pers);
       dari_atas = dari_atas + 10+8;
       kan->TextOutA(letak, dari_atas, tgl_data);
#endif
       int letak = 20;
       int dari_atas = 30;
       pnt->drawText(letak, dari_atas, "Test");
}

void Form_lap::paintEvent(QPaintEvent *)
{
#if 1
    qDebug("Paint");

    QPainter painter(this);
    painter.setPen(Qt::gray);
    QPen pen = painter.pen();
    pen.setWidth( 1 );
    painter.setPen( pen );


    n_kolom = 18; //jumlah kolom yang akan dipakai

    int d_x;
    int d_y;
    int lebar;
    int tinggi;
    int row_1;
    //int tinggi_font;
    int tinggi_judul;
    int jar_kol;
    int i;
    int letak;
    int dari_atas;
    int t_font_judul;
    QString sTem;

    //Color = Dasar->Color;

    tinggi_judul = 80;
    row_1 = 40;
    lebar = this->width() - 8; //10
    tinggi = this->height() - 8; //10
    jar_kol = lebar/n_kolom; //jarak antar kolom
    t_font_judul = 16;

    //kan->Brush->Color = Color;

    /* gambar kotak luar */
    //kan->Pen->Color = Garis->Color;
    painter.drawRect( 4, 4, lebar, tinggi);

    /* garis judul */
    lebar += 4;
    tinggi += 4;

    QPainterPath path;
    path.moveTo(4, tinggi_judul);
    path.lineTo(lebar, tinggi_judul);
    painter.drawPath( path );
    row_y[0] = tinggi_judul;

    /* row pertama */
    /** diberikan warna band terlebih dahulu **/
    //kan->Brush->Color = Garis->WarnaBand;
    //painter.drawRect(10, tinggi_judul, lebar, tinggi_judul+row_1+3);

    //kan->Brush->Color = Color;
    path.moveTo(4, tinggi_judul+row_1);
    path.lineTo(lebar, tinggi_judul+row_1);
    painter.drawPath( path );
    path.moveTo(4, tinggi_judul+row_1+2);
    path.lineTo(lebar, tinggi_judul+row_1+2);
    painter.drawPath( path );

    row_y[1] = tinggi_judul+row_1+2;
    kol_x[0] = 4; //tepi kiri
    /* garis kolom kebawah*/
    for (i=1; i< n_kolom; i++)
    {
        kol_x[i] = i*jar_kol;

        if (i>2 || i<7)
        {
            if (i != 11)
            {
                path.moveTo(i*jar_kol, tinggi_judul+row_1/2);
                path.lineTo(i*jar_kol, tinggi);
                painter.drawPath( path );
            }
        }

        if (i>7 || i<10)
        {
            if (i != 11)
            {
                path.moveTo(i*jar_kol, tinggi_judul+row_1/2);
                path.lineTo(i*jar_kol, tinggi);
                painter.drawPath( path );
            }
        }

        if (i==6 || i==10 || i==12 || i == 15 || i == 3)
        {
            path.moveTo(i*jar_kol, tinggi_judul);
            path.lineTo(i*jar_kol, tinggi);
            painter.drawPath( path );
        }

        if (i>16 || i< 3)
        {
            if (i != 11)
            {
                path.moveTo(i*jar_kol, tinggi_judul);
                path.lineTo(i*jar_kol, tinggi);
                painter.drawPath( path );
            }
        }
    }
    #if 1
    /* garis di row pertama ke kanan */
    path.moveTo(kol_x[3], tinggi_judul+row_1/2);
    path.lineTo(kol_x[10], tinggi_judul+row_1/2);
    painter.drawPath( path );

    path.moveTo(kol_x[12], tinggi_judul+row_1/2);
    path.lineTo(kol_x[17], tinggi_judul+row_1/2);
    painter.drawPath( path );


    // kan->LineTo(kol_x[16], tinggi_judul+row_1/2);

    /* garis paling bawah
          berdasarkan jumlah silinder yang akan diplot */

    path.moveTo(4, tinggi - 40);
    path.lineTo(lebar, tinggi - 40);
    painter.drawPath( path );
#endif
#endif
    info_teks(&painter);
}
