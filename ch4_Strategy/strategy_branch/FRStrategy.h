#ifndef CNSTRATEGY_H
#define CNSTRATEGY_H

#include "TaxStrategy.h"

class FRStrategy : public TaxStrategy
{
private:
    /* data */
public:
    FRStrategy(/* args */);
    virtual double Calculate(const Context& context) override;
    ~FRStrategy();
};

FRStrategy::FRStrategy(/* args */)
{
}

FRStrategy::~FRStrategy()
{
}

double FRStrategy::Calculate(const Context& context){
    // FRStrategy
}

#endif