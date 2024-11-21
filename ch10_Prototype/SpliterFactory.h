#ifndef SPLITERFACTORY_H
#define SPLITERFACTORY_H
#include "ISpliter.h"

class SpliterFactory
{
private:
    /* data */
public:
    SpliterFactory(/* args */);
    virtual ISpliter* createSpliter()=0;
    virtual ~SpliterFactory();
};

SpliterFactory::SpliterFactory(/* args */)
{
}

SpliterFactory::~SpliterFactory()
{
}


#endif