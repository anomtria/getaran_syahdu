#include "form_note.h"
#include "ui_form_note.h"

extern struct d_global global;

Form_Note::Form_Note(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Note)
{
    ui->setupUi(this);
}

Form_Note::~Form_Note()
{
    delete ui;
}

void Form_Note::on_pb_close_clicked()
{
    this->close();
}

void Form_Note::on_pb_save_clicked()
{
    QString opt = this->ui->edit_opt->text();
    QString judul = this->ui->edit_judul->text();
    int tipe_data = this->ui->combo_tipe->currentIndex();
    int ch = this->ui->combo_ch->currentIndex();
    QString note = this->ui->catatan->toPlainText();

    dbase->save_database_note(global.db, KIND_TRENDING, opt, judul, tipe_data, ch, note);
    this->close();
}
