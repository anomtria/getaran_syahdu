#-------------------------------------------------
#
# Project created by QtCreator 2014-10-06T13:38:30
#
#-------------------------------------------------

QT      += core
QT      += gui
QT      += sql
QT      += network
QT      += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = online_vibration_monitoring
TEMPLATE = app

INCLUDEPATH +=$$PWD/libku/qwt-6.0.0/src

SOURCES += main.cpp \
    view/form_log.cpp \
    view/form_lap.cpp \
    view/dialog_setting.cpp \
    view/dialog_report.cpp \
    view/form_trend.cpp \
    view/form_note.cpp \
    model/file_setting.cpp \
    view/form_replay.cpp \
    model/udpsocket.cpp \
    libku/fft/fourierd.c \
    libku/fft/fftmisc.c \
    libku/windowing/windowkan.c \
    libku/windowing/buat_filter.c \
    view/util/show_grafik.cpp \
    view/util/show_table.cpp \
    model/database.cpp \
    view/util/set_value.cpp \
    view/mainwindow.cpp \
    view/util/show_alarm.cpp \
    model/mythread.cpp \
    model/signalprocessing.cpp \
    model/formula.cpp \
    controller/save_db.cpp \
    controller/save_setting.cpp \
    controller/get_db.cpp \
    controller/tampil_replay.cpp \
    controller/tampil_trend.cpp \
    controller/tampil_band_analisis.cpp

HEADERS  += \
    view/form_log.h \
    view/form_lap.h \
    view/dialog_setting.h \
    view/dialog_report.h \
    util/setting.h \
    util/msg_box.h \
    view/form_trend.h \
    view/form_note.h \
    model/file_setting.h \
    view/form_replay.h \
    model/udpsocket.h \
    libku/windowing/windowkan.h \
    libku/windowing/buat_filter.h \
    view/util/show_grafik.h \
    view/util/show_table.h \
    model/database.h \
    view/util/set_value.h \
    view/mainwindow.h \
    view/util/show_alarm.h \
    model/mythread.h \
    model/signalprocessing.h \
    model/formula.h \
    controller/save_db.h \
    controller/save_setting.h \
    controller/get_db.h \
    controller/tampil_replay.h \
    controller/tampil_trend.h \
    controller/tampil_band_analisis.h

FORMS    += \
    view/form_log.ui \
    view/form_lap.ui \
    view/dialog_report.ui \
    view/form_trend.ui \
    view/frontpage.ui \
    view/form_note.ui \
    view/form_replay.ui \
    view/dialog_setting.ui \
    view/mainwindow.ui

LIBS += -L$$PWD/libku/qwt-6.0.0/lib \
    -lqwt

RESOURCES += \
    icon.qrc
