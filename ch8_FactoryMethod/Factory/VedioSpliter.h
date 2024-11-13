#ifndef VEDIOSPLITER_H
#define VEDIOSPLITER_H
#include "../../common.h"
#include "IProgress.h"
#include "ISpliter.h"

class VedioSpliter : public ISpliter
{
private:
    /* data */
    string m_filePath;
    int m_number;
    // 如果只是传递观察者的抽象基类，可能会遇到其基类不存在setValue方法（不同观察者方法名称不同）
    vector<IProgress*> m_iprogress; // 抽象通知机制，声明一个接口类，一定要实现DoProgress方法

public:
    VedioSpliter(string filePath, int nubmer);
    int add_IProgress(IProgress* iprogress);
    int remove_IProgress(IProgress* iprogress);

    virtual void split() override;
    ~VedioSpliter();

protected:
    void onProgress(float value);
};

VedioSpliter::VedioSpliter(string filePath, int number)

{   
    m_filePath = filePath;
    m_number = number;
}

inline int VedioSpliter::add_IProgress(IProgress *iprogress)
{
    m_iprogress.push_back(iprogress);
    return 0;
}

inline int VedioSpliter::remove_IProgress(IProgress *iprogress)
{
    m_iprogress.erase(std::remove(m_iprogress.begin(), m_iprogress.end(), iprogress), m_iprogress.end());  
    return 0;
}

inline void VedioSpliter::onProgress(float value)
{
    for (vector<IProgress*>::iterator itor = m_iprogress.begin(); itor < m_iprogress.end(); itor++){
        if (*itor != nullptr){
            (*itor) -> DoProgress(value); // 这个是虚方法，但是编译器不会报错
        }
    }
}

void VedioSpliter::split(){
    cout << "I am Splitting the" << m_filePath << "to" << m_number << "Part" << endl;
    for (int i = 0; i <= m_number; i++){
        cout << i << "/" << m_number << "..." << endl;
        float progressValue = m_number;
        progressValue = (i+1) / m_number;
        onProgress(progressValue);
    }
}

VedioSpliter::~VedioSpliter()
{
}


#endif