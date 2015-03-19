#ifndef MSG_BOX_H
#define MSG_BOX_H

#include <QMessageBox>
#include "util/setting.h"



#define msg_box(x) QMessageBox::warning(this, tr(DEF_JUDUL), tr(x),  \
                                QMessageBox::Cancel    \
                                | QMessageBox::Ok,      \
                                QMessageBox::Cancel)

#define error_box(x) QMessageBox::critical(this, tr(DEF_JUDUL), tr(x),  \
                                QMessageBox::Cancel    \
                                | QMessageBox::Ok,      \
                                QMessageBox::Ok)

#define info_box(x) QMessageBox::information(this, tr(DEF_JUDUL), tr(x),  \
                                QMessageBox::Ok,      \
                                QMessageBox::Ok)


#endif // MSG_BOX_H
