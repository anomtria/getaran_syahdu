#ifndef FORM_NOTE_H
#define FORM_NOTE_H

#include <QWidget>

#include "util/setting.h"
#include "controller/save_db.h"

namespace Ui {
class Form_Note;
}

class Form_Note : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_Note(QWidget *parent = 0);
    ~Form_Note();
    
private slots:
    void on_pb_close_clicked();

    void on_pb_save_clicked();

private:
    Ui::Form_Note *ui;

    save_db *dbase;
};

#endif // FORM_NOTE_H
