#ifndef SQLCOMMAND_H
#define SQLCOMMAND_H
#include "../../common.h"
#include "SqlConnection.h"
#include "SqlDataReader.h"
#include "SqlDataQuery.h"

class SqlCommand
{
private:
    /* data */
    SqlConnection* sqlConnection;
    string commandText;
    SqlDataQuery* dataQuery;
public:
    SqlCommand(SqlDataQuery* dq);
    void SetConnection(SqlConnection* sqlcon);
    void SetCommandText(string str);
    SqlDataReader* ExecuteReader();
    ~SqlCommand();
};

inline SqlCommand::SqlCommand(SqlDataQuery *dq)
{
    dataQuery = dq;
}

inline void SqlCommand::SetConnection(SqlConnection *sqlcon)
{
    sqlConnection = sqlcon;
}

inline void SqlCommand::SetCommandText(string str)
{
    commandText = str;
}

inline SqlDataReader *SqlCommand::ExecuteReader()
{
    // 通过commandText和sqlConnection获取结果，需要一个外部纯虚接口，获取Reader对象
    SqlDataReader* reader = dataQuery->Query(commandText, sqlConnection);
    return reader;
}

SqlCommand::~SqlCommand()
{
}



#endif