#ifndef TextSpliterFactory_h
#define TextSpliterFactory_h

#include "TextSpliter.h"
#include "SpliterFactory.h"

class TextSpliterFactory : public SpliterFactory {
public:
    ISpliter* createSpliter() override {
        return new TextSpliter(); // 创建具体的 TextISpliter
    }
};

#endif
