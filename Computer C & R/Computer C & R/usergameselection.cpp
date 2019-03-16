#include "usergameselection.h"
#include "allpartandgamedata.h"
#include "part.h"
#include <ctime>
#include "fstream"
#include "iostream"

UserGameSelection::UserGameSelection(AllPartAndGameData *apag) : apag(apag){}

list<GameData>* UserGameSelection::getUserGameSelectableList(){return &userGameSelectableList;}
list<GameData>* UserGameSelection::getUserGameSelectionList(){return &userGameSelectionList;}
list<Part*>* UserGameSelection::getPartRecommendationList(){return &partRecommendationList;}

void UserGameSelection::initializeUserGameSelectableList(){
    userGameSelectableList = *(apag->getAllGameDataList());
    userGameSelectionList.clear();
    for(list<GameData>::iterator gdIter = userGameSelectableList.begin(); gdIter != userGameSelectableList.end(); gdIter++){
        notify(getUserGameSelectableList(), getUserGameSelectionList());
    }
}

void UserGameSelection::observerPrintClicked(){
    list<Part*>::iterator ptIter;
    ofstream outFile("C:\\Users\\Michael\\Desktop\\output.txt");
    for(ptIter = getPartRecommendationList()->begin() ; ptIter != getPartRecommendationList()->end() ; ptIter++){
        outFile << (*ptIter)->getPartType() + ":" << endl;
        outFile << (*ptIter)->getName() << endl << endl;
    }
    outFile.close();
}

void UserGameSelection::registerObserver(GameSelectionObserver *compObs){
    getViews()->push_back(compObs);
}

void UserGameSelection::notify(list<GameData> *selectableList, list<GameData> *selectionList){
    for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
        getViews()->at(i)->update(selectableList, selectionList);
    }
}

void UserGameSelection::notify(list<Part*> *partRecList){
    for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
        getViews()->at(i)->update(partRecList);
    }
}

void UserGameSelection::observerGameAddClicked(string gameName){
    list<GameData>::iterator gdIter;
    for(gdIter = getUserGameSelectableList()->begin(); gdIter != getUserGameSelectableList()->end(); gdIter++){
        if(gdIter->getName().compare(gameName) == 0){
            getUserGameSelectionList()->push_back(*gdIter);
            getUserGameSelectableList()->erase(gdIter);
            notify(getUserGameSelectableList(), getUserGameSelectionList());
            break;
        }
    }
}

void UserGameSelection::observerGameDeleteClicked(string gameName){
    list<GameData>::iterator gdIter;
    for(gdIter = getUserGameSelectionList()->begin(); gdIter != getUserGameSelectionList()->end(); gdIter++){
        if(gdIter->getName().compare(gameName) == 0){
            getUserGameSelectableList()->push_back(*gdIter);
            getUserGameSelectionList()->erase(gdIter);
            notify(getUserGameSelectableList(), getUserGameSelectionList());
            break;
        }
    }
}

void UserGameSelection::observerGameInitializeClicked(){
    initializeUserGameSelectableList();
}

void UserGameSelection::observerRecommendClicked(){
    partRecommendation();
}

