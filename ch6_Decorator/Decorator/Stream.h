#ifndef STREAM_H
#define STREAM_H

#include "../../common.h"
// 我们可能需要各种类型的Stream，NetWorkStream，FileStream等等，都继承
// Decorator 核心思想，像python那样的装饰器，要能够不断套娃，就需要
// 1. 外层和内层有相同的接口（外层和内层均继承相同的基类）
// 2. 外层的接口能够包装内层的接口（外层持有内层指针）

class Stream
{
private:
    /* data */
public:
    Stream(/* args */);
    virtual char read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    
    ~Stream();
};

Stream::Stream(/* args */)
{
}

Stream::~Stream()
{
}



#endif