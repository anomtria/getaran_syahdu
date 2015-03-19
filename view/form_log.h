#ifndef FORM_LOG_H
#define FORM_LOG_H

#include <QDialog>
#include <stdarg.h>
#include <stdio.h>
#include <QDateTime>

namespace Ui {
class Form_log;
}

class Form_log : public QDialog
{
    Q_OBJECT
    
public:
    explicit Form_log(QWidget *parent = 0);
    ~Form_log();
    void out(const char *fmt, ...);
    void out_trend(const char *fmt, ...);
    
private:
    Ui::Form_log *ui;

protected:
    //QString ss;
    int nomer;
    char *buf_lay;
    char *buf_no;
};

#endif // FORM_LOG_H
