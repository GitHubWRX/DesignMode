#ifndef MOBILEMESSAGERBASE_H
#define MOBILEMESSAGERBASE_H
#include "Messager.h"

class MobileMessagerBase
{
private:
    /* data */
public:
    MobileMessagerBase(/* args */);
    virtual void PlaySound(){
        cout << "Mobile PlaySound" << endl;
    }
    virtual void DrawShape(){
        cout << "Mobile DrawShape" << endl;
    }
    virtual void WriteText(){
        cout << "Mobile WriteText" << endl;
    }
    virtual void Connect(){
        cout << "Mobile Connect" << endl;
    }
    ~MobileMessagerBase();
};

MobileMessagerBase::MobileMessagerBase(/* args */)
{
}

MobileMessagerBase::~MobileMessagerBase()
{
}


#endif