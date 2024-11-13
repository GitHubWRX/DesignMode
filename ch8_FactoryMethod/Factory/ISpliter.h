#ifndef ISPLITER_H
#define ISPLITER_H

#include "IProgress.h"

class ISpliter
{
private:
    /* data */
public:
    ISpliter(/* args */);
    virtual int add_IProgress(IProgress* iprogress)=0;
    virtual int remove_IProgress(IProgress* iprogress)=0;
    virtual void split()=0;
    ~ISpliter();
};

ISpliter::ISpliter(/* args */)
{
}

ISpliter::~ISpliter()
{
}








#endif