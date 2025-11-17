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
    QWidget *widget;
    QHBoxLayout *toolbarLayout;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QSpacerItem *hspacer;
    QComboBox *cmbSpeed;
    QWidget *widget1;
    QGridLayout *stationsLayout;
    QGroupBox *grpAssembler;
    QVBoxLayout *vboxLayout;
    QLabel *lblAsmState;
    QLabel *lblAsmProcessed;
    QProgressBar *barAsm;
    QGroupBox *grpTester;
    QVBoxLayout *vboxLayout1;
    QLabel *lblTesState;
    QLabel *lblTesProcessed;
    QProgressBar *barTes;
    QGroupBox *groupBoxQC;
    QLabel *lblQCProcessed;
    QLabel *lblQCState;
    QProgressBar *barQC;
    QGroupBox *grpPacker;
    QVBoxLayout *vboxLayout2;
    QLabel *lblPacState;
    QLabel *lblPacProcessed;
    QProgressBar *barPac;
    QPlainTextEdit *txtLogs;
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
        widget = new QWidget(scrollAreaWidgetContents_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 630, 28));
        toolbarLayout = new QHBoxLayout(widget);
        toolbarLayout->setObjectName(QString::fromUtf8("toolbarLayout"));
        toolbarLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        toolbarLayout->addWidget(btnStart);

        btnPause = new QPushButton(widget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));

        toolbarLayout->addWidget(btnPause);

        btnStop = new QPushButton(widget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        toolbarLayout->addWidget(btnStop);

        hspacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        toolbarLayout->addItem(hspacer);

        cmbSpeed = new QComboBox(widget);
        cmbSpeed->setObjectName(QString::fromUtf8("cmbSpeed"));

        toolbarLayout->addWidget(cmbSpeed);

        widget1 = new QWidget(scrollAreaWidgetContents_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(0, 30, 630, 142));
        stationsLayout = new QGridLayout(widget1);
        stationsLayout->setObjectName(QString::fromUtf8("stationsLayout"));
        stationsLayout->setContentsMargins(0, 0, 0, 0);
        grpAssembler = new QGroupBox(widget1);
        grpAssembler->setObjectName(QString::fromUtf8("grpAssembler"));
        vboxLayout = new QVBoxLayout(grpAssembler);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        lblAsmState = new QLabel(grpAssembler);
        lblAsmState->setObjectName(QString::fromUtf8("lblAsmState"));

        vboxLayout->addWidget(lblAsmState);

        lblAsmProcessed = new QLabel(grpAssembler);
        lblAsmProcessed->setObjectName(QString::fromUtf8("lblAsmProcessed"));

        vboxLayout->addWidget(lblAsmProcessed);

        barAsm = new QProgressBar(grpAssembler);
        barAsm->setObjectName(QString::fromUtf8("barAsm"));
        barAsm->setValue(0);

        vboxLayout->addWidget(barAsm);


        stationsLayout->addWidget(grpAssembler, 0, 0, 1, 1);

        grpTester = new QGroupBox(widget1);
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

        groupBoxQC = new QGroupBox(widget1);
        groupBoxQC->setObjectName(QString::fromUtf8("groupBoxQC"));
        lblQCProcessed = new QLabel(groupBoxQC);
        lblQCProcessed->setObjectName(QString::fromUtf8("lblQCProcessed"));
        lblQCProcessed->setGeometry(QRect(20, 70, 66, 18));
        lblQCState = new QLabel(groupBoxQC);
        lblQCState->setObjectName(QString::fromUtf8("lblQCState"));
        lblQCState->setGeometry(QRect(10, 30, 66, 18));
        barQC = new QProgressBar(groupBoxQC);
        barQC->setObjectName(QString::fromUtf8("barQC"));
        barQC->setGeometry(QRect(10, 100, 118, 23));
        barQC->setValue(0);

        stationsLayout->addWidget(groupBoxQC, 0, 2, 1, 1);

        grpPacker = new QGroupBox(widget1);
        grpPacker->setObjectName(QString::fromUtf8("grpPacker"));
        vboxLayout2 = new QVBoxLayout(grpPacker);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lblPacState = new QLabel(grpPacker);
        lblPacState->setObjectName(QString::fromUtf8("lblPacState"));
        lblPacState->setEnabled(true);

        vboxLayout2->addWidget(lblPacState);

        lblPacProcessed = new QLabel(grpPacker);
        lblPacProcessed->setObjectName(QString::fromUtf8("lblPacProcessed"));

        vboxLayout2->addWidget(lblPacProcessed);

        barPac = new QProgressBar(grpPacker);
        barPac->setObjectName(QString::fromUtf8("barPac"));
        barPac->setValue(0);

        vboxLayout2->addWidget(barPac);


        stationsLayout->addWidget(grpPacker, 0, 3, 1, 1);

        txtLogs = new QPlainTextEdit(scrollAreaWidgetContents_2);
        txtLogs->setObjectName(QString::fromUtf8("txtLogs"));
        txtLogs->setGeometry(QRect(0, 330, 630, 260));
        txtLogs->setReadOnly(true);
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
        lblAsmState->setText(QCoreApplication::translate("MainWindow", "Idle", nullptr));
        lblAsmProcessed->setText(QString());
        grpTester->setTitle(QCoreApplication::translate("MainWindow", "Tester", nullptr));
        lblTesState->setText(QCoreApplication::translate("MainWindow", "Idle", nullptr));
        lblTesProcessed->setText(QString());
        groupBoxQC->setTitle(QCoreApplication::translate("MainWindow", "Quality Control", nullptr));
        lblQCProcessed->setText(QString());
        lblQCState->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        grpPacker->setTitle(QCoreApplication::translate("MainWindow", "Packer", nullptr));
        lblPacState->setText(QCoreApplication::translate("MainWindow", "Idle", nullptr));
        lblPacProcessed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
