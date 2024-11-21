#ifndef BinarySpliterFactory_h
#define BinarySpliterFactory_h

#include "BinarySpliter.h"
#include "SpliterFactory.h"

class BinarySpliterFactory : public SpliterFactory {
public:
    ISpliter* createSpliter() override {
        return new BinarySpliter(); // 创建具体的 BinaryISpliter
    }
};

#endif
