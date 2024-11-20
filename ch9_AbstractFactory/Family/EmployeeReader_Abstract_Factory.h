#ifndef EMPLOYEEREADER_H
#define EMPLOYEEREADER_H
#include "../../common.h"
#include "Employee.h"
#include "IDBCommand.h"
#include "SqlFactory.h"

class EmployeeReader
{
private:
    /* data */
    vector<Employee> employees;
    SqlFactory* sqlFactory;
public:
    EmployeeReader(SqlFactory *sf);
    vector<Employee> GetEmployee(){

        // 建立连接
        IDBConnection* connection = sqlFactory->CreateDBConnection();
        connection->SetConnectionString("...");

        // 建立命令对象，关联连接，这里的外部接口dataQuery需要在类初始化的时候传入
        IDBCommand* command = sqlFactory->CreateDBCommand();
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

inline EmployeeReader::EmployeeReader(SqlFactory *sf)
{
    sqlFactory = sf;
}

EmployeeReader::~EmployeeReader()
{
}

#endif