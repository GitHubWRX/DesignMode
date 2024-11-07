#ifndef CRYPTOBUFFEREDNETWORKSTREAM_H // 这个一定要修改否则后续不会被定义，因为引入了FileStream.h
#define CRYPTOBUFFEREDNETWORKSTREAM_H

#include "../../common.h"
#include "FileStream.h"

// 扩展操作1：加密文件流
class CryptoBufferedNetworkStream : public FileStream
{
private:
    /* data */
public:
    CryptoBufferedNetworkStream(/* args */);
    virtual char read(int number){
        // 额外的加密操作...
        // 额外的缓冲操作...
        FileStream::read(number);
        // 额外的缓冲操作...
        // 额外的加密操作...
    }
    virtual void Seek(int position){
        // 额外的加密操作...
        // 额外的缓冲操作...
        FileStream::Seek(position);
        // 额外的缓冲操作...
        // 额外的加密操作...
    }
    virtual void Write(char data){
        // 额外的加密操作...
        // 额外的缓冲操作...
        FileStream::Write(data);
        // 额外的缓冲操作...
        // 额外的加密操作...
    }
    ~CryptoBufferedNetworkStream();
};

CryptoBufferedNetworkStream::CryptoBufferedNetworkStream(/* args */)
{
}

CryptoBufferedNetworkStream::~CryptoBufferedNetworkStream()
{
}


#endif