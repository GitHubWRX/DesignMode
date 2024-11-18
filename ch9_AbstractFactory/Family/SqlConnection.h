#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include "../../common.h"
#include "IDBConnection.h"

class SqlConnection : public IDBConnection
{
public:
    SqlConnection(/* args */);
    void SetConnectionString(string str);
    ~SqlConnection();
};

SqlConnection::SqlConnection(/* args */)
{
}

void SqlConnection::SetConnectionString(string str)
{
    // connectionString = str; 此处一样要使用父类的初始化函数
    IDBConnection::SetConnectionString(str);
}

SqlConnection::~SqlConnection()
{
}


#endif