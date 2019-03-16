#include "allpartandgamedata.h"
#include <fstream>

#include <qstring.h>
#include <qdir.h>

void AllPartAndGameData::openGameFiles() {
    QString path = QDir(QDir::currentPath()).filePath("gamelist.csv");
    cout << path.toLocal8Bit().constData() << endl;

    string nameTemp;
    string minRamTemp;
    string minCpuBenchmarkTemp;
    string minVgaBenchmarkTemp;
    string proRamTemp;
    string proCpuBenchmarkTemp;
    string proVgaBenchmarkTemp;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ifstream gameFile(path.toLocal8Bit().constData());
    if (gameFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no GAME file" << endl;
    }
    while (gameFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(gameFile, nameTemp, ',');
        getline(gameFile, minRamTemp, ',');            //need atoi
        getline(gameFile, minCpuBenchmarkTemp, ',');   //need atoi
        getline(gameFile, minVgaBenchmarkTemp, ',');   //need atoi
        getline(gameFile, proRamTemp, ',');            //need atoi
        getline(gameFile, proCpuBenchmarkTemp, ',');   //need atoi
        getline(gameFile, proVgaBenchmarkTemp, '\n');  //need atoi

        if (nameTemp.compare("") != 0) {               // 이거 안하면 공백인 것들이 object에 집어넣음
            allGameDataList.push_back(GameData(nameTemp, atoi(minRamTemp.c_str()), atoi(minCpuBenchmarkTemp.c_str()), atoi(minVgaBenchmarkTemp.c_str()), atoi(proRamTemp.c_str()), atoi(proCpuBenchmarkTemp.c_str()), atoi(proVgaBenchmarkTemp.c_str())));
        }
    }
    gameFile.close(); //파일 입출력 완료 후 닫아준다.
}

