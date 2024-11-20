#ifndef SqlCommandFactory_h
#define SqlCommandFactory_h
#include "SqlCommand.h"
#include "SqlDataQuery.h"
#include "IDBCommandFactory.h"

class SqlCommandFactory : public IDBCommandFactory
{
private:
    /* data */
    SqlDataQuery* sqlDataQuery;
public:
    SqlCommandFactory(SqlDataQuery* sq);
    // 遗留问题：返回类型与重写虚拟函数 "IDBCommandFactory::CreateDBCommand" 的返回类型 "<error-type> *" 既不相同，也不协变C/C++(317)
    virtual IDBCommand* CreateDBCommand() override; 
    ~SqlCommandFactory();
};

SqlCommandFactory::SqlCommandFactory(SqlDataQuery* sq):sqlDataQuery(sq)
{
}

IDBCommand* SqlCommandFactory::CreateDBCommand()
{
    return new SqlCommand(sqlDataQuery);
}

SqlCommandFactory::~SqlCommandFactory()
{
    delete sqlDataQuery;
}

#endif