#ifndef HouseBuilder_h
#define HouseBuilder_h

#include "House.h"

class HouseBuilder
{
private:
    /* data */
    House* pHouse;
public:
    HouseBuilder(House* house);
    virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual bool BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
    ~HouseBuilder();
};

HouseBuilder::HouseBuilder(House* house)
{
    pHouse = house;
}

HouseBuilder::~HouseBuilder()
{
}

#endif