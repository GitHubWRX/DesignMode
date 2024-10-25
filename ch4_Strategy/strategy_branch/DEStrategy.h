#ifndef DESTRATEGY_H
#define DESTRATEGY_H

#include "TaxStrategy.h"

class DEStrategy : public TaxStrategy
{
private:
    /* data */
public:
    DEStrategy(/* args */);
    virtual double Calculate(const Context& context) override;
    ~DEStrategy();
};

DEStrategy::DEStrategy(/* args */)
{
}

DEStrategy::~DEStrategy()
{
}

double DEStrategy::Calculate(const Context& context){
    // DEStrategy
}

#endif