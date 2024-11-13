#ifndef SPLITERFACTORY_H
#define SPLITERFACTORY_H

#include "../../common.h"
#include "ISpliter.h"

class SpliterFactory
{
private:
    /* data */
public:
    SpliterFactory(/* args */);
    virtual ISpliter* CreateSpliter()=0;
    virtual ~SpliterFactory();
};

SpliterFactory::SpliterFactory(/* args */)
{
}

SpliterFactory::~SpliterFactory()
{
}




#endif