/********************************************************************************
** Form generated from reading UI file 'StatsWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSWINDOW_H
#define UI_STATSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatsWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *lblStationHeader;
    QLabel *lblProcessedHeader;
    QLabel *lblBufferHeader;
    QLabel *stationName1;
    QLCDNumber *lcdProcessed1;
    QLCDNumber *lcdBuffer1;
    QLabel *stationName2;
    QLCDNumber *lcdProcessed2;
    QLCDNumber *lcdBuffer2;
    QLabel *stationName3;
    QLCDNumber *lcdProcessed3;
    QLCDNumber *lcdBuffer3;
    QLabel *stationName4;
    QLCDNumber *lcdProcessed4;
    QLCDNumber *lcdBuffer4;
    QLabel *stationName5;
    QLCDNumber *lcdProcessed5;
    QLCDNumber *lcdBuffer5;
    QLabel *stationName6;
    QLCDNumber *lcdProcessed6;
    QLCDNumber *lcdBuffer6;

    void setupUi(QWidget *StatsWindow)
    {
        if (StatsWindow->objectName().isEmpty())
            StatsWindow->setObjectName(QString::fromUtf8("StatsWindow"));
        StatsWindow->resize(480, 260);
        gridLayout = new QGridLayout(StatsWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblStationHeader = new QLabel(StatsWindow);
        lblStationHeader->setObjectName(QString::fromUtf8("lblStationHeader"));

        gridLayout->addWidget(lblStationHeader, 0, 0, 1, 1);

        lblProcessedHeader = new QLabel(StatsWindow);
        lblProcessedHeader->setObjectName(QString::fromUtf8("lblProcessedHeader"));

        gridLayout->addWidget(lblProcessedHeader, 0, 1, 1, 1);

        lblBufferHeader = new QLabel(StatsWindow);
        lblBufferHeader->setObjectName(QString::fromUtf8("lblBufferHeader"));

        gridLayout->addWidget(lblBufferHeader, 0, 2, 1, 1);

        stationName1 = new QLabel(StatsWindow);
        stationName1->setObjectName(QString::fromUtf8("stationName1"));

        gridLayout->addWidget(stationName1, 1, 0, 1, 1);

        lcdProcessed1 = new QLCDNumber(StatsWindow);
        lcdProcessed1->setObjectName(QString::fromUtf8("lcdProcessed1"));
        lcdProcessed1->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdProcessed1, 1, 1, 1, 1);

        lcdBuffer1 = new QLCDNumber(StatsWindow);
        lcdBuffer1->setObjectName(QString::fromUtf8("lcdBuffer1"));
        lcdBuffer1->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdBuffer1, 1, 2, 1, 1);

        stationName2 = new QLabel(StatsWindow);
        stationName2->setObjectName(QString::fromUtf8("stationName2"));

        gridLayout->addWidget(stationName2, 2, 0, 1, 1);

        lcdProcessed2 = new QLCDNumber(StatsWindow);
        lcdProcessed2->setObjectName(QString::fromUtf8("lcdProcessed2"));
        lcdProcessed2->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdProcessed2, 2, 1, 1, 1);

        lcdBuffer2 = new QLCDNumber(StatsWindow);
        lcdBuffer2->setObjectName(QString::fromUtf8("lcdBuffer2"));
        lcdBuffer2->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdBuffer2, 2, 2, 1, 1);

        stationName3 = new QLabel(StatsWindow);
        stationName3->setObjectName(QString::fromUtf8("stationName3"));

        gridLayout->addWidget(stationName3, 3, 0, 1, 1);

        lcdProcessed3 = new QLCDNumber(StatsWindow);
        lcdProcessed3->setObjectName(QString::fromUtf8("lcdProcessed3"));
        lcdProcessed3->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdProcessed3, 3, 1, 1, 1);

        lcdBuffer3 = new QLCDNumber(StatsWindow);
        lcdBuffer3->setObjectName(QString::fromUtf8("lcdBuffer3"));
        lcdBuffer3->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdBuffer3, 3, 2, 1, 1);

        stationName4 = new QLabel(StatsWindow);
        stationName4->setObjectName(QString::fromUtf8("stationName4"));

        gridLayout->addWidget(stationName4, 4, 0, 1, 1);

        lcdProcessed4 = new QLCDNumber(StatsWindow);
        lcdProcessed4->setObjectName(QString::fromUtf8("lcdProcessed4"));
        lcdProcessed4->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdProcessed4, 4, 1, 1, 1);

        lcdBuffer4 = new QLCDNumber(StatsWindow);
        lcdBuffer4->setObjectName(QString::fromUtf8("lcdBuffer4"));
        lcdBuffer4->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdBuffer4, 4, 2, 1, 1);

        stationName5 = new QLabel(StatsWindow);
        stationName5->setObjectName(QString::fromUtf8("stationName5"));

        gridLayout->addWidget(stationName5, 5, 0, 1, 1);

        lcdProcessed5 = new QLCDNumber(StatsWindow);
        lcdProcessed5->setObjectName(QString::fromUtf8("lcdProcessed5"));
        lcdProcessed5->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdProcessed5, 5, 1, 1, 1);

        lcdBuffer5 = new QLCDNumber(StatsWindow);
        lcdBuffer5->setObjectName(QString::fromUtf8("lcdBuffer5"));
        lcdBuffer5->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdBuffer5, 5, 2, 1, 1);

        stationName6 = new QLabel(StatsWindow);
        stationName6->setObjectName(QString::fromUtf8("stationName6"));

        gridLayout->addWidget(stationName6, 6, 0, 1, 1);

        lcdProcessed6 = new QLCDNumber(StatsWindow);
        lcdProcessed6->setObjectName(QString::fromUtf8("lcdProcessed6"));
        lcdProcessed6->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdProcessed6, 6, 1, 1, 1);

        lcdBuffer6 = new QLCDNumber(StatsWindow);
        lcdBuffer6->setObjectName(QString::fromUtf8("lcdBuffer6"));
        lcdBuffer6->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdBuffer6, 6, 2, 1, 1);


        retranslateUi(StatsWindow);

        QMetaObject::connectSlotsByName(StatsWindow);
    } // setupUi

    void retranslateUi(QWidget *StatsWindow)
    {
        StatsWindow->setWindowTitle(QCoreApplication::translate("StatsWindow", "Production Stats", nullptr));
        lblStationHeader->setText(QCoreApplication::translate("StatsWindow", "Station", nullptr));
        lblProcessedHeader->setText(QCoreApplication::translate("StatsWindow", "Processed", nullptr));
        lblBufferHeader->setText(QCoreApplication::translate("StatsWindow", "Buffer Size", nullptr));
        stationName1->setText(QCoreApplication::translate("StatsWindow", "Assembler-1", nullptr));
        stationName2->setText(QCoreApplication::translate("StatsWindow", "Assembler-2", nullptr));
        stationName3->setText(QCoreApplication::translate("StatsWindow", "Tester", nullptr));
        stationName4->setText(QCoreApplication::translate("StatsWindow", "QualityControl", nullptr));
        stationName5->setText(QCoreApplication::translate("StatsWindow", "Packer", nullptr));
        stationName6->setText(QCoreApplication::translate("StatsWindow", "Shipping", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatsWindow: public Ui_StatsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSWINDOW_H
