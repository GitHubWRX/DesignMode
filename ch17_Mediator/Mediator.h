#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "../common.h"

class Colleague;

class Mediator
{
private:
    /* data */
public:
    Mediator(/* args */);
    // 抽象的中介者至少需要知道：【消息内容】、【消息接收者】，但不需要知道如何具体管理Colleague
    virtual void SendMessage(const string& message, Colleague* colleague)=0;
    ~Mediator();
};

Mediator::Mediator(/* args */)
{
}

Mediator::~Mediator()
{
}



#endif