#ifndef IDBCONNECTION_H
#define IDBCONNECTION_H
#include "../../common.h"

class IDBConnection
{
private:
    /* data */
    string connectionString;
public:
    IDBConnection(/* args */);
    virtual void SetConnectionString(string str)=0;
    virtual ~IDBConnection();
};

IDBConnection::IDBConnection(/* args */)
{
}

IDBConnection::~IDBConnection()
{
}

#endif