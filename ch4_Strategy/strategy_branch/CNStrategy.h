#ifndef CNSTRATEGY_H
#define CNSTRATEGY_H

#include "TaxStrategy.h"

class CNStrategy : public TaxStrategy
{
private:
    /* data */
public:
    CNStrategy(/* args */);
    virtual double Calculate(const Context& context) override;
    ~CNStrategy();
};

CNStrategy::CNStrategy(/* args */)
{
}

CNStrategy::~CNStrategy()
{
}

double CNStrategy::Calculate(const Context& context){
    // CNStrategy
}

#endif