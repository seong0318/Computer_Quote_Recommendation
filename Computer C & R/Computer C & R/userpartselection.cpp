#include "userpartselection.h"

UserPartSelection::UserPartSelection(AllPartAndGameData *apag) : apag(apag){}

list<PartData> *UserPartSelection::getUserPartSelectableList(){return &userPartSelectableList;}
Part **UserPartSelection::getUserPartSelectionList(){return userPartSelectionList;}

AllPartAndGameData* UserPartSelection::getApag(){
    return apag;
}
void UserPartSelection::initializeUserPartSelectableList(){
    userPartSelectableList = *(apag->getAllPartDataList());
    for(list<PartData>::iterator pdIter = userPartSelectableList.begin(); pdIter != userPartSelectableList.end(); pdIter++){
        notify(&*pdIter, "cpu");
    }
}

void UserPartSelection::updateUserPartSelectableList(string partType){
    userPartSelectableList = *(apag->getAllPartDataList());
    for(list<PartData>::iterator pdIter = userPartSelectableList.begin(); pdIter != userPartSelectableList.end(); pdIter++){
        notify(&*pdIter, partType);
    }
}

void UserPartSelection::changeMainboardListCompatible(string cpuName){
    list<PartData>::iterator pdIter;
    list<Part*>::iterator ptIter;
        if(cpuName.compare("cpu")){
            string socketTemp;
            for(pdIter = userPartSelectableList.begin(); pdIter != userPartSelectableList.end(); pdIter++){
                if((pdIter->getPartName()).compare("cpu") == 0){
                    for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++) {
                        if((*ptIter)->getName().compare(cpuName) == 0){
                            socketTemp = ((CPU*)(*ptIter))->getSocket();
                            //cout << socketTemp << endl;
                            break;
                        }
                    }
                    break;
                }
            }
            //notify("mainboard"); //메인보드 콤보박스 초기화
            for(pdIter = userPartSelectableList.begin(); pdIter != userPartSelectableList.end(); pdIter++){
                if((pdIter->getPartName()).compare("mainboard") == 0){
                    ptIter = pdIter->getPartDataList()->begin();
                    while(ptIter != pdIter->getPartDataList()->end()){
                        if(((CPU*)(*ptIter))->getSocket().compare(socketTemp) != 0){
                            pdIter->getPartDataList()->erase(ptIter++); // 삭제가 되버려서 cpu 소켓이 다른 것으로 바꾸면 복구가 되지 않음.
                        }
                        else ptIter++;
                    }
                    break;
                }
            }
            notify(&*pdIter, "mainboard");
            //notify("mainboard", pList); //호환성 맞는 part observer에게 전달
       }
}

void UserPartSelection::changePowerListConsumption(){
    list<PartData>::iterator pdIter;
    list<Part*>::iterator ptIter;
    int sumOfPowerConsumption = 0;
    for(int i = 0; i < 6; i++){
        sumOfPowerConsumption += userPartSelectionList[i]->getPowerConsumption();
        //cout << "name = " << userPartSelectionList[i]->getName() << endl;
        //cout << "part powerconsumption = " << userPartSelectionList[i]->getPowerConsumption() << endl;
        //cout << "sum of powerconsumption = " << sumOfPowerConsumption << endl;
    }
    for(pdIter = userPartSelectableList.begin(); pdIter != userPartSelectableList.end(); pdIter++){
        if(pdIter->getPartName().compare("powersupply") == 0){
            ptIter = pdIter->getPartDataList()->begin();
            while(ptIter != pdIter->getPartDataList()->end()){
                if(dynamic_cast<PowerSupply*>(*ptIter)->getCapacity() < sumOfPowerConsumption + 100){
                    //cout << "power capacity = " << dynamic_cast<PowerSupply*>(*ptIter)->getCapacity() << endl;
                    pdIter->getPartDataList()->erase(ptIter++);
                }
                else ptIter++;
            }
            break;
        }
    }
    notify(&*pdIter, "powersupply");
}

