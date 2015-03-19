#include "form_log.h"
#include "ui_form_log.h"

Form_log::Form_log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_log)
{
    ui->setupUi(this);

    nomer = 0;
    buf_lay = (char *) malloc(1024);
    buf_no = (char *) malloc(1024);

}

Form_log::~Form_log()
{
    delete ui;
}

void Form_log::out(const char *fmt, ...)
{
    QDateTime dt;
    va_list args;
    int i;

    va_start (args, fmt);

       /* For this to work, printbuffer must be larger than
        * anything we ever want to print.
        */
    i = vsprintf (buf_lay, fmt, args);
    va_end (args);

    dt = QDateTime::currentDateTime();

    /* Print the string */
    #if QT_VERSION >= 0x050000
        sprintf(buf_no, "%d. %s.", nomer++, dt.toString().toLocal8Bit().data());
    #else
        sprintf(buf_no, "%d. %s.", nomer++, dt.toString().toAscii().data());
    #endif


    #if (debug_splash == 1)
    extern QSplashScreen *p_sp;
    extern int belum_show;

    if (belum_show == 1)
        p_sp->showMessage( buf_lay );
    #endif

    strcat(buf_lay, "\r\n");
    strcat(buf_no, buf_lay);

    ui->memo->insertPlainText( buf_no );

    /* supaya cursor selalu menunjuk paling akhir */
    QTextCursor c =  ui->memo->textCursor();
    c.movePosition(QTextCursor::End);
    ui->memo->setTextCursor(c);
}
