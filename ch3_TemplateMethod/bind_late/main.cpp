// #include "lib.h"
#include "app.h"

int main(){
    // Lib lib; 不允许使用抽象类类型 "Lib" 的对象:C/C++(322)
    App app;
    // 所有流程只需要使用Lib中定义好的Template Method，即run完成。
    app.run();
    return 0;
}