#ifndef CONCRETECOLLEAGUEB_H
#define CONCRETECOLLEAGUEB_H

#include "Colleague.h"
#include "Mediator.h"

class ConcreteColleagueB : public Colleague
{
private:
    /* data */
public:
    ConcreteColleagueB(Mediator* mediator) : Colleague(mediator){};
    // override 的作用是告诉编译器该函数是对基类虚函数的重写，
    // 编译器需要在函数声明时就知道这个信息。因为类外的函数定义是分开处理的，
    // 编译器在这时无法确认该函数是否重写了基类的虚函数，除非它已经在类内部声明时使用了 override。
    void SendMessage(const string& message) override;
    void ReceiveMessage(const string& message) override;
    ~ConcreteColleagueB();
};


// receive实际是上调用mediator发送后引发的结果

void ConcreteColleagueB::SendMessage(const string &message)
{
    cout << "ConcreteColleagueB is Sending message" << endl;
    mediator->SendMessage(message, this); // 传入自己，表示是自身发的消息
}

void ConcreteColleagueB::ReceiveMessage(const string &message)
{
    cout << "ConcreteColleagueB is Receiving message: " << message << endl;
}

ConcreteColleagueB::~ConcreteColleagueB()
{
}

#endif