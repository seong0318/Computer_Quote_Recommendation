#ifndef USERPARTSELECTION_H
#define USERPARTSELECTION_H
#include "compatibilitysubject.h"
#include "allpartandgamedata.h"

class UserPartSelection : public CompatibilitySubject {
private:
    AllPartAndGameData *apag;              // original data of part and game list (used for part data list initialize)
    list<PartData> userPartSelectableList; // part data list that user can select in GUI (changes when compatibility applied)
    Part* userPartSelectionList[10];        // part list that user currently selected (used for game performance prediction)
public:
    UserPartSelection(AllPartAndGameData *apag);
    AllPartAndGameData* getApag();
    list<PartData> *getUserPartSelectableList();
    Part **getUserPartSelectionList();
    void setUserPartSelectionList(string partName);
    void initializeUserPartSelectableList();
    void updateUserPartSelectableList(string partType);
    void changeMainboardListCompatible(string cpuName);
    void changePowerListConsumption();
    void storeUserSelected(string partType, string partName);
    void registerObserver(CompatibilityObserver *compObs);
    void showResult();
    void notify(PartData *pd, string partType);
    void notify(string partType, int price, int pricesum);
    void notify(string partType, string description);
    void notify(Part** userSelectionList, list<GameData>* gamedata);
    void observerComboActivated(string partType, string partName);
    void observerInitClicked();
};

#endif // USERPARTSELECTION_H
