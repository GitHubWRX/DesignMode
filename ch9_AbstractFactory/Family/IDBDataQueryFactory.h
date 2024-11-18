#ifndef IDBDataQueryFactory_h
#define IDBDataQueryFactory_h
#include "IDBDataQuery.h"

class IDBDataQueryFactory
{
public:
    IDBDataQueryFactory(/* args */);
    virtual IDBDataQuery* CreateDBDataQuey()=0;
    ~IDBDataQueryFactory();
};

IDBDataQueryFactory::IDBDataQueryFactory(/* args */)
{
}

IDBDataQueryFactory::~IDBDataQueryFactory()
{
}

#endif