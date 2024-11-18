#ifndef SQLCOMMAND_H
#define SQLCOMMAND_H
#include "../../common.h"
#include "IDBCommand.h"

class SqlCommand : public IDBCommand{
public:
    SqlCommand::SqlCommand(IDBDataQuery *dq):IDBCommand(dq)
    {
        // dataQuery = dq; 直接赋值为父类的是不可行的
        // 在初始化列表中进行
    }

    SqlCommand::~SqlCommand()
    {
    }

};


#endif