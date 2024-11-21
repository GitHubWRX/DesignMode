#ifndef VedioSpliterFactory_h
#define VedioSpliterFactory_h

#include "VedioSpliter.h"
#include "SpliterFactory.h"

class VedioSpliterFactory : public SpliterFactory {
public:
    ISpliter* createSpliter() override {
        return new VedioSpliter(); // 创建具体的 VedioISpliter
    }
};

#endif