void AllPartAndGameData::openPartFiles() {
    QString path;

    string nameTemp;
    string socketTemp;
    string powerConsumptionTemp;
    string capacityTemp;
    string priceTemp;
    string cpuMultiBenchmarkTemp;
    string cpuSingleBenchmarkTemp;
    string vgaBenchmarkTemp;
    string descriptionTemp;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path = QDir(QDir::currentPath()).filePath("cpu.csv");
    ifstream cpuFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("cpu"));
    if (cpuFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no CPU file" << endl;
    }
    while (cpuFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(cpuFile, nameTemp, ',');
        getline(cpuFile, socketTemp, ',');
        getline(cpuFile, powerConsumptionTemp, ',');   //atoi
        getline(cpuFile, priceTemp, ',');            //atoi
        getline(cpuFile, cpuMultiBenchmarkTemp, ',');  //atoi
        getline(cpuFile, cpuSingleBenchmarkTemp, ','); //atoi
        getline(cpuFile, vgaBenchmarkTemp, ',');       //atoi
        getline(cpuFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new CPU(nameTemp, atoi(priceTemp.c_str()), atoi(powerConsumptionTemp.c_str()), descriptionTemp, socketTemp, atoi(cpuSingleBenchmarkTemp.c_str()), atoi(cpuMultiBenchmarkTemp.c_str()), atoi(vgaBenchmarkTemp.c_str())));
            //cout << "allpartdatalist pointer= "<<allPartDataList.back().getPartDataList() << endl;
            //cout << allPartDataList.back().getPartDataList()->back().getName() << endl;
        }
    }
    cpuFile.close(); //파일 입출력 완료 후 닫아준다.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path.clear();
    path = QDir(QDir::currentPath()).filePath("mainboard.csv");
    ifstream mbFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("mainboard"));

    if (mbFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no MB file" << endl;
    }
    while (mbFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(mbFile, nameTemp, ',');
        getline(mbFile, socketTemp, ',');
        getline(mbFile, priceTemp, ',');              //atoi
        getline(mbFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new Mainboard(nameTemp, atoi(priceTemp.c_str()), descriptionTemp, socketTemp));
        }
    }
    mbFile.close(); //파일 입출력 완료 후 닫아준다.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path.clear();
    path = QDir(QDir::currentPath()).filePath("vga.csv");
    ifstream vgaFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("vga"));

    if (vgaFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no VGA file" << endl;
    }
    while (vgaFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(vgaFile, nameTemp, ',');
        getline(vgaFile, vgaBenchmarkTemp, ',');       //atoi
        getline(vgaFile, powerConsumptionTemp, ',');   //atoi
        getline(vgaFile, socketTemp, ',');
        getline(vgaFile, priceTemp, ',');              //atoi
        getline(vgaFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new VGA(nameTemp, atoi(priceTemp.c_str()), atoi(powerConsumptionTemp.c_str()), descriptionTemp, socketTemp, atoi(vgaBenchmarkTemp.c_str())));
        }
    }
    vgaFile.close(); //파일 입출력 완료 후 닫아준다.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path.clear();
    path = QDir(QDir::currentPath()).filePath("ram.csv");
    ifstream ramFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("ram"));

    if (ramFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no RAM file" << endl;
    }
    while (ramFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(ramFile, nameTemp, ',');
        getline(ramFile, capacityTemp, ',');              //atoi
        getline(ramFile, priceTemp, ',');                 //atoi
        getline(ramFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new RAM(nameTemp, atoi(priceTemp.c_str()), descriptionTemp, atoi(capacityTemp.c_str())));
        }
    }
    ramFile.close(); //파일 입출력 완료 후 닫아준다.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path.clear();
    path = QDir(QDir::currentPath()).filePath("ssd.csv");
    ifstream ssdFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("ssd"));

    if (ssdFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no SSD File" << endl;
    }
    while (ssdFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(ssdFile, nameTemp, ',');
        getline(ssdFile, capacityTemp, ',');              //atoi
        getline(ssdFile, priceTemp, ',');                 //atoi
        getline(ssdFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new SSD(nameTemp, atoi(priceTemp.c_str()), descriptionTemp, atoi(capacityTemp.c_str())));
        }
    }
    ssdFile.close(); //파일 입출력 완료 후 닫아준다.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path.clear();
    path = QDir(QDir::currentPath()).filePath("hdd.csv");
    ifstream hddFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("hdd"));

    if (hddFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "There is no HDD file" << endl;
    }
    while (hddFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(hddFile, nameTemp, ',');
        getline(hddFile, capacityTemp, ',');              //atoi
        getline(hddFile, priceTemp, ',');                 //atoi
        getline(hddFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new HDD(nameTemp, atoi(priceTemp.c_str()), descriptionTemp, atoi(capacityTemp.c_str())));
        }
    }
    hddFile.close(); //파일 입출력 완료 후 닫아준다.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    path.clear();
    path = QDir(QDir::currentPath()).filePath("powersupply.csv");
    ifstream psFile(path.toLocal8Bit().constData());
    allPartDataList.push_back(PartData("powersupply"));

    if (psFile.fail())  //만약 bad() 함수가 실패 하면..
    {
        cout << "there is no PS file" << endl;
    }
    while (psFile.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
    {
        getline(psFile, nameTemp, ',');
        getline(psFile, capacityTemp, ',');              //atoi
        getline(psFile, priceTemp, ',');                 //atoi
        getline(psFile, descriptionTemp, '\n');

        if (nameTemp.compare("") != 0) {      // 이거 안하면 공백인 것들이 object에 집어넣음
            allPartDataList.back().getPartDataList()->push_back(new PowerSupply(nameTemp, atoi(priceTemp.c_str()), descriptionTemp, atoi(capacityTemp.c_str())));
        }
    }
    psFile.close(); //파일 입출력 완료 후 닫아준다.
}

list<PartData> *AllPartAndGameData::getAllPartDataList(){
    return &allPartDataList;
}

list<GameData> *AllPartAndGameData::getAllGameDataList(){
    return &allGameDataList;
}
