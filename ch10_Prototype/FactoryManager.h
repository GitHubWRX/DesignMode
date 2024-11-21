#ifndef FactoryManager_h
#define FactoryManager_h

#include "../common.h"
#include <unordered_map>
#include "SpliterFactory.h"
#include "BinarySpliterFactory.h"
#include "PictureSpliterFactory.h"
#include "TextSpliterFactory.h"
#include "VedioSpliterFactory.h"

class FactoryManager {
private:
    std::unordered_map<std::string, SpliterFactory*> factoryMap; // 保存工厂映射

public:
    FactoryManager() {
        // 注册工厂
        factoryMap["binary"] = new BinarySpliterFactory();
        factoryMap["picture"] = new PictureSpliterFactory();
        factoryMap["text"] = new TextSpliterFactory();
        factoryMap["vedio"] = new VedioSpliterFactory();
    }

    SpliterFactory* getFactory(const std::string& type) {
        if (factoryMap.find(type) != factoryMap.end()) {
            return factoryMap[type];
        }
        return nullptr; // 未找到对应的工厂
    }

    ~FactoryManager() {
        for (auto& pair : factoryMap) {
            delete pair.second; // 删除所有工厂
        }
    }
};

#endif
