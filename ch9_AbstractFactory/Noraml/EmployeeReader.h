#ifndef EMPLOYEEREADER_H
#define EMPLOYEEREADER_H
#include "../../common.h"

class EmployeeReader
{
private:
    /* data */
    vector<Employee> employees;
public:
    EmployeeReader(/* args */);
    vector<Employee> GetEmployee(){
        SqlConnection* connection = new SqlConnection();
        connection->ConnectionString = "...";
        
        SqlCommand* command = new SqlCommand();
        command->CommandText = "..."
        command->SetConnection(connection);

        SqlDataReader* reader = command->ExecuteReader();
        while(reader->Read()){
            employees.push_back(reader.Result());
        }
    }
    ~EmployeeReader();
};

EmployeeReader::EmployeeReader(/* args */)
{
}

EmployeeReader::~EmployeeReader()
{
}


#endif