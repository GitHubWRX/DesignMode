#ifndef MESSAGER_H
#define MESSAGER_H

#include "../../common.h"
#include "Image.h"
#include "MessagerImp.h"

class Messager
{
public:
    /* data */
    MessagerImp * m_messagerImp;

public:
    Messager(MessagerImp * messagerImp);

    virtual void Login(string username, string password)=0;
    virtual void SendMessage(string messages)=0;
    virtual void SendPicture(Image image)=0;
    
    ~Messager();
};

Messager::Messager( MessagerImp * messagerImp)
{
    m_messagerImp = messagerImp;
}

Messager::~Messager()
{
    delete m_messagerImp;
}

#endif