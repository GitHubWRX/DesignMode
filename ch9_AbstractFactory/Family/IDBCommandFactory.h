#ifndef IDBCommandFactory_h
#define IDBCommandFactory_h
#include "IDBCommand.h"

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