#ifndef NETWORKSTREAM_H
#define NETWORKSTREAM_H

#include "Stream.h"

class NetworkStream : public Stream
{
private:
    /* data */
public:
    NetworkStream(/* args */);
    virtual char read(int number){
        cout << "I am reading Network:" << number << endl;
    }
    virtual void Seek(int position){
        cout << "I am seeking Network:" << position << endl;
    }
    virtual void Write(char data){
        cout << "I am writing Network:" << data << endl;
    }
    ~NetworkStream();
};

NetworkStream::NetworkStream(/* args */)
{
}

NetworkStream::~NetworkStream()
{
}


#endif