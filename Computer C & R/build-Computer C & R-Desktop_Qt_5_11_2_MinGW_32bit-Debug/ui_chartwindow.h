/********************************************************************************
** Form generated from reading UI file 'chartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chartWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chartWindow)
    {
        if (chartWindow->objectName().isEmpty())
            chartWindow->setObjectName(QStringLiteral("chartWindow"));
        chartWindow->resize(1500, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chartWindow->sizePolicy().hasHeightForWidth());
        chartWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(chartWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        chartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chartWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1500, 26));
        chartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(chartWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        chartWindow->setStatusBar(statusbar);

        retranslateUi(chartWindow);

        QMetaObject::connectSlotsByName(chartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *chartWindow)
    {
        chartWindow->setWindowTitle(QApplication::translate("chartWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chartWindow: public Ui_chartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H
