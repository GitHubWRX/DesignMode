#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Colleague.h"

class ConcreteMediator : public Mediator
{
private:
    // 中介者需要知道每个colleague，在这里定义组织方式
    vector<Colleague*> colleagues;
public:
    // 默认构造函数需要存在（不定义也会生成默认的）
    // 这样才可以构造一个空的colleagues列表，初始化传入ConcreteColleague
    ConcreteMediator(/* args */);

    void addColleague(Colleague* colleague){
        colleagues.push_back(colleague);
    }

    void SendMessage(const string& message, Colleague* colleague) override;

    ~ConcreteMediator();
};

ConcreteMediator::ConcreteMediator(/* args */)
{
}

void ConcreteMediator::SendMessage(const string &message, Colleague *colleague)
{
    // 此处复习使用迭代器而非auto进行处理，迭代器实际上是指针，所以要解引用
    for(vector<Colleague*>::iterator it = colleagues.begin(); it != colleagues.end(); ++it){
        if(*it != colleague ){
            (*it)->ReceiveMessage(message);
        }
    }
}

ConcreteMediator::~ConcreteMediator()
{
}



#endif