#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <compatibilityobserver.h>
#include <allpartandgamedata.h>
#include <partdata.h>
#include <iostream>
#include <QStandardItem>
#include "compatibilitysubject.h"
#include "part.h"
#include <string>
#include "gameselectionsubject.h"
#include <iomanip>
#include <sstream>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "chartwindow.h"
#include "usergameselection.h"
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(CompatibilitySubject *cSub, GameSelectionSubject *gSub, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), cSub(cSub), gSub(gSub)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->choosePartTabs->setCurrentIndex(0);
    ui->chooseGameTabs->setCurrentIndex(0);
    ui->chooseGameTabs->removeTab(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::existSSD = false;

void MainWindow::update_chart(Part** pa, list<GameData> *gdList){
    QBarSet *set0 = new QBarSet("cpu Benchmark");
    QBarSet *set1 = new QBarSet("graphic Benchmark");
    QBarSet *set2 = new QBarSet("ram Capacity");
    for(list<GameData>::iterator iter = gdList->begin(); iter != gdList->end(); iter++){  // gamedata game
        if((double)iter->getMinCPU()/(double)(dynamic_cast<CPU*>(pa[0])->getMultiBenchmark()) >= 1)
                    // compute whether my cpu is better than mincpu
            *set0  << ((double)(dynamic_cast<CPU*>(pa[0])->getMultiBenchmark()) / (double)iter->getMinCPU());
                // chart impossible cpu
        else {
            if((((double)(dynamic_cast<CPU*>(pa[0])->getMultiBenchmark()) / ((double)iter->getProperCpu()) + 1)) >= 3){
                *set0 << 3;     // chart for best cpu
            }
            else *set0 << (((double)(dynamic_cast<CPU*>(pa[0])->getMultiBenchmark()) / ((double)iter->getProperCpu()) + 1));
                                // chart for normal cpu
        }

        if(pa[2]->getName() == "no select") {       // if i select non-vga
            if((double)iter->getMinVga() / (double)(dynamic_cast<CPU*>(pa[0])->getVgaBenchmark()) >= 1){
                    // compute whether graphic in cpu is better than minvga
                *set1  << ((double)(dynamic_cast<CPU*>(pa[0])->getVgaBenchmark())/(double)iter->getMinVga());
                        // chart impossible cpu grapic
            }
            else {
                if(((double)(dynamic_cast<CPU*>(pa[0])->getVgaBenchmark())/((double)iter->getProperVga()) + 1) >= 3){
                    *set1 << 3;         // chart for best cpu graphic
                }
                else *set1 << ((double)(dynamic_cast<CPU*>(pa[0])->getVgaBenchmark())/((double)iter->getProperVga()) + 1);
                                        // chart for normal cpu graphic
            }
        }
        else {          // if i select vga
            if((double)iter->getMinVga() / (double)(dynamic_cast<VGA*>(pa[2])->getVgaBenchmark()) >= 1)
                            // compute whether my vga is better than minvga
                *set1  << ((double)(dynamic_cast<VGA*>(pa[2])->getVgaBenchmark())/(double)iter->getMinVga());
                            // chart impossible vga
            else {
                if(((double)(dynamic_cast<VGA*>(pa[2])->getVgaBenchmark())/((double)iter->getProperVga()) + 1) >= 3){
                    *set1 << 3;     // chart best vga
                }
                else *set1 << ((double)(dynamic_cast<VGA*>(pa[2])->getVgaBenchmark())/((double)iter->getProperVga()) + 1);
                                // chart normal vga
            }
        }

        if((double)iter->getMinRam()/(double)(dynamic_cast<RAM*>(pa[3])->getCapacity()) >= 1)
                    // compute whether my ram is better than minram
            *set2  << ((double)(dynamic_cast<RAM*>(pa[3])->getCapacity()) / (double)iter->getMinRam());
                // chart impossible ram
        else {
            if((((double)(dynamic_cast<RAM*>(pa[3])->getCapacity()) / ((double)iter->getProperRam()) + 1)) >= 3){
                *set2 << 3;     // chart for best ram
            }
            else *set2 << (((double)(dynamic_cast<RAM*>(pa[3])->getCapacity()) / ((double)iter->getProperRam()) + 1));
                                // chart for normal ram
        }
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Performance of your computer");
    QStringList categories;
    for(list<GameData>::iterator iter = gdList->begin(); iter != gdList->end(); iter++){
        categories << QString::fromLocal8Bit(iter->getName().c_str());
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    QCategoryAxis *axisy = new QCategoryAxis;
    axisy->append("minimum ", 1);
    axisy->append("recommend ", 2);
    axisy->append("max ", 3);
    axisy->setTickCount(4);
    axisy->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    chart->setAxisY(axisy, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    ChartView *chartView = new ChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, (0xffffff));
    pal.setColor(QPalette::WindowText, (0x404040));
    qApp->setPalette(pal);
    chartView->setRubberBand( ChartView::HorizontalRubberBand );
    chartWindow* window = new chartWindow(this);

    // Set the main window widget
    window->setCentralWidget(chartView);

    window->show();
}

void MainWindow::update(PartData *pd, string partType){
    QStandardItemModel* model;
    QModelIndex firstIndex;
    QStandardItem* firstItem;

    if(partType.compare("cpu") == 0){
        if(pd->getPartName().compare("cpu") == 0){
            ui->cpuCombo->setEnabled(true);
            ui->mbCombo->setEnabled(false);     // init
            ui->vgaCombo->setEnabled(false);    // init
            ui->ramCombo->setEnabled(false);    // init
            ui->ssdCombo->setEnabled(false);    // init
            ui->hddCombo->setEnabled(false);    // init
            ui->powerCombo->setEnabled(false);  // init

            ui->resultCombination->setEnabled(false);


            ui->cpuCombo->clear();
            ui->cpuCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->cpuCombo->model());
            firstIndex = model->index(0, ui->cpuCombo->modelColumn(), ui->cpuCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);

            list<Part*>::iterator ptIter;
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->cpuCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));
            }
        }
    }
    else if(partType.compare("mainboard") == 0){
        if(pd->getPartName().compare("mainboard") == 0){
            ui->mbCombo->setEnabled(true);
            ui->mbCombo->clear();
            ui->mbCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->mbCombo->model());
            firstIndex = model->index(0, ui->mbCombo->modelColumn(), ui->mbCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);

            list<Part*>::iterator ptIter;
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->mbCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));
            }
        }
    }
    else if(partType.compare("vga") == 0){
        if(pd->getPartName().compare("vga") == 0){
            ui->vgaCombo->setEnabled(true);
            ui->vgaCombo->clear();
            ui->vgaCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->vgaCombo->model());
            firstIndex = model->index(0, ui->vgaCombo->modelColumn(), ui->vgaCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);


            if(dynamic_cast<CPU*>(dynamic_cast<UserPartSelection*>(cSub)->getUserPartSelectionList()[0])->getVgaBenchmark() > 0){
                ui->vgaCombo->addItem(QString::fromLocal8Bit("no select"));
            }
            list<Part*>::iterator ptIter;
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->vgaCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));
            }
        }
    }
    else if(partType.compare("ram") == 0){
        if(pd->getPartName().compare("ram") == 0){
            ui->ramCombo->setEnabled(true);
            ui->ramCombo->clear();
            ui->ramCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->ramCombo->model());
            firstIndex = model->index(0, ui->ramCombo->modelColumn(), ui->ramCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);

            list<Part*>::iterator ptIter;
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->ramCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));
            }
        }
    }
    else if(partType.compare("ssd") == 0){
        if(pd->getPartName().compare("ssd") == 0){
            ui->ssdCombo->setEnabled(true);
            ui->ssdCombo->clear();
            ui->ssdCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->ssdCombo->model());
            firstIndex = model->index(0, ui->ssdCombo->modelColumn(), ui->ssdCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);

            ui->ssdCombo->addItem(QString::fromLocal8Bit("no select"));
            list<Part*>::iterator ptIter;
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->ssdCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));
            }
        }
    }
    else if(partType.compare("hdd") == 0){
        if(pd->getPartName().compare("hdd") == 0){
            ui->hddCombo->setEnabled(true);
            ui->hddCombo->clear();
            ui->hddCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->hddCombo->model());
            firstIndex = model->index(0, ui->hddCombo->modelColumn(), ui->hddCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);

            list<Part*>::iterator ptIter;
            //cout << "existSSD in hdd = " << existSSD << endl;
            if(existSSD == true){
                ui->hddCombo->addItem("no select");
            }
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->hddCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));;
            }
        }
    }

    else if(partType.compare("powersupply") == 0){
        if(pd->getPartName().compare("powersupply") == 0){
            ui->powerCombo->setEnabled(true);
            ui->powerCombo->clear();
            ui->powerCombo->addItem("Choose");
            model = qobject_cast<QStandardItemModel*>(ui->powerCombo->model());
            firstIndex = model->index(0, ui->powerCombo->modelColumn(), ui->powerCombo->rootModelIndex());
            firstItem = model->itemFromIndex(firstIndex);
            firstItem->setSelectable(false);

            list<Part*>::iterator ptIter;
            for(ptIter = pd->getPartDataList()->begin(); ptIter != pd->getPartDataList()->end(); ptIter++){
                ui->powerCombo->addItem(QString::fromLocal8Bit((*ptIter)->getName().c_str()));;
            }
        }        
    }
    else if(partType.compare(("init")) == 0){
        ui->cpuCombo->clear();
        ui->mbCombo->clear();
        ui->vgaCombo->clear();
        ui->ramCombo->clear();
        ui->ssdCombo->clear();
        ui->hddCombo->clear();
        ui->powerCombo->clear();

        ui->cpuCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->cpuCombo->model());
        firstIndex = model->index(0, ui->cpuCombo->modelColumn(), ui->cpuCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
}

