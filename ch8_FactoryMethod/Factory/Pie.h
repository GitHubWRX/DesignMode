#ifndef PIE_H
#define PIE_H

#include "../../common.h"
class Pie
{
private:
    /* data */
    float value;
public:
    Pie(/* args */);
    int setDegree(float value);
    float getDegree(); // 自然有其他组件会使用该方法，进行进度饼图的绘制，比如前端组件
    ~Pie();
};

Pie::Pie(/* args */):value(0){
}

inline int Pie::setDegree(float value)
{
    value = value;
    return 0;
}

inline float Pie::getDegree()
{
    return value;
}

Pie::~Pie()
{
}

#endif