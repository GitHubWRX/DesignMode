#ifndef IADAPTEE_H
#define IADAPTEE_H

class IAdaptee
{
private:
    /* data */
public:
    IAdaptee(/* args */);
    virtual void foo(int data)=0;
    virtual int bar()=0;
    ~IAdaptee();
};

IAdaptee::IAdaptee(/* args */)
{
}

IAdaptee::~IAdaptee()
{
}



#endif