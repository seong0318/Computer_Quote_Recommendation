#ifndef GAMESELECTIONSUBJECT_H
#define GAMESELECTIONSUBJECT_H
#include "gameselectionobserver.h"
#include <vector>
#include "part.h"
class AllPartAndGameData;

class GameSelectionSubject {
private:
    vector<GameSelectionObserver*> views;
public:
    virtual ~GameSelectionSubject(){}
    virtual void registerObserver(GameSelectionObserver *initObs) = 0;
    virtual void notify(list<GameData> *selectableList, list<GameData> *selectionList) = 0;
    virtual void notify(list<Part*> * partRecList) = 0;
    vector<GameSelectionObserver*> *getViews(){
        return &views;
    }
};

#endif // GAMESELECTIONSUBJECT_H
