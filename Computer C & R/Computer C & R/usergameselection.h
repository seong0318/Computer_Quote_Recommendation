#ifndef USERGAMESELECTION_H
#define USERGAMESELECTION_H
#include "gameselectionsubject.h"
#include "partdata.h"

class UserGameSelection : public GameSelectionSubject {
private:
    AllPartAndGameData *apag;
    list<GameData> userGameSelectableList;
    list<GameData> userGameSelectionList;
    list<Part*> partRecommendationList;
public:
    UserGameSelection(AllPartAndGameData *apag);
    list<GameData> *getUserGameSelectableList();
    list<GameData> *getUserGameSelectionList();
    list<Part*> *getPartRecommendationList();
    void setUserGameSelectionList(string gameName);
    void initializeUserGameSelectableList();
    void registerObserver(GameSelectionObserver *gameObs);
    void notify(list<GameData> *selectableList, list<GameData> *selectionList);
    void notify(list<Part*> * partRecList);
    void observerGameAddClicked(string gameName);
    void observerGameDeleteClicked(string gameName);
    void observerGameInitializeClicked();
    void observerRecommendClicked();
    void observerPrintClicked();
    void partRecommendation();
};

#endif // USERGAMESELECTION_H
