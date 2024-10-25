#include "../common.h"
#include "tax.h"

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        if (tax == CN_Tax){
            // CN***
        }else if(tax == US_Tax){
            // US***
        }else if(tax == DE_Tax){
            // DE***
        }
    }
};
