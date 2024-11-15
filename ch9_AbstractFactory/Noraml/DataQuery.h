#ifndef DATAQUERY_H
#define DATAQUERY_H
#include "../../common.h"
#include "SqlConnection.h"
#include "EmployeeReader.h"

// 这里只需要定义纯虚函数就可以了，不然没有尽头了，总要具体实现
class DataQuery
{
private:
    /* data */
public:
    DataQuery(/* args */);
    virtual SqlDataReader* Query(string str, SqlConnection* sqlCon)=0;
    ~DataQuery();
};

DataQuery::DataQuery(/* args */)
{
}

DataQuery::~DataQuery()
{
}


#endif