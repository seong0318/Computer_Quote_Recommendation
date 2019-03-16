#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "compatibilityobserver.h"
#include "allpartandgamedata.h"
#include "compatibilitysubject.h"
#include "gameselectionobserver.h"
#include "gameselectionsubject.h"
#include "chartview.h"


#include "userpartselection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public CompatibilityObserver, public GameSelectionObserver //관찰자
{
    Q_OBJECT
    CompatibilitySubject *cSub;
    GameSelectionSubject *gSub;

    //UserPartSelection *uPs;

public:
    explicit MainWindow(CompatibilitySubject *cSub, GameSelectionSubject *gSub, QWidget *parent = nullptr); //subject 인자 추가
    ~MainWindow(); 

    void update_chart(UserPartSelection* pa, list<GameData> *gdList);
    void update(PartData *pd, string partType);
    void update_price(string name, int price, int pricesum);
    void update_description(string partType, string description);
    void update_chart(Part** pa, list<GameData> *gdList);
    void update(list<GameData> *selectableList, list<GameData> *selectionList);
    void update(list<Part*> *partRecList);

private slots:
    void on_cpuCombo_activated(const QString &arg1);

    void on_mbCombo_activated(const QString &arg1);

    void on_vgaCombo_activated(const QString &arg1);

    void on_ramCombo_activated(const QString &arg1);

    void on_ssdCombo_activated(const QString &arg1);

    void on_hddCombo_activated(const QString &arg1);

    void on_powerCombo_activated(const QString &arg1);

    void on_initCombination_clicked();

    void on_resultCombination_clicked();

    void on_gameAdd_clicked();

    void on_gameDelete_clicked();

    void on_gameClear_clicked();

    void on_recommend_clicked();

    void on_reselect_clicked();

    void on_printRecParts_clicked();

    void on_retry_clicked();

    void on_goToGameSelection_clicked();

    void on_goToPartSelection_clicked();

private:
    Ui::MainWindow *ui;

    static bool existSSD;
};

#endif // MAINWINDOW_H
