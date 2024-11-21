#ifndef PictureSpliterFactory_h
#define PictureSpliterFactory_h

#include "PictureSpliter.h"
#include "SpliterFactory.h"

class PictureSpliterFactory : public SpliterFactory {
public:
    ISpliter* createSpliter() override {
        return new PictureSpliter(); // 创建具体的 PictureSpliter
    }
};

#endif
