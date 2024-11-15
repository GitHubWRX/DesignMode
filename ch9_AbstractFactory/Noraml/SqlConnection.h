#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include "../../common.h"

class SqlConnection
{
private:
    /* data */
    string connectionString;
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
    connectionString = str;
}

SqlConnection::~SqlConnection()
{
}


#endif