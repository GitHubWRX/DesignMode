#ifndef FileSpliter_H
#define FileSpliter_H
#include "../../common.h"
#include "IProgress.h"

class FileSpliter
{
private:
    /* data */
    string m_filePath;
    int m_number;
    // 如果只是传递观察者的抽象基类，可能会遇到其基类不存在setValue方法（不同观察者方法名称不同）
    IProgress* m_iprogress; // 抽象通知机制，声明一个接口类，一定要实现DoProgress方法

public:
    FileSpliter(string filePath, int nubmer, IProgress* iprogress);
    void split(){};
    ~FileSpliter();
};

FileSpliter::FileSpliter(string filePath, int number, IProgress* iprogress)

{   
    m_filePath = filePath;
    m_number = number;
    m_iprogress = iprogress;
}

void FileSpliter::split(){
    cout << "I am Splitting the" << m_filePath << "to" << m_number << "Part" << endl;
    for (int i = 0; i <= m_number; i++){
        cout << i << "/" << m_number << "..." << endl;
        if (m_iprogress != nullptr){
            m_iprogress -> DoProgress((i+1) / m_number); // 这个是虚方法，但是编译器不会报错
        }
    }
}

FileSpliter::~FileSpliter()
{
}


#endif