#ifndef EMPLOYEEREADER_H
#define EMPLOYEEREADER_H
#include "../../common.h"
#include "SqlConnection.h"
#include "SqlCommand.h"
#include "Employee.h"
#include "SqlDataQuery.h"

class EmployeeReader
{
private:
    /* data */
    vector<Employee> employees;
    SqlDataQuery* dataQuery;

public:
    EmployeeReader(SqlDataQuery *dq);
    vector<Employee> GetEmployee(){

        // 建立连接
        SqlConnection* connection = new SqlConnection();
        connection->SetConnectionString("...");


        // 建立命令对象，关联连接，这里的外部接口dataQuery需要在类初始化的时候传入
        SqlCommand* command = new SqlCommand(dataQuery);
        command->SetConnection(connection);
        command->SetCommandText("...");

        // 执行查询并获取结果对象
        SqlDataReader* reader = command->ExecuteReader();
        while(reader->GetStatus()){
            for(auto employee : reader->GetEmployees()){
                employees.push_back(employee);
            }
        }
        return employees;
    }
    ~EmployeeReader();
};

inline EmployeeReader::EmployeeReader(SqlDataQuery *dq)
{
    dataQuery = dq;
}

EmployeeReader::~EmployeeReader()
{
}

#endif