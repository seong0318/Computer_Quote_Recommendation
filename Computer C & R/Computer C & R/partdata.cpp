#include "partdata.h"
#include <list>

PartData::PartData(string myPartName) {
    partName = myPartName;
}

list<Part *> *PartData::getPartDataList() {
    return &partDataList;
}

string PartData::getPartName(){
    return partName;
}
