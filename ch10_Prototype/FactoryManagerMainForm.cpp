#include "FactoryManager.h"

class mainForm {
private:
    FactoryManager* factoryManager; // 工厂管理器
    SpliterFactory* factory;        // 当前使用的具体工厂

public:
    mainForm(FactoryManager* fm, const std::string& type) : factoryManager(fm) {
        factory = factoryManager->getFactory(type);
        if (!factory) {
            throw std::runtime_error("Invalid factory type!");
        }
    }

    void Button1_Click() {
        ISpliter* spliter = factory->createSpliter(); // 获取具体的Spliter（原型）
        ISpliter* workSpliter = spliter->clone();    // 克隆原型
        workSpliter->split();                        // 使用克隆对象
        delete workSpliter;                          // 释放克隆对象
        delete spliter;                              // 释放原型对象
    }

    ~mainForm() {
        // 注意：factoryManager 的生命周期不由 mainForm 管理
    }
};