void MainWindow::update_price(string name, int price, int pricesum){
    ui->sumPrice->clear();
   if(name == "cpu") ui->cpuPrice->setText(QString::number(price));
   if(name == "mainboard") ui->mbPrice->setText(QString::number(price));
   if(name == "vga") ui->vgaPrice->setText(QString::number(price));
   if(name == "ram") ui->ramPrice->setText(QString::number(price));
   if(name == "ssd") ui->ssdPrice->setText(QString::number(price));
   if(name == "hdd") ui->hddPrice->setText(QString::number(price));
   if(name == "powersupply") ui->powerPrice->setText(QString::number(price));
   ui->sumPrice->setText(QString::number(pricesum));
}

void MainWindow::update_description(string partType, string description){
    if(partType == "cpu") ui->cpuDescription->setText(QString::fromLocal8Bit(description.c_str()));
    if(partType == "mainboard") ui->mbDescription->setText(QString::fromLocal8Bit(description.c_str()));
    if(partType == "vga") ui->vgaDescription->setText(QString::fromLocal8Bit(description.c_str()));
    if(partType == "ram") ui->ramDescription->setText(QString::fromLocal8Bit(description.c_str()));
    if(partType == "ssd") ui->ssdDescription->setText(QString::fromLocal8Bit(description.c_str()));
    if(partType == "hdd") ui->hddDescription->setText(QString::fromLocal8Bit(description.c_str()));
    if(partType == "powersupply") ui->powerDescription->setText(QString::fromLocal8Bit(description.c_str()));
}

