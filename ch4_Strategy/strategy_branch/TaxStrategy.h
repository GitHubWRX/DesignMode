#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

class TaxStrategy
{
private:
    /* data */
public:
    TaxStrategy(/* args */);
    ~TaxStrategy();
    // 这里的context如何定义？后续解决。定义为纯虚函数用于多态继承
    virtual double Calculate(const Context& context) = 0;
};

TaxStrategy::TaxStrategy(/* args */)
{
}

TaxStrategy::~TaxStrategy()
{
}

#endif