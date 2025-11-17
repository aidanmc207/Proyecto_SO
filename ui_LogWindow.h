/********************************************************************************
** Form generated from reading UI file 'LogWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *logTextEdit;
    QHBoxLayout *buttonsLayout;
    QPushButton *btnClear;
    QPushButton *btnExport;
    QPushButton *returnBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QString::fromUtf8("LogWindow"));
        LogWindow->resize(901, 554);
        verticalLayout = new QVBoxLayout(LogWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logTextEdit = new QTextEdit(LogWindow);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(10);
        logTextEdit->setFont(font);
        logTextEdit->setReadOnly(true);

        verticalLayout->addWidget(logTextEdit);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        btnClear = new QPushButton(LogWindow);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        buttonsLayout->addWidget(btnClear);

        btnExport = new QPushButton(LogWindow);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));

        buttonsLayout->addWidget(btnExport);

        returnBtn = new QPushButton(LogWindow);
        returnBtn->setObjectName(QString::fromUtf8("returnBtn"));

        buttonsLayout->addWidget(returnBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonsLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(buttonsLayout);


        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QWidget *LogWindow)
    {
        LogWindow->setWindowTitle(QCoreApplication::translate("LogWindow", "Production Line Logs", nullptr));
        btnClear->setText(QCoreApplication::translate("LogWindow", "Clear", nullptr));
        btnExport->setText(QCoreApplication::translate("LogWindow", "Export", nullptr));
        returnBtn->setText(QCoreApplication::translate("LogWindow", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
