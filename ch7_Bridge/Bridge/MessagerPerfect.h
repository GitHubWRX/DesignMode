#ifndef MESSAGERPERFECT_H
#define MESSAGERPERFECT_H
#include "Messager.h"

// Lite实现抽象的其他接口，Login/SendMessage/SendPicture，Lite表示轻模式
class MessagerPerfect : public Messager
{
private:
    /* data */
public:
    MessagerPerfect(MessagerImp* messagerImp);
    virtual void Login(string username, string password) override;
    virtual void SendMessage(string messages) override;
    virtual void SendPicture(Image image) override;
    ~MessagerPerfect();
}; 

MessagerPerfect::MessagerPerfect(MessagerImp* messagerImp):Messager(messagerImp)
{
    // 基类初始化，在初始化列表中完成
}

inline void MessagerPerfect::Login(string username, string password)
{
    m_messagerImp->PlaySound();
    m_messagerImp->Connect();
    // ...
}

inline void MessagerPerfect::SendMessage(string messages)
{
    m_messagerImp->PlaySound();
    m_messagerImp->WriteText();
    // ...
}

inline void MessagerPerfect::SendPicture(Image image)
{
    m_messagerImp->PlaySound();
    m_messagerImp->DrawShape();
    // ...
}

MessagerPerfect::~MessagerPerfect()
{
    // 基类自己有析构函数
}

#endif