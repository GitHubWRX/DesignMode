#ifndef STONEHOUSE_H
#define STONEHOUSE_H

#include "House.h"
class StoneHouse : public House
{
private:
    /* data */
public:
    StoneHouse();
    ~StoneHouse();
protected:
    virtual void BuildPart1() override{
        cout << "build part1" << endl;
    }
    virtual void BuildPart1() override{
        cout << "build part2" << endl;
    }
    virtual void BuildPart1() override{
        cout << "build part3" << endl;
    }
    virtual void BuildPart1() override{
        cout << "build part4" << endl;
    }
    virtual void BuildPart1() override{
        cout << "build part5" << endl;
    }
};

StoneHouse::StoneHouse(/* args */)
{
    // 子类调用父类的初始化方法，实际上形成多态构造
    Init();
}

StoneHouse::~StoneHouse()
{
}

#endif