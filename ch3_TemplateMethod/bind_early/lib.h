#ifndef LIB_H
#define LIB_H

#include "../../common.h"

class Lib
{
private:
    /* data */
public:
    Lib();
    ~Lib();
    void Step1();
    void Step3();
};

Lib::Lib()
{
}

Lib::~Lib()
{
}

void Lib::Step1(){
    cout << "lib step1" << endl;
}

void Lib::Step3(){
    cout << "lib step3" << endl;
}

#endif