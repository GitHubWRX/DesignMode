#ifndef SqlDataQueryFactory_h
#define SqlDataQueryFactory_h
#include "SqlDataQuery.h"
#include "IDBDataQueryFactory.h"

class SqlDataQueryFactory: public IDBDataQueryFactory
{
private:
    /* data */
public:
    SqlDataQueryFactory(/* args */);
    virtual IDBDataQuery* CreateDBDataQuey();
    ~SqlDataQueryFactory();
};

SqlDataQueryFactory::SqlDataQueryFactory(/* args */)
{
}

inline IDBDataQuery * SqlDataQueryFactory::CreateDBDataQuey()
{
    return nullptr;
}

SqlDataQueryFactory::~SqlDataQueryFactory()
{
}

#endif