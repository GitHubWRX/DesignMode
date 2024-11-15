#ifndef SQLREADER_H
#define SQLREADER_H
#include "../../common.h"
#include "Employee.h"

enum failType{
    Add_Employee_Failed = 1,
    Remove_Employee_Failed,
    Set_Status_Failed,
};

// 该类将由外部接口返回，我们只需要关注该类有哪些属性，如何使用即可
class SqlDataReader
{
private:
    /* data */
    vector<Employee> employees;
    bool read_sataus;
public:
    SqlDataReader(/* args */);
    // 使用SET/GET方法，就防止了vector方法的原生接口暴露或者误操作
    bool GetStatus();
    int SetStatus(bool status);
    vector<Employee> GetEmployees();
    int AddEmployees(Employee employee);
    int RemoveEmployees(Employee employee);
    ~SqlDataReader();
};

SqlDataReader::SqlDataReader(/* args */)
{
}

inline bool SqlDataReader::GetStatus()
{
    return read_sataus;
}

inline int SqlDataReader::SetStatus(bool status)
{
    try{
        read_sataus = status;
        return 0;
    }catch(...){
        read_sataus = false;
        return Set_Status_Failed;
    }
}

inline vector<Employee> SqlDataReader::GetEmployees()
{
    return employees;
}

inline int SqlDataReader::AddEmployees(Employee employee)
{
    // 总是使用try-catch封装，避免异常
    try{
        employees.push_back(employee);
        return 0;
    }catch(...){
        read_sataus = false;
        return Add_Employee_Failed;
    }
}

inline int SqlDataReader::RemoveEmployees(Employee employee)
{
    try{
        // 使用 std::remove 将要移除的元素移到末尾，并返回新末尾的迭代器
        auto new_end = std::remove(employees.begin(), employees.end(), employee);
        // 使用 erase 移除从 new_end 到 vec.end() 的元素
        employees.erase(new_end, employees.end());
        return 0;
    }catch(...){
        return Remove_Employee_Failed;
    }
}

SqlDataReader::~SqlDataReader()
{
}


#endif