#ifndef SQLDATAQUERY_H
#define SQLDATAQUERY_H
#include "../../common.h"
#include "IDBDataQuery.h"

// 这里只需要定义纯虚函数就可以了，不然没有尽头了，总要具体实现
class SqlDataQuery : public IDBDataQuery
{
private:
    /* data */
public:
    SqlDataQuery(/* args */);
    IDBDataReader* Query(string str, IDBConnection* IDBCon) override;
    ~SqlDataQuery();
};

SqlDataQuery::SqlDataQuery(/* args */)
{
}

IDBDataReader* SqlDataQuery::Query(string str, IDBConnection* IDBCon){
    cout << "正在生成一个SqlDataQuery对象" << endl;
    return new IDBDataReader();
}

SqlDataQuery::~SqlDataQuery()
{
}


#endif