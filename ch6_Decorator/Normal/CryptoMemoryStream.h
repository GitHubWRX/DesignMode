#ifndef CRYPTOMEMORYSTREAM_H // 这个一定要修改否则后续不会被定义，因为引入了FileStream.h
#define CRYPTOMEMORYSTREAM_H

#include "../../common.h"
#include "FileStream.h"

// 扩展操作1：加密文件流
class CryptoMemoryStream : public FileStream
{
private:
    /* data */
public:
    CryptoMemoryStream(/* args */);
    virtual char read(int number){
        // 额外的加密操作...
        FileStream::read(number);
        // 额外的加密操作...
    }
    virtual void Seek(int position){
        // 额外的加密操作...
        FileStream::Seek(position);
        // 额外的加密操作...
    }
    virtual void Write(char data){
        // 额外的加密操作...
        FileStream::Write(data);
        // 额外的加密操作...
    }
    ~CryptoMemoryStream();
};

CryptoMemoryStream::CryptoMemoryStream(/* args */)
{
}

CryptoMemoryStream::~CryptoMemoryStream()
{
}


#endif