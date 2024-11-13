#ifndef IPROGRESS_H
#define IPROGRESS_H

class IProgress
{
private:
    /* data */
public:
    IProgress(/* args */);
    virtual void DoProgress(float value)=0; // 这里为纯虚函数，所以没有后续的函数定义编译器不会报错
    ~IProgress();
};

IProgress::IProgress(/* args */)
{
}

IProgress::~IProgress()
{
}

#endif