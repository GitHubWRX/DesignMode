#ifndef REALFILE_H
#define REALFILE_H

#include "File.h"

class RealFile : public File
{
private:
    /* data */
    string fileName;
public:
    RealFile(string fn);
    virtual void read() const override;
    ~RealFile();
};

RealFile::RealFile(string fn){
    fileName = fn;
}

inline void RealFile::read() const
{
    cout << "Reading File: " << endl;
}

RealFile::~RealFile()
{
}

#endif