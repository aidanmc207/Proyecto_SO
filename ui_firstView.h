/********************************************************************************
** Form generated from reading UI file 'firstView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTVIEW_H
#define UI_FIRSTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer;
    QPushButton *btnProduction;
    QPushButton *btnLogs;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FirstView)
    {
        if (FirstView->objectName().isEmpty())
            FirstView->setObjectName(QString::fromUtf8("FirstView"));
        FirstView->resize(895, 702);
        verticalLayout = new QVBoxLayout(FirstView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitle = new QLabel(FirstView);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans"));
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold;"));
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        verticalSpacer = new QSpacerItem(1000, 1500, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnProduction = new QPushButton(FirstView);
        btnProduction->setObjectName(QString::fromUtf8("btnProduction"));
        btnProduction->setMinimumSize(QSize(20, 100));

        verticalLayout->addWidget(btnProduction);

        btnLogs = new QPushButton(FirstView);
        btnLogs->setObjectName(QString::fromUtf8("btnLogs"));
        btnLogs->setMinimumSize(QSize(20, 100));

        verticalLayout->addWidget(btnLogs);

        verticalSpacer_2 = new QSpacerItem(100, 1500, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(FirstView);

        QMetaObject::connectSlotsByName(FirstView);
    } // setupUi

    void retranslateUi(QWidget *FirstView)
    {
        FirstView->setWindowTitle(QCoreApplication::translate("FirstView", "First View - Men\303\272 Principal", nullptr));
        labelTitle->setText(QCoreApplication::translate("FirstView", "Electrodomesticos D.A.A", nullptr));
        btnProduction->setText(QCoreApplication::translate("FirstView", "Cadena de Producci\303\263n", nullptr));
        btnLogs->setText(QCoreApplication::translate("FirstView", "Ver Registro del Sistema (Logs)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstView: public Ui_FirstView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTVIEW_H
