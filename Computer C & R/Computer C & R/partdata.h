#ifndef PARTDATA_H
#define PARTDATA_H

#include <string>
#include <list>
#include "part.h"
using namespace std;

class PartData {   // 각 부품의 모든 목록을 지니고 있는 클래스
private:
    string partName;
    list<Part*> partDataList;
public:
    PartData(string myPartName);
    list<Part*> *getPartDataList();
    string getPartName();
};

#endif // PARTDATA_H
