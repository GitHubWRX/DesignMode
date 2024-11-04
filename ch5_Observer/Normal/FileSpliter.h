#ifndef FileSpliter_H
#define FileSpliter_H
#include "../../common.h"
#include "ProgressBar.h"

class FileSpliter
{
private:
    /* data */
    string m_filePath;
    int m_number;
    ProgressBar* m_progressbar;

public:
    FileSpliter(string filePath, int nubmer, ProgressBar* progressbar);
    void split(){};
    ~FileSpliter();
};

FileSpliter::FileSpliter(string filePath, int number, ProgressBar* progressbar)

{   
    m_filePath = filePath;
    m_number = number;
    m_progressbar = progressbar; // 修改：持有进度条
}

void FileSpliter::split(){
    cout << "I am Splitting the" << m_filePath << "to" << m_number << "Part" << endl;
    for (int i = 0; i <= m_number; i++){
        cout << i << "/" << m_number << "..." << endl;
        if (m_progressbar != nullptr){
            m_progressbar -> setValue((i+1) / m_number); // 修改，使用进度条的具体方法进行更新
        }
    }
}

FileSpliter::~FileSpliter()
{
}


#endif