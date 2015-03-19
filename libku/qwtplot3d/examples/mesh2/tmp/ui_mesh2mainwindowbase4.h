/********************************************************************************
** Form generated from reading UI file 'mesh2mainwindowbase4.ui'
**
** Created: Tue Sep 11 10:40:10 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESH2MAINWINDOWBASE4_H
#define UI_MESH2MAINWINDOWBASE4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *hboxLayout1;
    QPushButton *normButton;
    QPushButton *lighting;
    QCheckBox *lightingswitch;
    QVBoxLayout *vboxLayout;
    QLabel *label_2;
    QSlider *offsSlider;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QLabel *label_3;
    QSlider *resSlider;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QFrame *frame;
    QVBoxLayout *vboxLayout2;
    QVBoxLayout *vboxLayout3;
    QCheckBox *projection;
    QCheckBox *colorlegend;
    QCheckBox *autoscale;
    QCheckBox *mouseinput;
    QCheckBox *shader;
    QVBoxLayout *vboxLayout4;
    QLabel *label;
    QHBoxLayout *hboxLayout3;
    QSlider *normalsquality;
    QSlider *normalslength;

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
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        normButton = new QPushButton(centralWidget);
        normButton->setObjectName(QString::fromUtf8("normButton"));

        hboxLayout1->addWidget(normButton);

        lighting = new QPushButton(centralWidget);
        lighting->setObjectName(QString::fromUtf8("lighting"));
        lighting->setEnabled(false);

        hboxLayout1->addWidget(lighting);

        lightingswitch = new QCheckBox(centralWidget);
        lightingswitch->setObjectName(QString::fromUtf8("lightingswitch"));

        hboxLayout1->addWidget(lightingswitch);

        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        vboxLayout->addWidget(label_2);

        offsSlider = new QSlider(centralWidget);
        offsSlider->setObjectName(QString::fromUtf8("offsSlider"));
        offsSlider->setMaximum(30);
        offsSlider->setPageStep(5);
        offsSlider->setValue(5);
        offsSlider->setOrientation(Qt::Horizontal);
        offsSlider->setTickPosition(QSlider::TicksAbove);
        offsSlider->setTickInterval(2);

        vboxLayout->addWidget(offsSlider);


        hboxLayout1->addLayout(vboxLayout);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        vboxLayout1->addWidget(label_3);

        resSlider = new QSlider(centralWidget);
        resSlider->setObjectName(QString::fromUtf8("resSlider"));
        resSlider->setMinimum(1);
        resSlider->setMaximum(100);
        resSlider->setOrientation(Qt::Horizontal);
        resSlider->setTickPosition(QSlider::TicksAbove);
        resSlider->setTickInterval(5);

        vboxLayout1->addWidget(resSlider);


        hboxLayout1->addLayout(vboxLayout1);


        hboxLayout->addLayout(hboxLayout1);

        spacerItem1 = new QSpacerItem(71, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);

        hboxLayout2->addWidget(frame);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        projection = new QCheckBox(centralWidget);
        projection->setObjectName(QString::fromUtf8("projection"));
        projection->setChecked(true);

        vboxLayout3->addWidget(projection);

        colorlegend = new QCheckBox(centralWidget);
        colorlegend->setObjectName(QString::fromUtf8("colorlegend"));

        vboxLayout3->addWidget(colorlegend);

        autoscale = new QCheckBox(centralWidget);
        autoscale->setObjectName(QString::fromUtf8("autoscale"));
        autoscale->setChecked(true);

        vboxLayout3->addWidget(autoscale);

        mouseinput = new QCheckBox(centralWidget);
        mouseinput->setObjectName(QString::fromUtf8("mouseinput"));
        mouseinput->setChecked(true);

        vboxLayout3->addWidget(mouseinput);

        shader = new QCheckBox(centralWidget);
        shader->setObjectName(QString::fromUtf8("shader"));
        shader->setChecked(true);

        vboxLayout3->addWidget(shader);


        vboxLayout2->addLayout(vboxLayout3);

        vboxLayout4 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout4->setSpacing(6);
#endif
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        vboxLayout4->addWidget(label);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        normalsquality = new QSlider(centralWidget);
        normalsquality->setObjectName(QString::fromUtf8("normalsquality"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(3));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(normalsquality->sizePolicy().hasHeightForWidth());
        normalsquality->setSizePolicy(sizePolicy1);
        normalsquality->setMinimum(3);
        normalsquality->setMaximum(32);
        normalsquality->setPageStep(4);
        normalsquality->setValue(3);
        normalsquality->setOrientation(Qt::Vertical);
        normalsquality->setInvertedAppearance(true);
        normalsquality->setTickPosition(QSlider::TicksAbove);

        hboxLayout3->addWidget(normalsquality);

        normalslength = new QSlider(centralWidget);
        normalslength->setObjectName(QString::fromUtf8("normalslength"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(7));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(normalslength->sizePolicy().hasHeightForWidth());
        normalslength->setSizePolicy(sizePolicy2);
        normalslength->setMinimum(1);
        normalslength->setMaximum(100);
        normalslength->setPageStep(5);
        normalslength->setValue(8);
        normalslength->setOrientation(Qt::Vertical);
        normalslength->setInvertedAppearance(true);
        normalslength->setTickPosition(QSlider::TicksAbove);

        hboxLayout3->addWidget(normalslength);


        vboxLayout4->addLayout(hboxLayout3);


        vboxLayout2->addLayout(vboxLayout4);


        hboxLayout2->addLayout(vboxLayout2);


        gridLayout->addLayout(hboxLayout2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(lightingswitch, SIGNAL(toggled(bool)), lighting, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mesh2", 0, QApplication::UnicodeUTF8));
        normButton->setText(QApplication::translate("MainWindow", "Std", 0, QApplication::UnicodeUTF8));
        lighting->setText(QApplication::translate("MainWindow", "Lighting", 0, QApplication::UnicodeUTF8));
        lightingswitch->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Polygon Offset</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Resolution</p></body></html>", 0, QApplication::UnicodeUTF8));
        projection->setText(QApplication::translate("MainWindow", "Ortho", 0, QApplication::UnicodeUTF8));
        colorlegend->setText(QApplication::translate("MainWindow", "Legend", 0, QApplication::UnicodeUTF8));
        autoscale->setText(QApplication::translate("MainWindow", "Autoscale", 0, QApplication::UnicodeUTF8));
        mouseinput->setText(QApplication::translate("MainWindow", "Mouse", 0, QApplication::UnicodeUTF8));
        shader->setText(QApplication::translate("MainWindow", "Shading", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Normals</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESH2MAINWINDOWBASE4_H
