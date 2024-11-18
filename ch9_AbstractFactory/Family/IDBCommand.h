#ifndef IDBCOMMAND_H
#define IDBCOMMAND_H
#include "../../common.h"
#include "IDBConnection.h"
#include "IDBDataReader.h"
#include "IDBDataQuery.h"

class IDBCommand
{
private:
    /* data */
    IDBConnection* idbConnection;
    string commandText;
    IDBDataQuery* dataQuery;
public:
    IDBCommand(IDBDataQuery* dq);
    virtual void SetConnection(IDBConnection* IDBcon);
    virtual void SetCommandText(string str);
    IDBDataReader* ExecuteReader();
    virtual ~IDBCommand();
};

inline IDBCommand::IDBCommand(IDBDataQuery *dq)
{
    dataQuery = dq;
}

inline void IDBCommand::SetConnection(IDBConnection *IDBcon)
{
    idbConnection = IDBcon;
}

inline void IDBCommand::SetCommandText(string str)
{
    commandText = str;
}

inline IDBDataReader *IDBCommand::ExecuteReader()
{
    // 通过commandText和IDBConnection获取结果，需要一个外部纯虚接口，获取Reader对象
    IDBDataReader* reader = dataQuery->Query(commandText, idbConnection);
    return reader;
}

IDBCommand::~IDBCommand()
{
    delete idbConnection;
    delete dataQuery;
}

#endif