void MainWindow::on_cpuCombo_activated(const QString &arg1)
{
    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("cpu", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    dynamic_cast<UserPartSelection*>(cSub)->observerComboActivated("cpu", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->cpuCombo->setEnabled(false);
}

void MainWindow::on_mbCombo_activated(const QString &arg1)
{
    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("mainboard", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    dynamic_cast<UserPartSelection*>(cSub)->observerComboActivated("vga", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->mbCombo->setEnabled(false);
}

void MainWindow::on_vgaCombo_activated(const QString &arg1)
{
    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("vga", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    dynamic_cast<UserPartSelection*>(cSub)->observerComboActivated("ram", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->vgaCombo->setEnabled(false);
}

void MainWindow::on_ramCombo_activated(const QString &arg1)
{
    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("ram", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    dynamic_cast<UserPartSelection*>(cSub)->observerComboActivated("ssd", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->ramCombo->setEnabled(false);
}

void MainWindow::on_ssdCombo_activated(const QString &arg1)
{
    //cout << ui->ssdCombo->currentText().toStdString() << endl;
    if(ui->ssdCombo->currentText().toStdString().compare("no select") != 0){
        existSSD = true;
    }
    //cout << "on_ssdCombo_activated existSSD = " << existSSD << endl;

    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("ssd", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    dynamic_cast<UserPartSelection*>(cSub)->observerComboActivated("hdd", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->ssdCombo->setEnabled(false);
}

void MainWindow::on_hddCombo_activated(const QString &arg1)
{
    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("hdd", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    dynamic_cast<UserPartSelection*>(cSub)->observerComboActivated("powersupply", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->hddCombo->setEnabled(false);
}

void MainWindow::on_powerCombo_activated(const QString &arg1)
{
    dynamic_cast<UserPartSelection*>(cSub)->storeUserSelected("powersupply", arg1.split(QRegExp(","))[0].toLocal8Bit().constData());
    ui->powerCombo->setEnabled(false);

    ui->resultCombination->setEnabled(true);
}

void MainWindow::on_initCombination_clicked()
{
    dynamic_cast<UserPartSelection*>(cSub)->observerInitClicked();
    ui->cpuPrice->clear();
    ui->mbPrice->clear();
    ui->vgaPrice->clear();
    ui->ramPrice->clear();
    ui->ssdPrice->clear();
    ui->hddPrice->clear();
    ui->powerPrice->clear();
    ui->sumPrice->clear();

    ui->cpuDescription->clear();
    ui->mbDescription->clear();
    ui->vgaDescription->clear();
    ui->ramDescription->clear();
    ui->ssdDescription->clear();
    ui->hddDescription->clear();
    ui->powerDescription->clear();

    existSSD = false;
}

void MainWindow::on_resultCombination_clicked()
{
    dynamic_cast<UserPartSelection*>(cSub)->showResult();
}

void MainWindow::update(list<GameData> *selectableList, list<GameData> *selectionList){
    list<GameData>::iterator gdIter;
    ui->gameList->clear();
    for(gdIter = selectableList->begin(); gdIter != selectableList->end(); gdIter++){
        ui->gameList->addItem(QString::fromLocal8Bit(gdIter->getName().c_str()));
    }
    ui->selectedList->clear();
    for(gdIter = selectionList->begin(); gdIter != selectionList->end(); gdIter++){
        ui->selectedList->addItem(QString::fromLocal8Bit(gdIter->getName().c_str()));
    }
}

void MainWindow::update(list<Part*> *partRecList){

    if(ui->chooseGameTabs->currentIndex() == 0){ // if chooseGameTab is on
        ui->chooseGameTabs->removeTab(0); // remove chooseGameTab
        ui->chooseGameTabs->insertTab(1,ui->quoteTab,"Recommendation"); // add recommendation tab
    }
    ui->partRecTable->clear();
    ui->chooseGameTabs->setCurrentIndex(1);
    ui->partRecTable->setColumnCount(3);
    ui->partRecTable->setRowCount(8);
    ui->partRecTable->setHorizontalHeaderLabels(QStringList() << "Part Name" << "Price" << "Description");
    ui->partRecTable->setVerticalHeaderLabels(QStringList() << "CPU" << "Mainboard" << "VGA" << "RAM" << "SSD" << "HDD" << "PowerSupply" << "");
    ui->partRecTable->setColumnWidth(0,300);
    ui->partRecTable->setColumnWidth(1,90);
    ui->partRecTable->setColumnWidth(2,500);
    ui->partRecTable->setRowHeight(0, 60);
    ui->partRecTable->setRowHeight(1, 60);
    ui->partRecTable->setRowHeight(2, 60);
    ui->partRecTable->setRowHeight(3, 60);
    ui->partRecTable->setRowHeight(4, 60);
    ui->partRecTable->setRowHeight(5, 60);
    ui->partRecTable->setRowHeight(6, 60);

    list<Part*>::iterator ptIter;
    int i = 0;
    int totalPrice = 0;
    for(ptIter = partRecList->begin(); ptIter != partRecList->end(); ptIter++){
        ui->partRecTable->setItem(i, 0, new QTableWidgetItem(QString::fromLocal8Bit((*ptIter)->getName().c_str())));
        ui->partRecTable->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit((to_string((*ptIter)->getPrice())+"¿ø").c_str())));
        ui->partRecTable->setItem(i, 2, new QTableWidgetItem(QString::fromLocal8Bit((*ptIter)->getDescription().c_str())));
        totalPrice += (*ptIter)->getPrice();
        i++;
    }
    ui->partRecTable->setItem(7, 0, new QTableWidgetItem("                                                Sum :"));
    ui->partRecTable->setItem(7, 1, new QTableWidgetItem(QString::fromLocal8Bit((to_string(totalPrice)+"¿ø").c_str())));
}

void MainWindow::on_gameAdd_clicked() // when gameAdd button clicked
{
    QModelIndex index = ui->gameList->currentIndex();
    dynamic_cast<UserGameSelection*>(gSub)->observerGameAddClicked(index.data(Qt::DisplayRole).toString().toLocal8Bit().constData());
}

void MainWindow::on_gameDelete_clicked() // when gameDelete button clicked
{
    QModelIndex index = ui->selectedList->currentIndex();
    dynamic_cast<UserGameSelection*>(gSub)->observerGameDeleteClicked(index.data(Qt::DisplayRole).toString().toLocal8Bit().constData());
    // 0 is Add, 1 is Delete, 2 is Initialize, 3 is Recommendation
}

void MainWindow::on_gameClear_clicked()
{
    dynamic_cast<UserGameSelection*>(gSub)->observerGameInitializeClicked();
}

void MainWindow::on_recommend_clicked()
{
    dynamic_cast<UserGameSelection*>(gSub)->observerRecommendClicked();
}

void MainWindow::on_reselect_clicked()
{
    ui->chooseGameTabs->insertTab(0, ui->chooseGame, "Game Selection"); // add recommendation tab
    ui->chooseGameTabs->removeTab(1); // remove chooseGameTab
}

void MainWindow::on_printRecParts_clicked() {
    dynamic_cast<UserGameSelection*>(gSub)->observerPrintClicked();
}

void MainWindow::on_retry_clicked()
{
    dynamic_cast<UserGameSelection*>(gSub)->observerRecommendClicked();
}

void MainWindow::on_goToGameSelection_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->chooseGameTabs->setCurrentIndex(0);
}

void MainWindow::on_goToPartSelection_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->choosePartTabs->setCurrentIndex(0);
}
