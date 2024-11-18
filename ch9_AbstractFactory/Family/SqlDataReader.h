#ifndef SQLREADER_H
#define SQLREADER_H
#include "../../common.h"
#include "Employee.h"
#include "IDBDataReader.h"

// 该类将由外部接口返回，我们只需要关注该类有哪些属性，如何使用即可
class SqlDataReader : IDBDataReader
{
    SqlDataReader(/* args */);
    ~SqlDataReader();
};

#endif