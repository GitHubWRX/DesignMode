#ifndef IDBDataReaderFactory_h
#define IDBDataReaderFactory_h
#include "IDBDataReader.h"

class IDBDataReaderFactory
{
public:
    IDBDataReaderFactory(/* args */);
    virtual IDBDataReader* CreateDBDataReader()=0;
    ~IDBDataReaderFactory();
};

IDBDataReaderFactory::IDBDataReaderFactory(/* args */)
{
}

IDBDataReaderFactory::~IDBDataReaderFactory()
{
}

#endif