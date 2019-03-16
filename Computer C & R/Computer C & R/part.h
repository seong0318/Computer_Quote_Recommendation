#ifndef PART_H
#define PART_H

#include <string>
using namespace std;

class Part {               // 부품들이 모두 통합되어 있는 class
private:
    string name;           // 부품의 이름
    int price;              // 부품의 가격
    int powerConsumption;   // 부품의 전력 소비량(w)
    string description;       // 부품의 상세설명
public:
    Part(const string myName, const int myPrice, const int myPowerConsumption, const string myDescription);
    virtual ~Part(){}
    string getName();
    int getPrice();
    int getPowerConsumption();
    string getDescription();
    virtual string getPartType() = 0;
};

class CPU : public Part {
private:
    string socket;          // cpu 소켓
    int cpuSingleBenchmark; // 멀티 벤치마크 점수
    int cpuMultiBenchmark;  // 싱글 벤치마크 점수
    int vgaBenchmark;       // 그래픽 점수
public:
    CPU(const string myName, const int myPrice, const int myPowerConsumption, const string myDescription, const string mySocket, const int mySingleBenchmark, const int myMultiBenchmark, const int myVgaBenchmark);
    int getSingleBenchmark();
    int getMultiBenchmark();
    int getVgaBenchmark();
    string getSocket();
    virtual string getPartType();
};

class VGA : public Part {
private:
    string socket;           // vga 소켓
    int vgaBenchmark;        // 그래픽 점수
public:
    VGA(const string myName, const int myPrice, const int myPowerConsumption, string myDescription, const string mySocket, const int myVgaBenchmark);
    int getVgaBenchmark();
    virtual string getPartType();
};

class PowerSupply : public Part {
private:
    int capacity;           // 파워 용량
public:
    PowerSupply(const string myName, const int myPrice, const string myDescription, const int mycapacity);
    int getCapacity();
    virtual string getPartType();
};

class RAM : public Part {
private:
    int capacity;           // 램 용량(단위: GB)
public:
    RAM(const string myName, const int myPrice, const string myDescription, const int myCapacity);
    int getCapacity();
    virtual string getPartType();
};

class SSD : public Part {
private:
    int capacity;           // ssd 용량(단위: GB)
public:
    SSD(const string myName, const int myPrice, const string myDescription, const int myCapacity);
    virtual string getPartType();
};

class HDD : public Part {
private:
    int capacity;           // hdd 용량(단위: GB)
public:
    HDD(const string myName, const int myPrice, const string myDescription, const int myCapacity);
    virtual string getPartType();
};

class Mainboard : public Part {
private:
    string socket;          // 메인보드 소켓
public:
    Mainboard(const string myName, const int myPrice, const string myDescription, const string mySocket);
    string getSocket();
    virtual string getPartType();
};


#endif // PART_H
