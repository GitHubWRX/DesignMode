#ifndef HOUSEDIRECTOR_H
#define HOUSEDIRECTOR_H
// 这个是稳定的，分离出来后不需要经常变化
#include "HouseBuilder.h"
class HouseDirector
{
private:
    HouseBuilder* pHouseBuilder;
public:
    HouseDirector(HouseBuilder* houseBuilder);

    House* Construct(){
        pHouseBuilder->BuildPart1();
        for(int i = 0; i < 4; i++){
            pHouseBuilder->BuildPart2();
        }
        bool flag = pHouseBuilder->BuildPart3();
        if(flag){
            pHouseBuilder->BuildPart4();
        }
        pHouseBuilder->BuildPart5();
    }

    ~HouseDirector();
};

HouseDirector::HouseDirector(HouseBuilder *houseBuilder)
{
    pHouseBuilder = houseBuilder;
}

HouseDirector::~HouseDirector()
{
}

#endif