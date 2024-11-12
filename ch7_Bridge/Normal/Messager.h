#ifndef MESSAGER_H
#define MESSAGER_H

#include "../../common.h"
#include "Image.h"

class Messager
{
private:
    /* data */
public:
    Messager(/* args */);
    virtual void Login(string username, string password)=0;
    virtual void SendMessage(string messages)=0;
    virtual void SendPicture(Image image)=0;

    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;
    
    ~Messager();
};

Messager::Messager(/* args */)
{
}

Messager::~Messager()
{
}

#endif