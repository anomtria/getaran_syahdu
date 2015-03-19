#include "dialog_report.h"
#include "ui_dialog_report.h"

Dialog_report::Dialog_report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_report)
{
    ui->setupUi(this);
}

Dialog_report::~Dialog_report()
{
    delete ui;
}

void Dialog_report::buat_table()
{
    int i;
    QTextCursor cursor( ui->edit->textCursor());
    cursor.movePosition(QTextCursor::Start);

    ui->edit->setText("Ini report");
    /*
    QTextTableFormat format;
    format.setHeight( 600 );
    format.setWidth( 800 );
    format.setCellPadding( 1 );
    format.setCellSpacing( 1 );
    format.setHeaderRowCount( 2 );

    QTextTable *table = cursor.insertTable(10, 5, format);
    */
    QTextTable *table = cursor.insertTable(10, 5 );


    QTextBlockFormat centerAlignment;
    centerAlignment.setAlignment(Qt::AlignHCenter);
    centerAlignment.setLineHeight( 30, QTextBlockFormat::FixedHeight);
    centerAlignment.setLeftMargin( 10 );
    centerAlignment.setRightMargin( 10 );
    QTextCursor cursor2;

    cursor2 = table->cellAt(0, 0).firstCursorPosition();
    cursor2.insertText(QString::fromUtf8("No"));
    cursor2.setBlockFormat(centerAlignment);

    for (i=1; i<9; i++)
    {

        cursor2 = table->cellAt(i, 0).firstCursorPosition();
        cursor2.setBlockFormat(centerAlignment);
        cursor2.insertText(QString::number(i+1) + "Sil");

    }



    /*
    int i, y;
    for (i=0; i<4; i++)
    {
        for (y=0;y<5; y++)
         QTextTable *table = cursor.insertTable( y, i );
            //QTextTable *table = cursor.insertTable( y, i, tableFormat);
    }*/

    //QTextTable *tbl;
    //tbl = new QTextTable( ui->edit );

}
