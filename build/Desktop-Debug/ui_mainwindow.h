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
    QGroupBox *grpPacker;
    QVBoxLayout *vboxLayout;
    QLabel *lblPacState;
    QLabel *lblPacProcessed;
    QProgressBar *barPac;
    QGroupBox *grpTester;
    QVBoxLayout *vboxLayout1;
    QLabel *lblTesState;
    QLabel *lblTesProcessed;
    QProgressBar *barTes;
    QGroupBox *groupBoxQC;
    QVBoxLayout *verticalLayout;
    QLabel *lblQCState;
    QLabel *lblQCProcessed;
    QLabel *lblQCRework;
    QProgressBar *barQC;
    QGroupBox *grpAssembler;
    QVBoxLayout *vboxLayout2;
    QLabel *lblAsmState;
    QLabel *lblAsm1Processed;
    QLabel *lblAsm2Processed;
    QProgressBar *barAsm1;
    QProgressBar *barAsm2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblShipState;
    QLabel *lblShipProcessed;
    QProgressBar *barShip;
    QPlainTextEdit *txtLogs;
    QLabel *lblTotalRework;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(648, 750);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setObjectName(QString::fromUtf8("rootLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 628, 707));
        layoutWidget = new QWidget(scrollAreaWidgetContents_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 630, 28));
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
        layoutWidget1->setGeometry(QRect(0, 30, 634, 177));
        stationsLayout = new QGridLayout(layoutWidget1);
        stationsLayout->setObjectName(QString::fromUtf8("stationsLayout"));
        stationsLayout->setContentsMargins(0, 0, 0, 0);
        grpPacker = new QGroupBox(layoutWidget1);
        grpPacker->setObjectName(QString::fromUtf8("grpPacker"));
        vboxLayout = new QVBoxLayout(grpPacker);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        lblPacState = new QLabel(grpPacker);
        lblPacState->setObjectName(QString::fromUtf8("lblPacState"));
        lblPacState->setEnabled(true);

        vboxLayout->addWidget(lblPacState);

        lblPacProcessed = new QLabel(grpPacker);
        lblPacProcessed->setObjectName(QString::fromUtf8("lblPacProcessed"));

        vboxLayout->addWidget(lblPacProcessed);

        barPac = new QProgressBar(grpPacker);
        barPac->setObjectName(QString::fromUtf8("barPac"));
        barPac->setValue(0);

        vboxLayout->addWidget(barPac);


        stationsLayout->addWidget(grpPacker, 0, 3, 1, 1);

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


        stationsLayout->addWidget(grpTester, 0, 1, 1, 1);

        groupBoxQC = new QGroupBox(layoutWidget1);
        groupBoxQC->setObjectName(QString::fromUtf8("groupBoxQC"));
        verticalLayout = new QVBoxLayout(groupBoxQC);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblQCState = new QLabel(groupBoxQC);
        lblQCState->setObjectName(QString::fromUtf8("lblQCState"));

        verticalLayout->addWidget(lblQCState);

        lblQCProcessed = new QLabel(groupBoxQC);
        lblQCProcessed->setObjectName(QString::fromUtf8("lblQCProcessed"));

        verticalLayout->addWidget(lblQCProcessed);

        lblQCRework = new QLabel(groupBoxQC);
        lblQCRework->setObjectName(QString::fromUtf8("lblQCRework"));

        verticalLayout->addWidget(lblQCRework);

        barQC = new QProgressBar(groupBoxQC);
        barQC->setObjectName(QString::fromUtf8("barQC"));
        barQC->setValue(0);

        verticalLayout->addWidget(barQC);


        stationsLayout->addWidget(groupBoxQC, 0, 2, 1, 1, Qt::AlignHCenter);

        grpAssembler = new QGroupBox(layoutWidget1);
        grpAssembler->setObjectName(QString::fromUtf8("grpAssembler"));
        vboxLayout2 = new QVBoxLayout(grpAssembler);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lblAsmState = new QLabel(grpAssembler);
        lblAsmState->setObjectName(QString::fromUtf8("lblAsmState"));

        vboxLayout2->addWidget(lblAsmState);

        lblAsm1Processed = new QLabel(grpAssembler);
        lblAsm1Processed->setObjectName(QString::fromUtf8("lblAsm1Processed"));

        vboxLayout2->addWidget(lblAsm1Processed);

        lblAsm2Processed = new QLabel(grpAssembler);
        lblAsm2Processed->setObjectName(QString::fromUtf8("lblAsm2Processed"));

        vboxLayout2->addWidget(lblAsm2Processed);

        barAsm1 = new QProgressBar(grpAssembler);
        barAsm1->setObjectName(QString::fromUtf8("barAsm1"));
        barAsm1->setValue(0);

        vboxLayout2->addWidget(barAsm1);

        barAsm2 = new QProgressBar(grpAssembler);
        barAsm2->setObjectName(QString::fromUtf8("barAsm2"));
        barAsm2->setValue(0);

        vboxLayout2->addWidget(barAsm2);


        stationsLayout->addWidget(grpAssembler, 0, 0, 1, 1);

        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblShipState = new QLabel(groupBox);
        lblShipState->setObjectName(QString::fromUtf8("lblShipState"));

        verticalLayout_2->addWidget(lblShipState);

        lblShipProcessed = new QLabel(groupBox);
        lblShipProcessed->setObjectName(QString::fromUtf8("lblShipProcessed"));

        verticalLayout_2->addWidget(lblShipProcessed);

        barShip = new QProgressBar(groupBox);
        barShip->setObjectName(QString::fromUtf8("barShip"));
        barShip->setValue(0);

        verticalLayout_2->addWidget(barShip);


        stationsLayout->addWidget(groupBox, 0, 4, 1, 1);

        txtLogs = new QPlainTextEdit(scrollAreaWidgetContents_2);
        txtLogs->setObjectName(QString::fromUtf8("txtLogs"));
        txtLogs->setGeometry(QRect(0, 330, 630, 260));
        txtLogs->setReadOnly(true);
        lblTotalRework = new QLabel(scrollAreaWidgetContents_2);
        lblTotalRework->setObjectName(QString::fromUtf8("lblTotalRework"));
        lblTotalRework->setGeometry(QRect(240, 260, 132, 18));
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
        grpPacker->setTitle(QCoreApplication::translate("MainWindow", "Packer", nullptr));
        lblPacState->setText(QString());
        lblPacProcessed->setText(QString());
        grpTester->setTitle(QCoreApplication::translate("MainWindow", "Tester", nullptr));
        lblTesState->setText(QString());
        lblTesProcessed->setText(QString());
        groupBoxQC->setTitle(QCoreApplication::translate("MainWindow", "Quality Control", nullptr));
        lblQCState->setText(QString());
        lblQCProcessed->setText(QString());
        lblQCRework->setText(QString());
        grpAssembler->setTitle(QCoreApplication::translate("MainWindow", "Assembler", nullptr));
        lblAsmState->setText(QString());
        lblAsm1Processed->setText(QString());
        lblAsm2Processed->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Shipping", nullptr));
        lblShipState->setText(QString());
        lblShipProcessed->setText(QString());
        lblTotalRework->setText(QCoreApplication::translate("MainWindow", "Total Reworks:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
