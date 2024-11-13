#ifndef MESSAGERIMP_H
#define MESSAGERIMP_H

class MessagerImp
{
private:
    /* data */
public:
    MessagerImp();

    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;

    ~MessagerImp();
};

MessagerImp::MessagerImp()
{
}

MessagerImp::~MessagerImp()
{
}

#endif