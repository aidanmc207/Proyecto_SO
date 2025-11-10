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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QHBoxLayout *toolbarLayout;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QSpacerItem *hspacer;
    QComboBox *cmbSpeed;
    QGridLayout *stationsLayout;
    QGroupBox *grpAssembler;
    QVBoxLayout *vboxLayout;
    QLabel *lblAsmState;
    QProgressBar *barAsm;
    QGroupBox *grpTester;
    QVBoxLayout *vboxLayout1;
    QLabel *lblTesState;
    QProgressBar *barTes;
    QGroupBox *grpPacker;
    QVBoxLayout *vboxLayout2;
    QLabel *lblPacState;
    QProgressBar *barPac;
    QPlainTextEdit *txtLogs;
    QTableWidget *tblThreads;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setObjectName(QString::fromUtf8("rootLayout"));
        toolbarLayout = new QHBoxLayout();
        toolbarLayout->setObjectName(QString::fromUtf8("toolbarLayout"));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        toolbarLayout->addWidget(btnStart);

        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));

        toolbarLayout->addWidget(btnPause);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        toolbarLayout->addWidget(btnStop);

        hspacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        toolbarLayout->addItem(hspacer);

        cmbSpeed = new QComboBox(centralwidget);
        cmbSpeed->setObjectName(QString::fromUtf8("cmbSpeed"));

        toolbarLayout->addWidget(cmbSpeed);


        rootLayout->addLayout(toolbarLayout);

        stationsLayout = new QGridLayout();
        stationsLayout->setObjectName(QString::fromUtf8("stationsLayout"));
        grpAssembler = new QGroupBox(centralwidget);
        grpAssembler->setObjectName(QString::fromUtf8("grpAssembler"));
        vboxLayout = new QVBoxLayout(grpAssembler);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        lblAsmState = new QLabel(grpAssembler);
        lblAsmState->setObjectName(QString::fromUtf8("lblAsmState"));

        vboxLayout->addWidget(lblAsmState);

        barAsm = new QProgressBar(grpAssembler);
        barAsm->setObjectName(QString::fromUtf8("barAsm"));

        vboxLayout->addWidget(barAsm);


        stationsLayout->addWidget(grpAssembler, 0, 0, 1, 1);

        grpTester = new QGroupBox(centralwidget);
        grpTester->setObjectName(QString::fromUtf8("grpTester"));
        vboxLayout1 = new QVBoxLayout(grpTester);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        lblTesState = new QLabel(grpTester);
        lblTesState->setObjectName(QString::fromUtf8("lblTesState"));

        vboxLayout1->addWidget(lblTesState);

        barTes = new QProgressBar(grpTester);
        barTes->setObjectName(QString::fromUtf8("barTes"));

        vboxLayout1->addWidget(barTes);


        stationsLayout->addWidget(grpTester, 0, 1, 1, 1);

        grpPacker = new QGroupBox(centralwidget);
        grpPacker->setObjectName(QString::fromUtf8("grpPacker"));
        vboxLayout2 = new QVBoxLayout(grpPacker);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lblPacState = new QLabel(grpPacker);
        lblPacState->setObjectName(QString::fromUtf8("lblPacState"));

        vboxLayout2->addWidget(lblPacState);

        barPac = new QProgressBar(grpPacker);
        barPac->setObjectName(QString::fromUtf8("barPac"));

        vboxLayout2->addWidget(barPac);


        stationsLayout->addWidget(grpPacker, 0, 2, 1, 1);


        rootLayout->addLayout(stationsLayout);

        txtLogs = new QPlainTextEdit(centralwidget);
        txtLogs->setObjectName(QString::fromUtf8("txtLogs"));
        txtLogs->setReadOnly(true);

        rootLayout->addWidget(txtLogs);

        tblThreads = new QTableWidget(centralwidget);
        if (tblThreads->columnCount() < 2)
            tblThreads->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblThreads->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblThreads->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tblThreads->setObjectName(QString::fromUtf8("tblThreads"));

        rootLayout->addWidget(tblThreads);

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
        grpTester->setTitle(QCoreApplication::translate("MainWindow", "Tester", nullptr));
        lblTesState->setText(QCoreApplication::translate("MainWindow", "Idle", nullptr));
        grpPacker->setTitle(QCoreApplication::translate("MainWindow", "Packer", nullptr));
        lblPacState->setText(QCoreApplication::translate("MainWindow", "Idle", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblThreads->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Thread", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblThreads->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "State", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
