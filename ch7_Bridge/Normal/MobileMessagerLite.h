#ifndef MOBILEMESSAGERLITE_H
#define MOBILEMESSAGERLITE_H
#include "MobileMessagerBase.h"

// Lite实现抽象的其他接口，Login/SendMessage/SendPicture，Lite表示轻模式
class MobileMessagerLite : MobileMessagerBase
{
private:
    /* data */
public:
    MobileMessagerLite(/* args */);
    virtual void Login(string username, string password);
    virtual void SendMessage(string messages);
    virtual void SendPicture(Image image);
    ~MobileMessagerLite();
}; 

MobileMessagerLite::MobileMessagerLite(/* args */)
{

}

inline void MobileMessagerLite::Login(string username, string password)
{
    MobileMessagerBase::Connect();
    // ...
}

inline void MobileMessagerLite::SendMessage(string messages)
{
    MobileMessagerBase::WriteText();
    // ...
}

inline void MobileMessagerLite::SendPicture(Image image)
{
    MobileMessagerBase::DrawShape();
    // ...
}

MobileMessagerLite::~MobileMessagerLite()
{
}

#endif