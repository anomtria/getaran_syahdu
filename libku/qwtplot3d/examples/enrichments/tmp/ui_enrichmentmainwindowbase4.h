/********************************************************************************
** Form generated from reading UI file 'enrichmentmainwindowbase4.ui'
**
** Created: Tue Sep 11 10:40:21 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENRICHMENTMAINWINDOWBASE4_H
#define UI_ENRICHMENTMAINWINDOWBASE4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QFrame *frame;
    QVBoxLayout *vboxLayout1;
    QLabel *label;
    QSlider *levelSlider;
    QHBoxLayout *hboxLayout1;
    QLabel *label_2;
    QSlider *widthSlider;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(8, 8, 8, 8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(frame);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        vboxLayout1->addWidget(label);

        levelSlider = new QSlider(centralWidget);
        levelSlider->setObjectName(QString::fromUtf8("levelSlider"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(levelSlider->sizePolicy().hasHeightForWidth());
        levelSlider->setSizePolicy(sizePolicy1);
        levelSlider->setMaximum(100);
        levelSlider->setValue(10);
        levelSlider->setOrientation(Qt::Vertical);
        levelSlider->setInvertedAppearance(true);
        levelSlider->setTickPosition(QSlider::TicksBelow);
        levelSlider->setTickInterval(10);

        vboxLayout1->addWidget(levelSlider);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        hboxLayout1->addWidget(label_2);

        widthSlider = new QSlider(centralWidget);
        widthSlider->setObjectName(QString::fromUtf8("widthSlider"));
        widthSlider->setEnabled(false);
        widthSlider->setMinimum(2);
        widthSlider->setMaximum(200);
        widthSlider->setValue(20);
        widthSlider->setOrientation(Qt::Horizontal);
        widthSlider->setTickPosition(QSlider::TicksBelow);

        hboxLayout1->addWidget(widthSlider);


        vboxLayout->addLayout(hboxLayout1);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Level</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Width</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENRICHMENTMAINWINDOWBASE4_H
