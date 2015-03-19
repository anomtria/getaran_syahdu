#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <QWidget>
#include <QDebug>
#include <QDesktopWidget>
#include <QTimer>
#include <QMenu>
#include <QClipboard>
#include <QtSql>
#include <QUdpSocket>
#include <QThread>
#include <unistd.h>

#include "qwt_plot.h"
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include "qwt_plot_grid.h"
#include <qwt.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include <qwt_legend.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

#include "util/setting.h"

#include "model/signalprocessing.h"

class UdpSocket
{
public:
    UdpSocket();

    void ada_udp_data();

private slots:


private:
    signalProcessing *signal;

};

#endif // UDPSOCKET_H
