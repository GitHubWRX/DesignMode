#ifndef HOUSE_H
#define HOUSE_H

#include "../common.h"
class House
{
private:
    /* data */
public:
    House(/* args */);
    /* 
    此处的Init不可以使用House的构造函数来替代，理由如下：
    1. 构造函数实际上需要调用子类的override版本函数，而子类的实例化晚于父类，会违背伦理
    2. Init在子类重写方法后，再调用。这样可以产生多态的效果，因此子类的构造函数可以调用Init
    3. 如果父类的protected方法并不是纯虚函数，其实可以放在House()构造函数中，不会依赖子类
    */
    void Init(){
        this->BuildPart1();
        for(int i = 0; i < 4; i++){
            this->BuildPart2();
        }
        bool flag = this->BuildPart3();
        if(flag){
            this->BuildPart4();
        }
        this->BuildPart5();
    }
    ~House();

protected:
    // 这些接口对外暴露没有意义，要组合在一起才生效
    virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual bool BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
};

House::House(/* args */)
{
}

House::~House()
{
}


#endif