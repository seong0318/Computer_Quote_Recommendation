#ifndef GAMESELECTIONOBSERVER_H
#define GAMESELECTIONOBSERVER_H
#include <gamedata.h>
#include <list>
#include "part.h"
class GameSelectionSubject;

class GameSelectionObserver {
private:
    GameSelectionSubject *model;
public:
    virtual ~GameSelectionObserver(){}
    virtual void update(list<GameData> *selectableList, list<GameData> *selectionList) = 0;
    virtual void update(list<Part*> *partRecList) = 0;
    GameSelectionSubject *getGameSelectionSubject(){
        return model;
    }
};

#endif // GAMESELECTIONOBSERVER_H
