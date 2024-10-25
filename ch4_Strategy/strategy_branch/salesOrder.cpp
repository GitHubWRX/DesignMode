#include "../../common.h"
#include "CNStrategy.h"
#include "DEStrategy.h"
#include "USStrategy.h"


class SalesOrder{
private:
    TaxStrategy* strategy;
public:
    SalesOrder(StrategyFactory* strategyFactory){
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }

    double CalculateTax(){
        Context context(); // 此为函数声明，用于获取上下文信息
        double val = strategy->Calculate(context);
        return val;
    }
};
