#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "../../common.h"
class ProgressBar
{
private:
    /* data */
    float value;
public:
    ProgressBar(/* args */);
    int setValue(float value);
    float getValue(); // 自然有其他组件会使用该方法，进行进度条的绘制，比如前端组件
    ~ProgressBar();
};

ProgressBar::ProgressBar(/* args */):value(0){
}

inline int ProgressBar::setValue(float value)
{
    value = value;
    return 0;
}

inline float ProgressBar::getValue()
{
    return value;
}

ProgressBar::~ProgressBar()
{
}

#endif