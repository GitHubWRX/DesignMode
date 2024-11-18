#ifndef IDBDATAQUERY_H
#define IDBDATAQUERY_H
#include "../../common.h"
#include "IDBConnection.h"
#include "EmployeeReader.h"

// 这里只需要定义纯虚函数就可以了，不然没有尽头了，总要具体实现
class IDBDataQuery
{
private:
    /* data */
public:
    IDBDataQuery(/* args */);
    virtual IDBDataReader* Query(string str, IDBConnection* IDBCon)=0;
    virtual ~IDBDataQuery();
};

IDBDataQuery::IDBDataQuery(/* args */)
{
}

IDBDataQuery::~IDBDataQuery()
{
}


#endif