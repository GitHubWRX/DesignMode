#ifndef PCMESSAGERPERFECT_H
#define PCMESSAGERPERFECT_H
#include "PCMessagerBase.h"

// Perfect实现抽象的其他接口，Login/SendMessage/SendPicture
class PCMessagerPerfect : PCMessagerBase
{
private:
    /* data */
public:
    PCMessagerPerfect(/* args */);
    virtual void Login(string username, string password);
    virtual void SendMessage(string messages);
    virtual void SendPicture(Image image);
    ~PCMessagerPerfect();
}; 

PCMessagerPerfect::PCMessagerPerfect(/* args */)
{

}

inline void PCMessagerPerfect::Login(string username, string password)
{
    PCMessagerBase::PlaySound();
    PCMessagerBase::Connect();
    // ...
}

inline void PCMessagerPerfect::SendMessage(string messages)
{
    PCMessagerBase::PlaySound();
    PCMessagerBase::WriteText();
    // ...
}

inline void PCMessagerPerfect::SendPicture(Image image)
{
    PCMessagerBase::PlaySound();
    PCMessagerBase::DrawShape();
    // ...
}

PCMessagerPerfect::~PCMessagerPerfect()
{
}

#endif