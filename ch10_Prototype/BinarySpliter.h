#ifndef BinarySpliter_H
#define BinarySpliter_H

#include "ISpliter.h"

class BinarySpliter : public ISpliter
{
private:
    /* data */
public:
    BinarySpliter(/* args */);
    virtual void split(){
        cout << "I am a BinarySpliter, I am splitering Binary File" << endl;
    }
    virtual BinarySpliter* clone(){
        return new BinarySpliter(*this);
    }
    virtual ~BinarySpliter();
};

BinarySpliter::BinarySpliter(/* args */)
{
}

BinarySpliter::~BinarySpliter()
{
}

#endif