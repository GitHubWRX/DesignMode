#ifndef ISPLITER_H
#define ISPLITER_H

// Prototype不需要反复地构造类，只需要拷贝模板类，再稍作修改和扩展即可
#include "../common.h"

class ISpliter
{
private:
    /* data */
public:
    ISpliter(/* args */);
    virtual void split()=0;
    virtual ISpliter* clone()=0;
    virtual ~ISpliter();
};

ISpliter::ISpliter(/* args */)
{
}

ISpliter::~ISpliter()
{
}

#endif