void UserPartSelection::storeUserSelected(string partType, string partName){
    list<PartData>::iterator pdIter;
    list<Part*>::iterator ptIter;
    int it = 0;
    int priceval = 0;
    if(partName == "no select"){
        if(partType == "vga") userPartSelectionList[2] = new VGA("no select", 0, 0, " ", " ", 0);
        else if(partType == "ssd") userPartSelectionList[4] = new SSD("no select", 0, " ", 0);
        else if(partType == "hdd") userPartSelectionList[5] = new HDD("no select", 0, " ", 0);
    }
    else for(pdIter = apag->getAllPartDataList()->begin(); pdIter != apag->getAllPartDataList()->end(); pdIter++){
           if((pdIter->getPartName()).compare(partType) == 0){
               for(ptIter = pdIter->getPartDataList()->begin(); ptIter != pdIter->getPartDataList()->end(); ptIter++) {
                   if((*ptIter)->getName().compare(partName) == 0){
                       if(partType == "cpu"){
                         userPartSelectionList[0] = (*ptIter);
                         for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                             priceval = 0;
                             for(int j = 0; j <= it; j++) priceval += userPartSelectionList[j]->getPrice();
                             notify("cpu", (*ptIter)->getPrice() ,priceval);
                             notify("cpu", (*ptIter)->getDescription());
                         }
                       }
                       else if(partType == "mainboard"){
                           userPartSelectionList[1] = (*ptIter);
                           for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                               priceval = 0;
                               for(int j = 0; j <= it; j++) priceval += userPartSelectionList[j]->getPrice();
                               notify("mainboard", (*ptIter)->getPrice() ,priceval);
                               notify("mainboard", (*ptIter)->getDescription());
                           }
                       }
                       else if(partType == "vga"){
                           userPartSelectionList[2] = (*ptIter);
                           for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                               priceval = 0;
                               for(int j = 0; j <= it; j++)priceval += userPartSelectionList[j]->getPrice();
                               notify("vga", (*ptIter)->getPrice() ,priceval);
                               notify("vga", (*ptIter)->getDescription());
                           }
                       }
                       else if(partType == "ram"){
                           userPartSelectionList[3] = (*ptIter);
                           for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                               priceval = 0;
                               for(int j = 0; j <= it; j++)priceval += userPartSelectionList[j]->getPrice();
                               notify("ram", (*ptIter)->getPrice() ,priceval);
                               notify("ram", (*ptIter)->getDescription());
                           }
                       }
                       else if(partType == "ssd"){
                           userPartSelectionList[4] = (*ptIter);
                           for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                               priceval = 0;
                               for(int j = 0; j <= it; j++)priceval += userPartSelectionList[j]->getPrice();
                               notify("ssd", (*ptIter)->getPrice() ,priceval);
                               notify("ssd", (*ptIter)->getDescription());
                           }
                       }
                       else if(partType == "hdd"){
                           userPartSelectionList[5] = (*ptIter);
                           for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                               priceval = 0;
                               for(int j = 0; j <= it; j++)priceval += userPartSelectionList[j]->getPrice();
                               notify("hdd", (*ptIter)->getPrice() ,priceval);
                               notify("hdd", (*ptIter)->getDescription());
                           }
                       }
                       else if(partType == "powersupply"){
                           userPartSelectionList[6] = (*ptIter);
                           for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
                               priceval = 0;
                               for(int j = 0; j <= it; j++) priceval += userPartSelectionList[j]->getPrice();
                               notify("powersupply", (*ptIter)->getPrice() ,priceval);
                               notify("powersupply", (*ptIter)->getDescription());
                           }
                       }
                       break;
                   }
                }
             break;
           }
           it++;
        }
}

void UserPartSelection::registerObserver(CompatibilityObserver *compObs){
    getViews()->push_back(compObs);
}

void UserPartSelection::notify(PartData *pd, string partType){
    for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
        getViews()->at(i)->update(pd, partType);
    }
}

void UserPartSelection::notify(string partType, int price, int pricesum){
    for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
        getViews()->at(i)->update_price(partType, price, pricesum);
    }
}

void UserPartSelection::notify(string partType, string description){
    for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
        getViews()->at(i)->update_description(partType, description);
    }
}

void UserPartSelection::notify(Part** userSelectionList, list<GameData>* gamedata){
    for(vector<int>::size_type i = 0; i != getViews()->size(); i++){
        getViews()->at(i)->update_chart(userSelectionList, gamedata);
    }
}

void UserPartSelection::showResult(){
    notify(userPartSelectionList, apag->getAllGameDataList());
}


void UserPartSelection::observerComboActivated(string partType, string partName){
    if(partType.compare("cpu") == 0){       // == 0 없어서 추가했음
        //cout << "observercomboactivated = " << partType << endl;
        changeMainboardListCompatible(partName);
    }
    else if(partType.compare("powersupply") == 0){
        changePowerListConsumption();
    }
    else{
        //cout << "observercomboactivated = " << partType << endl;
        updateUserPartSelectableList(partType);
    }
}

void UserPartSelection::observerInitClicked(){
    updateUserPartSelectableList("init");// 초기화 후
    updateUserPartSelectableList("cpu");    // cpu 선택할 수 있도록 하기 위해서!
}

void UserPartSelection::setUserPartSelectionList(string PartName){

}

