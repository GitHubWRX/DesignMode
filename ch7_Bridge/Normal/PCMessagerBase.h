#ifndef PCMESSAGERBASE_H
#define PCMESSAGERBASE_H
#include "Messager.h"

// Base实现基于不同平台的基础功能，可能需要调平台接口
class PCMessagerBase : public Messager
{
private:
    /* data */
public:
    PCMessagerBase(/* args */);
    virtual void PlaySound(){
        cout << "PC PlaySound" << endl;
    }
    virtual void DrawShape(){
        cout << "PC DrawShape" << endl;
    }
    virtual void WriteText(){
        cout << "PC WriteText" << endl;
    }
    virtual void Connect(){
        cout << "PC Connect" << endl;
    }
    ~PCMessagerBase();
};

PCMessagerBase::PCMessagerBase(/* args */)
{
}

PCMessagerBase::~PCMessagerBase()
{
}


#endif