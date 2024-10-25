#ifndef USSTRATEGY_H
#define USSTRATEGY_H

#include "TaxStrategy.h"

class USStrategy : public TaxStrategy
{
private:
    /* data */
public:
    USStrategy(/* args */);
    virtual double Calculate(const Context& context) override;
    ~USStrategy();
};

USStrategy::USStrategy(/* args */)
{
}

USStrategy::~USStrategy()
{
}

double USStrategy::Calculate(const Context& context){
    // USStrategy
}

#endif