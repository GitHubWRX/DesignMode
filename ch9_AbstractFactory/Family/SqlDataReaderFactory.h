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
    virtual IDBDataReader* CreateDBDataReader();
    ~SqlDataReaderFactory();
};

SqlDataReaderFactory::SqlDataReaderFactory(/* args */)
{
}

inline IDBDataReader *SqlDataReaderFactory::CreateDBDataReader()
{
    return nullptr;
}

SqlDataReaderFactory::~SqlDataReaderFactory()
{
}

#endif