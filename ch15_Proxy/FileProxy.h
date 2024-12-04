#ifndef FILEPROXY_H
#define FILEPROXY_H

#include "RealFile.h"

class FileProxy : public File
{
private:
    /* data */
    RealFile* realFile;
    bool hasAccess;
public:
    FileProxy(const string filename, bool access):
        realFile(new RealFile(filename)), hasAccess(access){}
    virtual void read() const override;
    ~FileProxy();
};

inline void FileProxy::read() const
{
    if(hasAccess){
        realFile->read(); // 有权限，访问真实对象的方法
    }else{
        cout << "Access denied. You do not have permission to read the file!";
    }
}

FileProxy::~FileProxy()
{
    delete realFile;
}

#endif