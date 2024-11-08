#ifndef FILESTREAM_H
#define FILESTREAM_H

#include "Stream.h"

class FileStream : public Stream
{
private:
    /* data */
public:
    FileStream(/* args */);
    virtual char read(int number){
        cout << "I am reading File:" << number << endl;
    }
    virtual void Seek(int position){
        cout << "I am seeking File:" << position << endl;
    }
    virtual void Write(char data){
        cout << "I am writing File:" << data << endl;
    }
    ~FileStream();
};

FileStream::FileStream(/* args */)
{
}

FileStream::~FileStream()
{
}


#endif