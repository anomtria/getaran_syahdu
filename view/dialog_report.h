#ifndef DIALOG_REPORT_H
#define DIALOG_REPORT_H

#include <QDialog>
#include <QTextTable>

namespace Ui {
class Dialog_report;
}

class Dialog_report : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_report(QWidget *parent = 0);
    ~Dialog_report();
    
public slots:
    void buat_table();

private:
    Ui::Dialog_report *ui;
};

#endif // DIALOG_REPORT_H
