#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include "Mediator.h"

class Colleague
{
protected:
    Mediator* mediator; // 每个Colleague需要知道自己对应的一个mediator，传入抽象
public:
    Colleague(Mediator* mediator) : mediator(mediator) {};

    // Colleague需要能够发送和接受消息
    // send理论上需要调用mediator来发送
    virtual void SendMessage(const string& message)=0;
    // receive实际是上调用mediator发送后引发的结果
    virtual void ReceiveMessage(const string& message)=0;

    ~Colleague();
};

Colleague::~Colleague()
{
}



#endif