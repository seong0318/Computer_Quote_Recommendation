#ifndef COMPATIBILITYOBSERVER_H
#define COMPATIBILITYOBSERVER_H

#include "part.h"
#include <list>
#include "partdata.h"
#include "gamedata.h"
class AllPartAndGameData;
class CompatibilitySubject;

class CompatibilityObserver
{
private:
    CompatibilitySubject *model;
public:
    virtual ~CompatibilityObserver(){}
    virtual void update(PartData *pd, string partType) = 0;
    virtual void update_price(string name, int price, int pricesum)=0;
    virtual void update_description(string partType, string description) = 0;
    virtual void update_chart(Part** userSelectionList, list<GameData>* game) = 0;
    CompatibilitySubject *getCompatibilitySubject(){
        return model;
    }
};

#endif // COMPATIBILITYOBSERVER_H
