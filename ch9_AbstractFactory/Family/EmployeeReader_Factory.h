#ifndef EMPLOYEEREADER_H
#define EMPLOYEEREADER_H
#include "../../common.h"
#include "Employee.h"
#include "IDBCommand.h"
#include "IDBConnectionFactory.h"
#include "IDBCommandFactory.h"
#include "IDBDataQueryFactory.h"
#include "IDBDataReaderFactory.h"

class EmployeeReader
{
private:
    /* data */
    vector<Employee> employees;
    IDBDataQuery* dataQuery;
    IDBConnectionFactory* connectionFactory;
    IDBCommandFactory* commandFactory;
    IDBDataQueryFactory* dataQueryFactory;
    IDBDataReaderFactory* dataReaderFactory;


public:
    EmployeeReader(IDBDataQuery *dq);
    vector<Employee> GetEmployee(){

        // 建立连接
        IDBConnection* connection = connectionFactory->CreateDBConnection();
        connection->SetConnectionString("...");

        // 建立命令对象，关联连接，这里的外部接口dataQuery需要在类初始化的时候传入
        IDBCommand* command = commandFactory->CreateDBCommand();
        command->SetConnection(connection);
        command->SetCommandText("...");

        // 执行查询并获取结果对象
        IDBDataReader* reader = command->ExecuteReader();
        while(reader->GetStatus()){
            for(auto employee : reader->GetEmployees()){
                employees.push_back(employee);
            }
        }
        return employees;
    }
    ~EmployeeReader();
};

inline EmployeeReader::EmployeeReader(IDBDataQuery *dq)
{
    dataQuery = dq;
}

EmployeeReader::~EmployeeReader()
{
}

#endif