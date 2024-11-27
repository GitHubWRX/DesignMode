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
};

StoneHouse::StoneHouse(/* args */)
{
}

StoneHouse::~StoneHouse()
{
}

#endif