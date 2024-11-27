#ifndef StoneHouseBuilder_h
#define StoneHouseBuilder_h

#include "HouseBuilder.h"

class StoneHouseBuilder : public HouseBuilder
{
private:
    House* pHouse;
public:
    StoneHouseBuilder(House* house);
    virtual void BuildPart1() override{
        cout << "build part1" << endl;
    }
    virtual void BuildPart2() override{
        cout << "build part2" << endl;
    }
    virtual bool BuildPart3() override{
        cout << "build part3" << endl;
    }
    virtual void BuildPart4() override{
        cout << "build part4" << endl;
    }
    virtual void BuildPart5() override{
        cout << "build part5" << endl;
    }
    ~StoneHouseBuilder();
};

StoneHouseBuilder::StoneHouseBuilder(House* house):HouseBuilder(house)
{
    // 使用初始化列表调用父类的构造函数
}
StoneHouseBuilder::~StoneHouseBuilder()
{
}


#endif