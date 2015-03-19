#ifndef FORM_LAP_H
#define FORM_LAP_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMenu>
#include <QPixmap>
#include <QClipboard>

namespace Ui {
class Form_lap;
}

class Form_lap : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_lap(QWidget *parent = 0);
    ~Form_lap();
    
private:
    Ui::Form_lap *ui;
    int n_kolom;
    int kol_x[19];
    int row_y[40];

private slots:
    void paintEvent(QPaintEvent *);
    void copy_clipboard();
    void info_teks(QPainter *pnt);
};

#endif // FORM_LAP_H
