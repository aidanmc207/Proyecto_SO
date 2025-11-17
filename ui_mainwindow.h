/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *layoutWidget;
    QHBoxLayout *toolbarLayout;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QSpacerItem *hspacer;
    QComboBox *cmbSpeed;
    QWidget *layoutWidget1;
    QGridLayout *stationsLayout;
    QGroupBox *grpAssembler;
    QVBoxLayout *vboxLayout;
    QLabel *lblAsmState;
    QLabel *lblAsm1Processed;
    QLabel *lblAsm2Processed;
    QProgressBar *barAsm1;
    QProgressBar *barAsm2;
    QHBoxLayout *assemblerControls;
    QPushButton *btnAsmStart;
    QPushButton *btnAsmPause;
    QPushButton *btnAsmStop;
    QGroupBox *grpTester;
    QVBoxLayout *vboxLayout1;
    QLabel *lblTesState;
    QLabel *lblTesProcessed;
    QProgressBar *barTes;
    QHBoxLayout *testerControls;
    QPushButton *btnTesStart;
    QPushButton *btnTesPause;
    QPushButton *btnTesStop;
    QGroupBox *groupBoxQC;
    QVBoxLayout *vboxLayout2;
    QLabel *lblQCState;
    QLabel *lblQCProcessed;
    QLabel *lblQCRework;
    QProgressBar *barQC;
    QHBoxLayout *qcControls;
    QPushButton *btnQCStart;
    QPushButton *btnQCPause;
    QPushButton *btnQCStop;
    QGroupBox *grpPacker;
    QVBoxLayout *vboxLayout3;
    QLabel *lblPacState;
    QLabel *lblPacProcessed;
    QProgressBar *barPac;
    QHBoxLayout *packerControls;
    QPushButton *btnPacStart;
    QPushButton *btnPacPause;
    QPushButton *btnPacStop;
    QGroupBox *grpShipping;
    QVBoxLayout *vboxLayout4;
    QLabel *lblShipState;
    QLabel *lblShipProcessed;
    QProgressBar *barShip;
    QHBoxLayout *shippingControls;
    QPushButton *btnShipStart;
    QPushButton *btnShipPause;
    QPushButton *btnShipStop;
    QPlainTextEdit *txtLogs;
    QLabel *lblTotalRework;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setObjectName(QString::fromUtf8("rootLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1180, 1050));
        layoutWidget = new QWidget(scrollAreaWidgetContents_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1180, 28));
        toolbarLayout = new QHBoxLayout(layoutWidget);
        toolbarLayout->setObjectName(QString::fromUtf8("toolbarLayout"));
        toolbarLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        toolbarLayout->addWidget(btnStart);

        btnPause = new QPushButton(layoutWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));

        toolbarLayout->addWidget(btnPause);

        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        toolbarLayout->addWidget(btnStop);

        hspacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        toolbarLayout->addItem(hspacer);

        cmbSpeed = new QComboBox(layoutWidget);
        cmbSpeed->setObjectName(QString::fromUtf8("cmbSpeed"));

        toolbarLayout->addWidget(cmbSpeed);

        layoutWidget1 = new QWidget(scrollAreaWidgetContents_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 30, 1180, 600));
        stationsLayout = new QGridLayout(layoutWidget1);
        stationsLayout->setObjectName(QString::fromUtf8("stationsLayout"));
        stationsLayout->setContentsMargins(0, 0, 0, 0);
        grpAssembler = new QGroupBox(layoutWidget1);
        grpAssembler->setObjectName(QString::fromUtf8("grpAssembler"));
        vboxLayout = new QVBoxLayout(grpAssembler);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        lblAsmState = new QLabel(grpAssembler);
        lblAsmState->setObjectName(QString::fromUtf8("lblAsmState"));

        vboxLayout->addWidget(lblAsmState);

        lblAsm1Processed = new QLabel(grpAssembler);
        lblAsm1Processed->setObjectName(QString::fromUtf8("lblAsm1Processed"));

        vboxLayout->addWidget(lblAsm1Processed);

        lblAsm2Processed = new QLabel(grpAssembler);
        lblAsm2Processed->setObjectName(QString::fromUtf8("lblAsm2Processed"));

        vboxLayout->addWidget(lblAsm2Processed);

        barAsm1 = new QProgressBar(grpAssembler);
        barAsm1->setObjectName(QString::fromUtf8("barAsm1"));
        barAsm1->setValue(0);

        vboxLayout->addWidget(barAsm1);

        barAsm2 = new QProgressBar(grpAssembler);
        barAsm2->setObjectName(QString::fromUtf8("barAsm2"));
        barAsm2->setValue(0);

        vboxLayout->addWidget(barAsm2);

        assemblerControls = new QHBoxLayout();
        assemblerControls->setObjectName(QString::fromUtf8("assemblerControls"));
        btnAsmStart = new QPushButton(grpAssembler);
        btnAsmStart->setObjectName(QString::fromUtf8("btnAsmStart"));

        assemblerControls->addWidget(btnAsmStart);

        btnAsmPause = new QPushButton(grpAssembler);
        btnAsmPause->setObjectName(QString::fromUtf8("btnAsmPause"));

        assemblerControls->addWidget(btnAsmPause);

        btnAsmStop = new QPushButton(grpAssembler);
        btnAsmStop->setObjectName(QString::fromUtf8("btnAsmStop"));

        assemblerControls->addWidget(btnAsmStop);


        vboxLayout->addLayout(assemblerControls);


        stationsLayout->addWidget(grpAssembler, 0, 0, 1, 1);

        grpTester = new QGroupBox(layoutWidget1);
        grpTester->setObjectName(QString::fromUtf8("grpTester"));
        vboxLayout1 = new QVBoxLayout(grpTester);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lblTesState = new QLabel(grpTester);
        lblTesState->setObjectName(QString::fromUtf8("lblTesState"));

        vboxLayout1->addWidget(lblTesState);

        lblTesProcessed = new QLabel(grpTester);
        lblTesProcessed->setObjectName(QString::fromUtf8("lblTesProcessed"));

        vboxLayout1->addWidget(lblTesProcessed);

        barTes = new QProgressBar(grpTester);
        barTes->setObjectName(QString::fromUtf8("barTes"));
        barTes->setValue(0);

        vboxLayout1->addWidget(barTes);

        testerControls = new QHBoxLayout();
        testerControls->setObjectName(QString::fromUtf8("testerControls"));
        btnTesStart = new QPushButton(grpTester);
        btnTesStart->setObjectName(QString::fromUtf8("btnTesStart"));

        testerControls->addWidget(btnTesStart);

        btnTesPause = new QPushButton(grpTester);
        btnTesPause->setObjectName(QString::fromUtf8("btnTesPause"));

        testerControls->addWidget(btnTesPause);

        btnTesStop = new QPushButton(grpTester);
        btnTesStop->setObjectName(QString::fromUtf8("btnTesStop"));

        testerControls->addWidget(btnTesStop);


        vboxLayout1->addLayout(testerControls);


        stationsLayout->addWidget(grpTester, 0, 1, 1, 1);

        groupBoxQC = new QGroupBox(layoutWidget1);
        groupBoxQC->setObjectName(QString::fromUtf8("groupBoxQC"));
        vboxLayout2 = new QVBoxLayout(groupBoxQC);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lblQCState = new QLabel(groupBoxQC);
        lblQCState->setObjectName(QString::fromUtf8("lblQCState"));

        vboxLayout2->addWidget(lblQCState);

        lblQCProcessed = new QLabel(groupBoxQC);
        lblQCProcessed->setObjectName(QString::fromUtf8("lblQCProcessed"));

        vboxLayout2->addWidget(lblQCProcessed);

        lblQCRework = new QLabel(groupBoxQC);
        lblQCRework->setObjectName(QString::fromUtf8("lblQCRework"));

        vboxLayout2->addWidget(lblQCRework);

        barQC = new QProgressBar(groupBoxQC);
        barQC->setObjectName(QString::fromUtf8("barQC"));
        barQC->setValue(0);

        vboxLayout2->addWidget(barQC);

        qcControls = new QHBoxLayout();
        qcControls->setObjectName(QString::fromUtf8("qcControls"));
        btnQCStart = new QPushButton(groupBoxQC);
        btnQCStart->setObjectName(QString::fromUtf8("btnQCStart"));

        qcControls->addWidget(btnQCStart);

        btnQCPause = new QPushButton(groupBoxQC);
        btnQCPause->setObjectName(QString::fromUtf8("btnQCPause"));

        qcControls->addWidget(btnQCPause);

        btnQCStop = new QPushButton(groupBoxQC);
        btnQCStop->setObjectName(QString::fromUtf8("btnQCStop"));

        qcControls->addWidget(btnQCStop);


        vboxLayout2->addLayout(qcControls);


        stationsLayout->addWidget(groupBoxQC, 1, 0, 1, 1);

        grpPacker = new QGroupBox(layoutWidget1);
        grpPacker->setObjectName(QString::fromUtf8("grpPacker"));
        vboxLayout3 = new QVBoxLayout(grpPacker);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        lblPacState = new QLabel(grpPacker);
        lblPacState->setObjectName(QString::fromUtf8("lblPacState"));
        lblPacState->setEnabled(true);

        vboxLayout3->addWidget(lblPacState);

        lblPacProcessed = new QLabel(grpPacker);
        lblPacProcessed->setObjectName(QString::fromUtf8("lblPacProcessed"));

        vboxLayout3->addWidget(lblPacProcessed);

        barPac = new QProgressBar(grpPacker);
        barPac->setObjectName(QString::fromUtf8("barPac"));
        barPac->setValue(0);

        vboxLayout3->addWidget(barPac);

        packerControls = new QHBoxLayout();
        packerControls->setObjectName(QString::fromUtf8("packerControls"));
        btnPacStart = new QPushButton(grpPacker);
        btnPacStart->setObjectName(QString::fromUtf8("btnPacStart"));

        packerControls->addWidget(btnPacStart);

        btnPacPause = new QPushButton(grpPacker);
        btnPacPause->setObjectName(QString::fromUtf8("btnPacPause"));

        packerControls->addWidget(btnPacPause);

        btnPacStop = new QPushButton(grpPacker);
        btnPacStop->setObjectName(QString::fromUtf8("btnPacStop"));

        packerControls->addWidget(btnPacStop);


        vboxLayout3->addLayout(packerControls);


        stationsLayout->addWidget(grpPacker, 1, 1, 1, 1);

        grpShipping = new QGroupBox(layoutWidget1);
        grpShipping->setObjectName(QString::fromUtf8("grpShipping"));
        vboxLayout4 = new QVBoxLayout(grpShipping);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        lblShipState = new QLabel(grpShipping);
        lblShipState->setObjectName(QString::fromUtf8("lblShipState"));

        vboxLayout4->addWidget(lblShipState);

        lblShipProcessed = new QLabel(grpShipping);
        lblShipProcessed->setObjectName(QString::fromUtf8("lblShipProcessed"));

        vboxLayout4->addWidget(lblShipProcessed);

        barShip = new QProgressBar(grpShipping);
        barShip->setObjectName(QString::fromUtf8("barShip"));
        barShip->setValue(0);

        vboxLayout4->addWidget(barShip);

        shippingControls = new QHBoxLayout();
        shippingControls->setObjectName(QString::fromUtf8("shippingControls"));
        btnShipStart = new QPushButton(grpShipping);
        btnShipStart->setObjectName(QString::fromUtf8("btnShipStart"));

        shippingControls->addWidget(btnShipStart);

        btnShipPause = new QPushButton(grpShipping);
        btnShipPause->setObjectName(QString::fromUtf8("btnShipPause"));

        shippingControls->addWidget(btnShipPause);

        btnShipStop = new QPushButton(grpShipping);
        btnShipStop->setObjectName(QString::fromUtf8("btnShipStop"));

        shippingControls->addWidget(btnShipStop);


        vboxLayout4->addLayout(shippingControls);


        stationsLayout->addWidget(grpShipping, 2, 0, 1, 1);

        txtLogs = new QPlainTextEdit(scrollAreaWidgetContents_2);
        txtLogs->setObjectName(QString::fromUtf8("txtLogs"));
        txtLogs->setGeometry(QRect(0, 510, 630, 180));
        txtLogs->setReadOnly(true);
        lblTotalRework = new QLabel(scrollAreaWidgetContents_2);
        lblTotalRework->setObjectName(QString::fromUtf8("lblTotalRework"));
        lblTotalRework->setGeometry(QRect(240, 485, 132, 18));
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        rootLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Production Line Simulator", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#if QT_CONFIG(tooltip)
        cmbSpeed->setToolTip(QCoreApplication::translate("MainWindow", "Production speed", nullptr));
