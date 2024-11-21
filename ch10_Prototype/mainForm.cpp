#include "SpliterFactory.h"

class mainForm {
private:
    SpliterFactory* factory; // 工厂基类指针
public:
    mainForm(SpliterFactory* fc) : factory(fc) {}

    void Button1_Click() {
        ISpliter* spliter = factory->createSpliter(); // 获取具体的Spliter（原型）
        ISpliter* workSpliter = spliter->clone();    // 克隆原型
        workSpliter->split();                        // 使用克隆对象
        delete workSpliter;                          // 释放克隆对象
        delete spliter;                              // 释放原型对象
    }

    ~mainForm() {
        delete factory; // 删除工厂
    }
};
