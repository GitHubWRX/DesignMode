#ifndef BUFFEREDFILESTREAM_H // 这个一定要修改否则后续不会被定义，因为引入了FileStream.h
#define BUFFEREDFILESTREAM_H

#include "../../common.h"
#include "FileStream.h"

// 扩展操作1：缓冲文件流
class BufferedFileStream : public FileStream
{
private:
    /* data */
public:
    BufferedFileStream(/* args */);
    virtual char read(int number){
        // 额外的缓冲操作...
        FileStream::read(number);
        // 额外的缓冲操作...
    }
    virtual void Seek(int position){
        // 额外的缓冲操作...
        FileStream::Seek(position);
        // 额外的缓冲操作...
    }
    virtual void Write(char data){
        // 额外的缓冲操作...
        FileStream::Write(data);
        // 额外的缓冲操作...
    }
    ~BufferedFileStream();
};

BufferedFileStream::BufferedFileStream(/* args */)
{
}

BufferedFileStream::~BufferedFileStream()
{
}


#endif