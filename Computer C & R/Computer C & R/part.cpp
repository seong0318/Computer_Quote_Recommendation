#include "part.h"

Part::Part(const string myName, const int myPrice, const int myPowerConsumption, const string myDescription)
: name(myName), price(myPrice), powerConsumption(myPowerConsumption), description(myDescription) {}

string Part::getName() {
    return name;
}

int Part::getPrice(){
    return price;
}

int Part::getPowerConsumption(){
    return powerConsumption;
}

string Part::getDescription(){
    return description;
}

CPU::CPU(const string myName, const int myPrice, const int myPowerConsumption, const string myDescription, const string mySocket, const int mySingleBenchmark, const int myMultiBenchmark, const int myVgaBenchmark)
    : Part(myName, myPrice, myPowerConsumption, myDescription) {
    socket = mySocket;
    cpuSingleBenchmark = mySingleBenchmark;
    cpuMultiBenchmark = myMultiBenchmark;
    vgaBenchmark = myVgaBenchmark;
}

int CPU::getSingleBenchmark(){
    return cpuSingleBenchmark;
}

int CPU::getMultiBenchmark(){
    return cpuMultiBenchmark;
}

int CPU::getVgaBenchmark(){
    return vgaBenchmark;
}

string CPU::getSocket(){
    return socket;
}

string CPU::getPartType(){
    return "CPU";
}

VGA::VGA(const string myName, const int myPrice, const int myPowerConsumption, string myDescription, const string mySocket, const int myVgaBenchmark)
    : Part(myName, myPrice, myPowerConsumption, myDescription) {
    socket = mySocket;
    vgaBenchmark = myVgaBenchmark;
}
int VGA::getVgaBenchmark(){
    return vgaBenchmark;
}

string VGA::getPartType(){
    return "VGA";
}

PowerSupply::PowerSupply(const string myName, const int myPrice, const string myDescription, const int mycapacity)
    : Part(myName, myPrice, 1, myDescription) {  // 전력 소모량( 기본 대기 전력 = 1 )
    capacity = mycapacity;
}

string PowerSupply::getPartType(){
    return "PowerSupply";
}

int PowerSupply::getCapacity(){
    return capacity;
}

RAM::RAM(const string myName, const int myPrice, const string myDescription, const int myCapacity)
    : Part(myName, myPrice, 2, myDescription) {   // 전력 소모량( 기본 대기 전력 = 2 )
    capacity = myCapacity;
}

string RAM::getPartType(){
    return "RAM";
}

int RAM::getCapacity(){
    return capacity;
}

SSD::SSD(const string myName, const int myPrice, const string myDescription, const int myCapacity)
    : Part(myName, myPrice, 3, myDescription) {   // 전력 소모량( 기본 대기 전력 = 5 )
    capacity = myCapacity;
}

string SSD::getPartType(){
    return "SSD";
}

HDD::HDD(const string myName, const int myPrice, const string myDescription, const int myCapacity)
    : Part(myName, myPrice, 15, myDescription) {  // 전력 소모량( 기본 대기 전력 = 7 )
    capacity = myCapacity;
}

string HDD::getPartType(){
    return "HDD";
}

Mainboard::Mainboard(const string myName, const int myPrice, const string myDescription, const string mySocket)
    : Part(myName, myPrice, 30, myDescription) {  // 전력 소모량( 기본 대기 전력 = 45 )
    socket = mySocket;
}

string Mainboard::getSocket(){
    return socket;
}

string Mainboard::getPartType(){
    return "Mainboard";
}
