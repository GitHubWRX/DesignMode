#ifndef BUFFEREDSTREAM_H // 这个一定要修改否则后续不会被定义，因为引入了FileStream.h
#define BUFFEREDSTREAM_H

#include "../../common.h"
#include "Stream.h"

// 扩展操作1：缓存文件流
class BufferdStream : public Stream
{
private:
    /* data */
    Stream * stream; // 可以指向任何流，都进行缓存，因为三种流均继承自Stream
public:
    BufferdStream(Stream * stream);
    virtual char read(int number){
        // 额外的缓存操作...
        stream->read(number);
        // 额外的缓存操作...
    }
    virtual void Seek(int position){
        // 额外的缓存操作...
        stream->Seek(position);
        // 额外的缓存操作...
    }
    virtual void Write(char data){
        // 额外的缓存操作...
        stream->Write(data);
        // 额外的缓存操作...
    }
    ~BufferdStream();
};

BufferdStream::BufferdStream(Stream * stream)
{
    stream = stream;
}

BufferdStream::~BufferdStream()
{
}


#endif