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
    QGroupBox *grpAssembler;
    QVBoxLayout *vboxLayout1;
    QLabel *lblAsmState;
    QLabel *lblAsm1Processed;
    QLabel *lblAsm2Processed;
    QProgressBar *barAsm1;
    QProgressBar *barAsm2;
    QGroupBox *grpTester;
    QVBoxLayout *vboxLayout2;
    QLabel *lblTesState;
    QLabel *lblTesProcessed;
    QProgressBar *barTes;
    QGroupBox *groupBoxQC;
    QLabel *lblQCProcessed;
    QLabel *lblQCState;
    QProgressBar *barQC;
    QLabel *lblQCRework;
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
        layoutWidget1->setGeometry(QRect(0, 30, 630, 225));
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

        grpAssembler = new QGroupBox(layoutWidget1);
        grpAssembler->setObjectName(QString::fromUtf8("grpAssembler"));
        vboxLayout1 = new QVBoxLayout(grpAssembler);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lblAsmState = new QLabel(grpAssembler);
        lblAsmState->setObjectName(QString::fromUtf8("lblAsmState"));

        vboxLayout1->addWidget(lblAsmState);

        lblAsm1Processed = new QLabel(grpAssembler);
        lblAsm1Processed->setObjectName(QString::fromUtf8("lblAsm1Processed"));

        vboxLayout1->addWidget(lblAsm1Processed);

        lblAsm2Processed = new QLabel(grpAssembler);
        lblAsm2Processed->setObjectName(QString::fromUtf8("lblAsm2Processed"));

        vboxLayout1->addWidget(lblAsm2Processed);

        barAsm1 = new QProgressBar(grpAssembler);
        barAsm1->setObjectName(QString::fromUtf8("barAsm1"));
        barAsm1->setValue(0);

        vboxLayout1->addWidget(barAsm1);

        barAsm2 = new QProgressBar(grpAssembler);
        barAsm2->setObjectName(QString::fromUtf8("barAsm2"));
        barAsm2->setValue(0);

        vboxLayout1->addWidget(barAsm2);


        stationsLayout->addWidget(grpAssembler, 0, 0, 1, 1);

        grpTester = new QGroupBox(layoutWidget1);
        grpTester->setObjectName(QString::fromUtf8("grpTester"));
        vboxLayout2 = new QVBoxLayout(grpTester);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lblTesState = new QLabel(grpTester);
        lblTesState->setObjectName(QString::fromUtf8("lblTesState"));

        vboxLayout2->addWidget(lblTesState);

        lblTesProcessed = new QLabel(grpTester);
        lblTesProcessed->setObjectName(QString::fromUtf8("lblTesProcessed"));

        vboxLayout2->addWidget(lblTesProcessed);

        barTes = new QProgressBar(grpTester);
        barTes->setObjectName(QString::fromUtf8("barTes"));
        barTes->setValue(0);

        vboxLayout2->addWidget(barTes);


        stationsLayout->addWidget(grpTester, 0, 1, 1, 1);

        groupBoxQC = new QGroupBox(layoutWidget1);
        groupBoxQC->setObjectName(QString::fromUtf8("groupBoxQC"));
        lblQCProcessed = new QLabel(groupBoxQC);
        lblQCProcessed->setObjectName(QString::fromUtf8("lblQCProcessed"));
        lblQCProcessed->setGeometry(QRect(10, 60, 111, 18));
        lblQCState = new QLabel(groupBoxQC);
        lblQCState->setObjectName(QString::fromUtf8("lblQCState"));
        lblQCState->setGeometry(QRect(10, 30, 111, 18));
        barQC = new QProgressBar(groupBoxQC);
        barQC->setObjectName(QString::fromUtf8("barQC"));
        barQC->setGeometry(QRect(0, 190, 118, 23));
        barQC->setValue(0);
        lblQCRework = new QLabel(groupBoxQC);
        lblQCRework->setObjectName(QString::fromUtf8("lblQCRework"));
        lblQCRework->setGeometry(QRect(10, 80, 111, 18));

        stationsLayout->addWidget(groupBoxQC, 0, 2, 1, 1);

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
        grpAssembler->setTitle(QCoreApplication::translate("MainWindow", "Assembler", nullptr));
        lblAsmState->setText(QString());
        lblAsm1Processed->setText(QString());
        lblAsm2Processed->setText(QString());
        grpTester->setTitle(QCoreApplication::translate("MainWindow", "Tester", nullptr));
        lblTesState->setText(QString());
        lblTesProcessed->setText(QString());
        groupBoxQC->setTitle(QCoreApplication::translate("MainWindow", "Quality Control", nullptr));
        lblQCProcessed->setText(QString());
        lblQCState->setText(QString());
        lblQCRework->setText(QString());
        lblTotalRework->setText(QCoreApplication::translate("MainWindow", "Total Reworks:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
