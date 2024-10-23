#include "lib.h"
#include "app.h"

void main(){
    Lib lib;
    App app;

    // 在传统模式中，lib提供一些方法，然后在app自定义一些方法，最后main串起整个流程
    lib.Step1();

    if(app.Step2()){
        lib.Step3();
    }

    for (size_t i = 0; i < 4; i++)
    {
        /* code */
        app.Step4();
    }
}