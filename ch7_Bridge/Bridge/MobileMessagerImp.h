#ifndef MOBILEMESSAGERBASE_H
#define MOBILEMESSAGERBASE_H
#include "MessagerImp.h"
#include "../../common.h"

class MobileMessagerImp : public MessagerImp
{
private:
    /* data */
public:
    MobileMessagerImp();
    virtual void PlaySound() override{
        cout << "Mobile PlaySound" << endl;
    }
    virtual void DrawShape() override{
        cout << "Mobile DrawShape" << endl;
    }
    virtual void WriteText() override{
        cout << "Mobile WriteText" << endl;
    }
    virtual void Connect() override{
        cout << "Mobile Connect" << endl;
    }
    ~MobileMessagerImp();
};

MobileMessagerImp::MobileMessagerImp()
{
}

MobileMessagerImp::~MobileMessagerImp()
{
}


#endif