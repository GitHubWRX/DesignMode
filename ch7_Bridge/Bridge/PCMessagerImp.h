#ifndef PCMESSAGERBASE_H
#define PCMESSAGERBASE_H
#include "MessagerImp.h"
#include "../../common.h"

// Base实现基于不同平台的基础功能，可能需要调平台接口
class PCMessagerImp : public MessagerImp
{
private:
    /* data */
public:
    PCMessagerImp();
    virtual void PlaySound() override{
        cout << "PC PlaySound" << endl;
    }
    virtual void DrawShape() override{
        cout << "PC DrawShape" << endl;
    }
    virtual void WriteText() override{
        cout << "PC WriteText" << endl;
    }
    virtual void Connect() override{
        cout << "PC Connect" << endl;
    }
    ~PCMessagerImp();
};

PCMessagerImp::PCMessagerImp()
{
}

PCMessagerImp::~PCMessagerImp()
{
}


#endif