#ifndef CRYPTOSTREAM_H // 这个一定要修改否则后续不会被定义，因为引入了FileStream.h
#define CRYPTOSTREAM_H

#include "../../common.h"
#include "Stream.h"

// 扩展操作1：加密文件流
class CryptoStream : public Stream
{
private:
    /* data */
    Stream * stream; // 可以指向任何流，都进行加密，因为三种流均继承自Stream
public:
    CryptoStream(Stream * stream);
    virtual char read(int number){
        // 额外的加密操作...
        stream->read(number);
        // 额外的加密操作...
    }
    virtual void Seek(int position){
        // 额外的加密操作...
        stream->Seek(position);
        // 额外的加密操作...
    }
    virtual void Write(char data){
        // 额外的加密操作...
        stream->Write(data);
        // 额外的加密操作...
    }
    ~CryptoStream();
};

CryptoStream::CryptoStream(Stream * stream)
{
    stream = stream;
}

CryptoStream::~CryptoStream()
{
}


#endif