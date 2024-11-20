#ifndef SQLFACTORY_H
#define SQLFACTORY_H

#include "../../common.h"
#include "IDBFactory.h"
#include "IDBCommand.h"
#include "IDBConnection.h"
#include "IDBDataQuery.h"
#include "IDBDataReader.h"


class SqlFactory: public IDBFactory
{
private:
    /* data */
public:
    SqlFactory(/* args */);
    virtual IDBCommand* CreateDBCommand();
    virtual IDBConnection* CreateDBConnection();
    virtual IDBDataQuery* CreateDBDataQuey();
    virtual IDBDataReader* CreateDBDataReader();
    ~SqlFactory();
};

SqlFactory::SqlFactory(/* args */)
{
}

inline IDBCommand *SqlFactory::CreateDBCommand()
{
    return nullptr;
}

inline IDBConnection *SqlFactory::CreateDBConnection()
{
    return nullptr;
}

inline IDBDataQuery *SqlFactory::CreateDBDataQuey()
{
    return nullptr;
}

inline IDBDataReader *SqlFactory::CreateDBDataReader()
{
    return nullptr;
}

SqlFactory::~SqlFactory()
{
}


#endif