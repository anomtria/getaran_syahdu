#if QT_VERSION >= 0x050000
    #include <QApplication>
#else
    #include <QtGui/QApplication>
#endif

#include "view/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;

    m.showMaximized();
    return a.exec();
}

static char buf_command[4096];

int proses_q( QSqlQuery *q, char *s, ...)
{
    QSqlError er;
    va_list args;
    int i;

    va_start (args, s);

       /* For this to work, printbuffer must be larger than
        * anything we ever want to print.
        */
    i = vsprintf (buf_command, s, args);
    va_end (args);

    //debug("%s(): %s",__FUNCTION__, buf_command );

    if (!q->exec( buf_command ))
    {
        er = q->lastError();
        return -1;
    }
    else
    {
        /* untuk SQLITE harus manual ditunjukkan ke first sebelum bisa dipakai */
        q->first();
        /* SQLITE size juga pasti akan -1 */
        //debug("%s(): OK, %d row", __FUNCTION__, q->size());
    }
    return 0;
}
