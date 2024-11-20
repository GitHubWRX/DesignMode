#ifndef IDBFACTORY_H
#define IDBFACTORY_H

#include "../../common.h"
#include "IDBCommand.h"
#include "IDBConnection.h"
#include "IDBDataQuery.h"
#include "IDBDataReader.h"


class IDBFactory
{
private:
    /* data */
public:
    IDBFactory(/* args */);
    virtual IDBCommand* CreateDBCommand()=0;
    virtual IDBConnection* CreateDBConnection()=0;
    virtual IDBDataQuery* CreateDBDataQuey()=0;
    virtual IDBDataReader* CreateDBDataReader()=0;
    ~IDBFactory();
};

IDBFactory::IDBFactory(/* args */)
{
}

IDBFactory::~IDBFactory()
{
}


#endif