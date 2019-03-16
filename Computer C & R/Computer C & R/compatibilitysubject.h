#ifndef COMPATIBILITYSUBJECT_H
#define COMPATIBILITYSUBJECT_H

#include <vector>
#include "compatibilityobserver.h"
#include "gamedata.h"

class CompatibilitySubject
{
private:
    vector<CompatibilityObserver*> views;
public:
    virtual ~CompatibilitySubject(){}
    virtual void registerObserver(CompatibilityObserver *compObs) = 0;
    virtual void notify(PartData *pd, string partType) = 0;
    virtual void notify(string partType, int price, int pricenum) = 0;
    virtual void notify(string partType, string description) = 0;
    virtual void notify(Part** userSelectionList, list<GameData>* gamedata) = 0;
    vector<CompatibilityObserver*> *getViews(){
        return &views;
    }
};

#endif // COMPATIBILITYSUBJECT_H
