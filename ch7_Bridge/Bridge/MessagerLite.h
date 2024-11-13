#ifndef MESSAGERLITE_H
#define MESSAGERLITE_H
#include "Messager.h"

// Lite实现抽象的其他接口，Login/SendMessage/SendPicture，Lite表示轻模式
class MessagerLite : public Messager
{
private:
    /* data */
public:
    MessagerLite(MessagerImp* messagerImp);
    virtual void Login(string username, string password) override;
    virtual void SendMessage(string messages) override;
    virtual void SendPicture(Image image) override;
    ~MessagerLite();
}; 

MessagerLite::MessagerLite(MessagerImp* messagerImp):Messager(messagerImp)
{
    // 基类初始化，在初始化列表中完成
}

inline void MessagerLite::Login(string username, string password)
{
    m_messagerImp->Connect();
    // ...
}

inline void MessagerLite::SendMessage(string messages)
{
    m_messagerImp->WriteText();
    // ...
}

inline void MessagerLite::SendPicture(Image image)
{
    m_messagerImp->DrawShape();
    // ...
}

MessagerLite::~MessagerLite()
{
    // 基类自己有析构函数
}

#endif