/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *choosePartWidget;
    QTabWidget *choosePartTabs;
    QWidget *choosePartTab;
    QLabel *label_22;
    QComboBox *ramCombo;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *ramPrice;
    QLabel *label_13;
    QLabel *hddPrice;
    QLabel *vgaPrice;
    QLabel *sumPrice;
    QLabel *ssdPrice;
    QLabel *label_18;
    QPushButton *resultCombination;
    QComboBox *vgaCombo;
    QComboBox *cpuCombo;
    QLabel *label_15;
    QComboBox *hddCombo;
    QLabel *label_21;
    QComboBox *mbCombo;
    QLabel *label_19;
    QLabel *label_14;
    QComboBox *powerCombo;
    QComboBox *ssdCombo;
    QLabel *cpuPrice;
    QLabel *powerPrice;
    QLabel *mbPrice;
    QPushButton *initCombination;
    QTextBrowser *cpuDescription;
    QTextBrowser *mbDescription;
    QTextBrowser *vgaDescription;
    QTextBrowser *ramDescription;
    QTextBrowser *ssdDescription;
    QTextBrowser *hddDescription;
    QTextBrowser *powerDescription;
    QPushButton *goToGameSelection;
    QLabel *label_23;
    QLabel *label_24;
    QWidget *chooseGameWidget;
    QTabWidget *chooseGameTabs;
    QWidget *chooseGame;
    QListWidget *gameList;
    QListWidget *selectedList;
    QLabel *label;
    QLabel *label_2;
    QPushButton *gameAdd;
    QPushButton *gameDelete;
    QPushButton *gameClear;
    QPushButton *recommend;
    QPushButton *goToPartSelection;
    QWidget *quoteTab;
    QTableWidget *partRecTable;
    QPushButton *retry;
    QPushButton *reselect;
    QPushButton *printRecParts;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1057, 631);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -5, 1061, 641));
        choosePartWidget = new QWidget();
        choosePartWidget->setObjectName(QStringLiteral("choosePartWidget"));
        choosePartTabs = new QTabWidget(choosePartWidget);
        choosePartTabs->setObjectName(QStringLiteral("choosePartTabs"));
        choosePartTabs->setGeometry(QRect(0, 5, 1061, 641));
        choosePartTab = new QWidget();
        choosePartTab->setObjectName(QStringLiteral("choosePartTab"));
        label_22 = new QLabel(choosePartTab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(430, 60, 91, 20));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        label_22->setFont(font);
        ramCombo = new QComboBox(choosePartTab);
        ramCombo->setObjectName(QStringLiteral("ramCombo"));
        ramCombo->setGeometry(QRect(110, 280, 311, 21));
        label_12 = new QLabel(choosePartTab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 460, 80, 20));
        label_12->setFont(font);
        label_16 = new QLabel(choosePartTab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 160, 101, 20));
        label_16->setFont(font);
        ramPrice = new QLabel(choosePartTab);
        ramPrice->setObjectName(QStringLiteral("ramPrice"));
        ramPrice->setGeometry(QRect(440, 280, 131, 21));
        ramPrice->setFont(font);
        label_13 = new QLabel(choosePartTab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(370, 520, 80, 20));
        label_13->setFont(font);
        hddPrice = new QLabel(choosePartTab);
        hddPrice->setObjectName(QStringLiteral("hddPrice"));
        hddPrice->setGeometry(QRect(440, 400, 131, 21));
        hddPrice->setFont(font);
        vgaPrice = new QLabel(choosePartTab);
        vgaPrice->setObjectName(QStringLiteral("vgaPrice"));
        vgaPrice->setGeometry(QRect(440, 220, 131, 21));
        vgaPrice->setFont(font);
        sumPrice = new QLabel(choosePartTab);
        sumPrice->setObjectName(QStringLiteral("sumPrice"));
        sumPrice->setGeometry(QRect(440, 520, 191, 21));
        sumPrice->setFont(font);
        ssdPrice = new QLabel(choosePartTab);
        ssdPrice->setObjectName(QStringLiteral("ssdPrice"));
        ssdPrice->setGeometry(QRect(440, 340, 131, 21));
        ssdPrice->setFont(font);
        label_18 = new QLabel(choosePartTab);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 340, 80, 20));
        label_18->setFont(font);
        resultCombination = new QPushButton(choosePartTab);
        resultCombination->setObjectName(QStringLiteral("resultCombination"));
        resultCombination->setGeometry(QRect(920, 550, 101, 31));
        vgaCombo = new QComboBox(choosePartTab);
        vgaCombo->setObjectName(QStringLiteral("vgaCombo"));
        vgaCombo->setGeometry(QRect(110, 220, 311, 21));
        cpuCombo = new QComboBox(choosePartTab);
        cpuCombo->setObjectName(QStringLiteral("cpuCombo"));
        cpuCombo->setGeometry(QRect(110, 100, 311, 21));
        label_15 = new QLabel(choosePartTab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 100, 80, 20));
        label_15->setFont(font);
        hddCombo = new QComboBox(choosePartTab);
        hddCombo->setObjectName(QStringLiteral("hddCombo"));
        hddCombo->setGeometry(QRect(110, 400, 311, 21));
        label_21 = new QLabel(choosePartTab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 220, 80, 20));
        label_21->setFont(font);
        mbCombo = new QComboBox(choosePartTab);
        mbCombo->setObjectName(QStringLiteral("mbCombo"));
        mbCombo->setGeometry(QRect(110, 160, 311, 21));
        label_19 = new QLabel(choosePartTab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 280, 80, 20));
        label_19->setFont(font);
        label_14 = new QLabel(choosePartTab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 400, 80, 20));
        label_14->setFont(font);
        powerCombo = new QComboBox(choosePartTab);
        powerCombo->setObjectName(QStringLiteral("powerCombo"));
        powerCombo->setGeometry(QRect(110, 460, 311, 21));
        ssdCombo = new QComboBox(choosePartTab);
        ssdCombo->setObjectName(QStringLiteral("ssdCombo"));
        ssdCombo->setGeometry(QRect(110, 340, 311, 21));
        cpuPrice = new QLabel(choosePartTab);
        cpuPrice->setObjectName(QStringLiteral("cpuPrice"));
        cpuPrice->setGeometry(QRect(440, 100, 131, 21));
        cpuPrice->setFont(font);
        powerPrice = new QLabel(choosePartTab);
        powerPrice->setObjectName(QStringLiteral("powerPrice"));
        powerPrice->setGeometry(QRect(440, 460, 131, 21));
        powerPrice->setFont(font);
        mbPrice = new QLabel(choosePartTab);
        mbPrice->setObjectName(QStringLiteral("mbPrice"));
        mbPrice->setGeometry(QRect(440, 160, 131, 21));
        mbPrice->setFont(font);
        initCombination = new QPushButton(choosePartTab);
        initCombination->setObjectName(QStringLiteral("initCombination"));
        initCombination->setGeometry(QRect(830, 550, 81, 31));
        cpuDescription = new QTextBrowser(choosePartTab);
        cpuDescription->setObjectName(QStringLiteral("cpuDescription"));
        cpuDescription->setGeometry(QRect(530, 100, 501, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        cpuDescription->setFont(font1);
        mbDescription = new QTextBrowser(choosePartTab);
        mbDescription->setObjectName(QStringLiteral("mbDescription"));
        mbDescription->setGeometry(QRect(530, 160, 501, 51));
        mbDescription->setFont(font1);
        vgaDescription = new QTextBrowser(choosePartTab);
        vgaDescription->setObjectName(QStringLiteral("vgaDescription"));
        vgaDescription->setGeometry(QRect(530, 220, 501, 51));
        vgaDescription->setFont(font1);
        ramDescription = new QTextBrowser(choosePartTab);
        ramDescription->setObjectName(QStringLiteral("ramDescription"));
        ramDescription->setGeometry(QRect(530, 280, 501, 51));
        ramDescription->setFont(font1);
        ssdDescription = new QTextBrowser(choosePartTab);
        ssdDescription->setObjectName(QStringLiteral("ssdDescription"));
        ssdDescription->setGeometry(QRect(530, 340, 501, 51));
        ssdDescription->setFont(font1);
        hddDescription = new QTextBrowser(choosePartTab);
        hddDescription->setObjectName(QStringLiteral("hddDescription"));
        hddDescription->setGeometry(QRect(530, 400, 501, 51));
        hddDescription->setFont(font1);
        powerDescription = new QTextBrowser(choosePartTab);
        powerDescription->setObjectName(QStringLiteral("powerDescription"));
        powerDescription->setGeometry(QRect(530, 460, 501, 51));
        powerDescription->setFont(font1);
        goToGameSelection = new QPushButton(choosePartTab);
        goToGameSelection->setObjectName(QStringLiteral("goToGameSelection"));
        goToGameSelection->setGeometry(QRect(910, 10, 121, 28));
        label_23 = new QLabel(choosePartTab);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(220, 60, 91, 20));
        label_23->setFont(font);
        label_24 = new QLabel(choosePartTab);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(730, 60, 101, 20));
        label_24->setFont(font);
        choosePartTabs->addTab(choosePartTab, QString());
        stackedWidget->addWidget(choosePartWidget);
        chooseGameWidget = new QWidget();
        chooseGameWidget->setObjectName(QStringLiteral("chooseGameWidget"));
        chooseGameTabs = new QTabWidget(chooseGameWidget);
        chooseGameTabs->setObjectName(QStringLiteral("chooseGameTabs"));
        chooseGameTabs->setGeometry(QRect(0, 5, 1061, 641));
        chooseGame = new QWidget();
        chooseGame->setObjectName(QStringLiteral("chooseGame"));
        gameList = new QListWidget(chooseGame);
        gameList->setObjectName(QStringLiteral("gameList"));
        gameList->setGeometry(QRect(40, 70, 411, 501));
        selectedList = new QListWidget(chooseGame);
        selectedList->setObjectName(QStringLiteral("selectedList"));
        selectedList->setGeometry(QRect(600, 70, 411, 501));
        label = new QLabel(chooseGame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 40, 81, 21));
        label_2 = new QLabel(chooseGame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(770, 40, 81, 21));
        gameAdd = new QPushButton(chooseGame);
        gameAdd->setObjectName(QStringLiteral("gameAdd"));
        gameAdd->setGeometry(QRect(480, 80, 93, 28));
        gameDelete = new QPushButton(chooseGame);
        gameDelete->setObjectName(QStringLiteral("gameDelete"));
        gameDelete->setGeometry(QRect(480, 130, 93, 28));
        gameClear = new QPushButton(chooseGame);
        gameClear->setObjectName(QStringLiteral("gameClear"));
        gameClear->setGeometry(QRect(480, 180, 93, 28));
        recommend = new QPushButton(chooseGame);
        recommend->setObjectName(QStringLiteral("recommend"));
        recommend->setGeometry(QRect(480, 230, 93, 28));
        goToPartSelection = new QPushButton(chooseGame);
        goToPartSelection->setObjectName(QStringLiteral("goToPartSelection"));
        goToPartSelection->setGeometry(QRect(900, 10, 111, 28));
        chooseGameTabs->addTab(chooseGame, QString());
        quoteTab = new QWidget();
        quoteTab->setObjectName(QStringLiteral("quoteTab"));
        partRecTable = new QTableWidget(quoteTab);
        partRecTable->setObjectName(QStringLiteral("partRecTable"));
        partRecTable->setGeometry(QRect(15, 11, 1011, 521));
        retry = new QPushButton(quoteTab);
        retry->setObjectName(QStringLiteral("retry"));
        retry->setGeometry(QRect(700, 540, 93, 28));
        reselect = new QPushButton(quoteTab);
        reselect->setObjectName(QStringLiteral("reselect"));
        reselect->setGeometry(QRect(800, 540, 121, 28));
        printRecParts = new QPushButton(quoteTab);
        printRecParts->setObjectName(QStringLiteral("printRecParts"));
        printRecParts->setGeometry(QRect(930, 540, 93, 28));
        chooseGameTabs->addTab(quoteTab, QString());
        stackedWidget->addWidget(chooseGameWidget);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        choosePartTabs->setCurrentIndex(0);
        chooseGameTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "Price(KRW)", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Power", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Mainboard", nullptr));
        ramPrice->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Sum :", nullptr));
        hddPrice->setText(QString());
        vgaPrice->setText(QString());
        sumPrice->setText(QString());
        ssdPrice->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "SSD", nullptr));
        resultCombination->setText(QApplication::translate("MainWindow", "Performance", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "CPU", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "VGA", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "RAM", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "HDD", nullptr));
        cpuPrice->setText(QString());
        powerPrice->setText(QString());
        mbPrice->setText(QString());
        initCombination->setText(QApplication::translate("MainWindow", "Initialize", nullptr));
        goToGameSelection->setText(QApplication::translate("MainWindow", "Game Selection", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Part Name", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "Description", nullptr));
        choosePartTabs->setTabText(choosePartTabs->indexOf(choosePartTab), QApplication::translate("MainWindow", "Choose Part", nullptr));
        label->setText(QApplication::translate("MainWindow", "Game List", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Selection List", nullptr));
        gameAdd->setText(QApplication::translate("MainWindow", "Add", nullptr));
        gameDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        gameClear->setText(QApplication::translate("MainWindow", "Initialize", nullptr));
        recommend->setText(QApplication::translate("MainWindow", "Recommend", nullptr));
        goToPartSelection->setText(QApplication::translate("MainWindow", "Part Selection", nullptr));
        chooseGameTabs->setTabText(chooseGameTabs->indexOf(chooseGame), QApplication::translate("MainWindow", "Game Selection", nullptr));
        retry->setText(QApplication::translate("MainWindow", "Retry", nullptr));
        reselect->setText(QApplication::translate("MainWindow", "Game Selection", nullptr));
        printRecParts->setText(QApplication::translate("MainWindow", "Print", nullptr));
        chooseGameTabs->setTabText(chooseGameTabs->indexOf(quoteTab), QApplication::translate("MainWindow", "Recommendation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
