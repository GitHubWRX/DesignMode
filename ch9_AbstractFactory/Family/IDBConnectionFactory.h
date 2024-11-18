#ifndef IDBConnectionFactory_H
#define IDBConnectionFactory_H
#include "../../common.h"
#include "IDBConnection.h"

class IDBConnectionFactory
{
public:
    IDBConnectionFactory(/* args */);
    virtual IDBConnection* CreateDBConnection()=0;
    virtual ~IDBConnectionFactory();
};

IDBConnectionFactory::IDBConnectionFactory(/* args */)
{
}

IDBConnectionFactory::~IDBConnectionFactory()
{
}

#endif