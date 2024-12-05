#ifndef Adapter_H
#define Adapter_H
#include "ITarget.h"
#include "IAdaptee.h"
// Adapter要实现ITarget的功能，需要借助内部Adaptee实现

class Adapter : public ITarget
{
private:
    IAdaptee* m_adaptee;
public:
    Adapter(IAdaptee* adaptee):m_adaptee(adaptee){}
    virtual void process() override;
    ~Adapter();
};

inline void Adapter::process()
{
    m_adaptee->foo(m_adaptee->bar());
}

Adapter::~Adapter()
{
}



#endif