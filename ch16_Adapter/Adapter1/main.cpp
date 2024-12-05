// 只需要导入实现的类型即可
#include "RealAdaptee.h"
#include "Adapter.h"

int main(){
    IAdaptee* adaptee = new RealAdaptee();
    Adapter* adapter = new Adapter(adaptee);
    
    adapter->process();

    delete adapter;
    delete adaptee;
}