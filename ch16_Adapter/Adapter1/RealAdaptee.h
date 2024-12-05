#ifndef REALADAPTEE_H
#define REALADAPTEE_H
#include "IAdaptee.h"
#include "../../common.h"

class RealAdaptee : public IAdaptee
{
private:
    /* data */
public:
    RealAdaptee(/* args */);
    virtual void foo(int data) override;
    virtual int bar() override;
    ~RealAdaptee();
};

RealAdaptee::RealAdaptee(/* args */)
{
}

inline void RealAdaptee::foo(int data)
{
    cout << "Love You " << data << endl;
}

inline int RealAdaptee::bar()
{
    return 1314;
}

RealAdaptee::~RealAdaptee()
{
}



#endif