#endif // QT_CONFIG(tooltip)
        grpAssembler->setTitle(QCoreApplication::translate("MainWindow", "Assembler", nullptr));
        lblAsmState->setText(QString());
        lblAsm1Processed->setText(QString());
        lblAsm2Processed->setText(QString());
        btnAsmStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnAsmPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnAsmStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        grpTester->setTitle(QCoreApplication::translate("MainWindow", "Tester", nullptr));
        lblTesState->setText(QString());
        lblTesProcessed->setText(QString());
        btnTesStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnTesPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnTesStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        groupBoxQC->setTitle(QCoreApplication::translate("MainWindow", "Quality Control", nullptr));
        lblQCState->setText(QString());
        lblQCProcessed->setText(QString());
        lblQCRework->setText(QString());
        btnQCStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnQCPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnQCStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        grpPacker->setTitle(QCoreApplication::translate("MainWindow", "Packer", nullptr));
        lblPacState->setText(QString());
        lblPacProcessed->setText(QString());
        btnPacStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnPacPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnPacStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        grpShipping->setTitle(QCoreApplication::translate("MainWindow", "Shipping", nullptr));
        lblShipState->setText(QString());
        lblShipProcessed->setText(QString());
        btnShipStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnShipPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnShipStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        lblTotalRework->setText(QCoreApplication::translate("MainWindow", "Total Reworks:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
