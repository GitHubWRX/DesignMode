#ifndef STREAM_H
#define STREAM_H

#include "../../common.h"
// 我们可能需要各种类型的Stream，NetWorkStream，FileStream等等，都继承

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