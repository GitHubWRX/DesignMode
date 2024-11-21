#ifndef VedioSpliter_H
#define VedioSpliter_H

#include "ISpliter.h"

class VedioSpliter : public ISpliter
{
private:
    /* data */
public:
    VedioSpliter(/* args */);
    virtual void split(){
        cout << "I am a VedioSpliter, I am splitering Vedio File" << endl;
    }
    virtual VedioSpliter* clone(){
        return new VedioSpliter(*this);
    }
    virtual ~VedioSpliter();
};

VedioSpliter::VedioSpliter(/* args */)
{
}

VedioSpliter::~VedioSpliter()
{
}

#endif