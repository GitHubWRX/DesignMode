#ifndef SqlDataReaderFactory_h
#define SqlDataReaderFactory_h
#include "SqlDataReader.h"
#include "IDBDataReaderFactory.h"

class SqlDataReaderFactory: public IDBDataReaderFactory
{
private:
    /* data */
public:
    SqlDataReaderFactory(/* args */);
    virtual IDBDataReader* CreateDBDataQuey();
    ~SqlDataReaderFactory();
};

SqlDataReaderFactory::SqlDataReaderFactory(/* args */)
{
}

inline IDBDataReader *SqlDataReaderFactory::CreateDBDataQuey()
{
    return nullptr;
}

SqlDataReaderFactory::~SqlDataReaderFactory()
{
}

#endif