#ifndef SqlConnectionFactory_H
#define SqlConnectionFactory_H
#include "../../common.h"
#include "SqlConnection.h"
#include "IDBCommandFactory.h"

class SqlConnectionFactory: public IDBCommandFactory
{
public:
    SqlConnectionFactory(/* args */);
    virtual IDBConnection* CreateDBConnection();
    virtual ~SqlConnectionFactory();
};

SqlConnectionFactory::SqlConnectionFactory(/* args */)
{
}

inline IDBConnection *SqlConnectionFactory::CreateDBConnection()
{
    return nullptr;
}

SqlConnectionFactory::~SqlConnectionFactory()
{
}

#endif