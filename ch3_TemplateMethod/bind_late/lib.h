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
    virtual int Step2() = 0;
    void Step3();
    virtual void Step4() = 0;
    void run();
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

void Lib::run(){
    // 谁来实现我的虚函数呢？看来是需要继承了，继承后将子类赋给父类指针，然后使用多态调用run
    cout << "run的函数定义在这里，这是一个需要被实现的定义" << endl;

    Step1();

    if(Step2()){
        Step3();
    }

    for (size_t i = 0; i < 4; i++)
    {
        Step4();
    }
}

#endif