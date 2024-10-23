#ifndef App_H
#define App_H

#include "../../common.h"
#include "lib.h"

class App : public Lib
{
private:
    /* data */
public:
    App();
    int Step2() override;
    void Step4() override;
    ~App();
};

App::App()
{
}

App::~App()
{
}

int App::Step2(){ // 这里不需要写override，仅在声明的地方即可
    cout << "lib step2" << endl;
    std::random_device rd;  // 生成随机种子
    std::mt19937 gen(rd()); // 使用梅森旋转算法的随机数引擎
    std::uniform_int_distribution<> distrib(1, 100); // 生成1到100之间的均匀分布整数
    int randomNumber = distrib(gen); // 生成随机数
    return randomNumber;
}

void App::Step4(){
    cout << "lib step4" << endl;
}

#endif