void UserGameSelection::partRecommendation(){
    if(getUserGameSelectionList()->empty() == false){ // only if userGameSelectionList is not empty
        getPartRecommendationList()->clear(); // clears the prev partRecommendationList
        list<PartData>::iterator pdIter;
        for(pdIter = apag->getAllPartDataList()->begin(); pdIter != apag->getAllPartDataList()->end(); pdIter++){ // part type loop
            if(pdIter->getPartName() == "cpu"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    list<GameData>::iterator gdIter;
                    list<GameData>::iterator gdIter2 = getUserGameSelectionList()->begin();
                    bool pass = false;
                    for(gdIter = getUserGameSelectionList()->begin(); gdIter != getUserGameSelectionList()->end(); gdIter++){ // game loop
                        if(dynamic_cast<CPU*>((*ptIter))->getMultiBenchmark() >= gdIter->getProperCpu()){ // cpu benchmark is higher than game proper benchmark.
                            gdIter2++;
                        }
                        if(gdIter2 == getUserGameSelectionList()->end() && ((rand() % 20) == 0)){ // if all cpu benchmark test passed and probability 5% passed
                            getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                            //cout << (*ptIter)->getName() << endl;
                            pass = true;
                        }
                    }
                    if(pass == true){ // to escape for loop faster...
                        break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){ // if nothing is selected until the end.. do the loop again
                        ptIter = --(pdIter->getPartDataList()->begin());
                    }
                }
            }
            else if(pdIter->getPartName() == "mainboard"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    if(dynamic_cast<Mainboard*>((*ptIter))->getSocket().compare(dynamic_cast<CPU*>(*getPartRecommendationList()->begin())->getSocket()) == 0  && (rand() % 20) == 0) { // if same socket CPU-MB && probability 5% passed
                        getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                        //cout << (*ptIter)->getName() << endl;
                        break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){ // if nothing is selected until the end.. do the loop again
                        ptIter = --(pdIter->getPartDataList()->begin());
                    }
                }
            }
            else if(pdIter->getPartName() == "vga"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    list<GameData>::iterator gdIter;
                    list<GameData>::iterator gdIter2 = getUserGameSelectionList()->begin();
                    bool pass = false;
                    for(gdIter = getUserGameSelectionList()->begin(); gdIter != getUserGameSelectionList()->end(); gdIter++){ // game loop
                        if(dynamic_cast<VGA*>((*ptIter))->getVgaBenchmark() >= gdIter->getProperVga()){ // cpu benchmark is higher than game proper benchmark.
                            gdIter2++;
                        }
                        if(gdIter2 == getUserGameSelectionList()->end() && ((rand() % 20) == 0)){ // if all cpu benchmark test passed and probability 5% passed
                            getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                            //cout << (*ptIter)->getName() << endl;
                            pass = true;
                        }
                    }
                    if(pass == true){ // to escape for loop faster...
                        break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){  // if nothing is selected until the end.. do the loop again
                        ptIter = --(pdIter->getPartDataList()->begin());
                    }
                }
            }
            else if(pdIter->getPartName() == "ram"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    list<GameData>::iterator gdIter;
                    list<GameData>::iterator gdIter2 = getUserGameSelectionList()->begin();
                    bool pass = false;
                    for(gdIter = getUserGameSelectionList()->begin(); gdIter != getUserGameSelectionList()->end(); gdIter++){ // game loop
                        if(dynamic_cast<RAM*>((*ptIter))->getCapacity() >= gdIter->getProperRam()){ // cpu benchmark is higher than game proper benchmark.
                            gdIter2++;
                        }
                        if(gdIter2 == getUserGameSelectionList()->end() && ((rand() % 20) == 0)){ // if all cpu benchmark test passed and probability 5% passed
                            getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                            //cout << (*ptIter)->getName() << endl;
                            pass = true;
                        }
                    }
                    if(pass == true){ // to escape for loop faster...
                        break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){  // if nothing is selected until the end
                        ptIter = --(pdIter->getPartDataList()->begin());
                    }
                }
            }
            else if(pdIter->getPartName() == "ssd"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    if((rand() % 20) == 0) { // probability 5% passed
                        getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                        //cout << (*ptIter)->getName() << endl;
                        break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){  // if nothing is selected until the end.. do the loop again
                        ptIter = --(pdIter->getPartDataList()->begin());
                    }
                }
            }
            else if(pdIter->getPartName() == "hdd"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    if((rand() % 20) == 0) { // probability 5% passed
                        getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                        //cout << (*ptIter)->getName() << endl;
                        break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){ // if nothing is selected until the end.. do the loop again
                        ptIter = --(pdIter->getPartDataList()->begin());
                    }
                }
            }
            else if(pdIter->getPartName() == "powersupply"){ //cout << "shit" << endl;
                list<Part*>::iterator ptIter;
                int totalPowerConsumption = 0;
                for(ptIter = getPartRecommendationList()->begin(); ptIter != getPartRecommendationList()->end(); ptIter++){ // part loop
                    totalPowerConsumption += (*ptIter)->getPowerConsumption(); // calculate total power consumption
                }
                for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++){ // part loop
                    if((rand() % 20) == 0 && totalPowerConsumption + 50 <= dynamic_cast<PowerSupply*>((*ptIter))->getCapacity()
                            && dynamic_cast<PowerSupply*>((*ptIter))->getCapacity() <= totalPowerConsumption + 200) { // probability 5% and power consumption check passed
                            getPartRecommendationList()->push_back(*(ptIter)); // insert part to recommendation list
                            //cout << (*ptIter)->getName() << endl;
                            break;
                    }
                    else if(ptIter == --(pdIter->getPartDataList()->end())){ // if nothing is selected until the end.. do the loop again
                        ptIter = --(pdIter->getPartDataList()->begin());
                        cout << "shit" << endl;
                    }
                }
            }
        }
        notify(getPartRecommendationList());
    }
}
