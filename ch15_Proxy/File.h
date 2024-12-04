#ifndef FILE_H
#define FILE_H

#include "../common.h"

class File
{
private:
    /* data */
public:
    File(/* args */);
    virtual void read() const=0; // 为了表明这个函数不会修改对象的状态
    ~File();
};

File::File(/* args */)
{
}

File::~File()
{
}


#endif