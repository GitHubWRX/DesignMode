#ifndef FileSpliter_H
#define FileSpliter_H
#include "../../common.h"
#include "ProgressBar.h"
#include "Pie.h"

class FileSpliter
{
private:
    /* data */
    string m_filePath;
    int m_number;
    ProgressBar* m_progressbar;
    Pie* m_pie;

public:
    FileSpliter(string filePath, int nubmer, ProgressBar* progressbar, Pie* pie); // 修改，增加参数
    void split(){};
    ~FileSpliter();
};

FileSpliter::FileSpliter(string filePath, int number, ProgressBar* progressbar, Pie* pie)

{   
    m_filePath = filePath;
    m_number = number;
    m_progressbar = progressbar; // 修改：持有进度条
    m_pie = pie; // 修改：持有进度饼图
}

void FileSpliter::split(){
    cout << "I am Splitting the" << m_filePath << "to" << m_number << "Part" << endl;
    for (int i = 0; i <= m_number; i++){
        cout << i << "/" << m_number << "..." << endl;
        if (m_progressbar != nullptr){
            m_progressbar -> setValue((i+1) / m_number); // 修改，使用进度条的具体方法进行更新
        }

        if (m_pie != nullptr){
            m_pie -> setDegree((i+1) / m_number * 360); // 修改，使用饼状图的具体方法进行更新
        }

    }
}

FileSpliter::~FileSpliter()
{
}


#endif