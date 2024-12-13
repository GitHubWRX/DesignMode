#ifndef SQUAREPEG_H
#define SQUAREPEG_H

#include "../../common.h"

class SquarePeg
{
private:
    /* data */
    double width;
public:
    SquarePeg(double w):width(w){}
    // 如果将SquarePeg放入RoundHole，不知道是否可以成功，因为衡量口径不一样
    // 所以需要有一个适配器，能够使用getRadius方法，将width转化为radius
    double getWidth()const { return width; }
    ~SquarePeg();
};

SquarePeg::~SquarePeg()
{
}

#endif