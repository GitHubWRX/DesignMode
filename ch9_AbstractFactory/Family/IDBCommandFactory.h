#ifndef IDBCommandFactory_h
#define IDBCommandFactory_h
#include "IDBCommand.h"

class IDBCommand; // 这个前置声明如果不写，就会导致SqlCommandFactory.h中的CreateDBCommand出错

class IDBCommandFactory
{
public:
    IDBCommandFactory(/* args */);
    virtual IDBCommand* CreateDBCommand()=0;
    ~IDBCommandFactory();
};

IDBCommandFactory::IDBCommandFactory(/* args */)
{
}

IDBCommandFactory::~IDBCommandFactory()
{
}

#endif