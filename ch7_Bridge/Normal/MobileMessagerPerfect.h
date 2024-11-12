#ifndef MOBILEMESSAGERPERFECT_H
#define MOBILEMESSAGERPERFECT_H
#include "MobileMessagerBase.h"

// Perfect实现抽象的其他接口，Login/SendMessage/SendPicture
class MobileMessagerPerfect : MobileMessagerBase
{
private:
    /* data */
public:
    MobileMessagerPerfect(/* args */);
    virtual void Login(string username, string password);
    virtual void SendMessage(string messages);
    virtual void SendPicture(Image image);
    ~MobileMessagerPerfect();
}; 

MobileMessagerPerfect::MobileMessagerPerfect(/* args */)
{

}

inline void MobileMessagerPerfect::Login(string username, string password)
{
    MobileMessagerBase::PlaySound();
    MobileMessagerBase::Connect();
    // ...
}

inline void MobileMessagerPerfect::SendMessage(string messages)
{
    MobileMessagerBase::PlaySound();
    MobileMessagerBase::WriteText();
    // ...
}

inline void MobileMessagerPerfect::SendPicture(Image image)
{
    MobileMessagerBase::PlaySound();
    MobileMessagerBase::DrawShape();
    // ...
}

MobileMessagerPerfect::~MobileMessagerPerfect()
{
}

#endif