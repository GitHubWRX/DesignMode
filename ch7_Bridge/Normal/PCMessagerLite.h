#ifndef PCMESSAGERLITE_H
#define PCMESSAGERLITE_H
#include "PCMessagerBase.h"

// Lite实现抽象的其他接口，Login/SendMessage/SendPicture，Lite表示轻模式
class PCMessagerLite : PCMessagerBase
{
private:
    /* data */
public:
    PCMessagerLite(/* args */);
    virtual void Login(string username, string password);
    virtual void SendMessage(string messages);
    virtual void SendPicture(Image image);
    ~PCMessagerLite();
}; 

PCMessagerLite::PCMessagerLite(/* args */)
{

}

inline void PCMessagerLite::Login(string username, string password)
{
    PCMessagerBase::Connect();
    // ...
}

inline void PCMessagerLite::SendMessage(string messages)
{
    PCMessagerBase::WriteText();
    // ...
}

inline void PCMessagerLite::SendPicture(Image image)
{
    PCMessagerBase::DrawShape();
    // ...
}

PCMessagerLite::~PCMessagerLite()
{
}

#endif