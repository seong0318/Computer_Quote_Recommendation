#ifndef ALLPARTANDGAMEDATA_H
#define ALLPARTANDGAMEDATA_H

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include "partdata.h"
#include "gamedata.h"
#include "compatibilitysubject.h"
#include "gameselectionsubject.h"
class MainWindow;

class AllPartAndGameData {   // 모든 부품의 모든 목록과 게임 목록을 지니고 있는 클래스
private:
    list<PartData> allPartDataList;
    list<GameData> allGameDataList;
public:
    list<PartData> *getAllPartDataList();
    list<GameData> *getAllGameDataList();
    void openGameFiles();
    void openPartFiles();
};
#endif // ALLPARTANDGAMEDATA_H
