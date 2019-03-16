#include "gamedata.h"

GameData::GameData(const string gamename, int minram, int mincpu, int minvga, int proram, int procpu, int provga) {
    name = gamename;
    minRam = minram;
    minCpu = mincpu;
    minVga = minvga;
    properRam = proram;
    properCpu = procpu;
    properVga = provga;
}

string GameData::getName(){
    return name;
}

int GameData::getMinCPU(){
    return minCpu;
}

int GameData::getMinRam(){
    return minRam;
}

int GameData::getMinVga(){
    return minVga;
}

int GameData::getProperCpu(){
    return properCpu;
}

int GameData::getProperRam(){
    return properRam;
}

int GameData::getProperVga(){
    return properVga;
}
