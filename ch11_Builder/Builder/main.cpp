// main函数一般可以认为是Client的角色
#include "StoneHouse.h"
#include "StoneHouseBuilder.h"
#include "HouseDirector.h"

int main(){
    House* pHouse = new StoneHouse();
    HouseBuilder* pHouseBuilder = new StoneHouseBuilder(pHouse);
    HouseDirector* pHouseDirector = new HouseDirector(pHouseBuilder);
    pHouseDirector->Construct();
    cout << "pHouse is the new StoneHouse Constructed" << endl;

    delete pHouseDirector;
    delete pHouseBuilder;
    delete pHouse;
}

