#ifndef ROUNDPEG_H
#define ROUNDPEG_H
#include "../../common.h"

class RoundPeg
{
private:
    /* data */
    double radius; // 半径，对于适配器需要开根号，浮点数是合适的
public:
    RoundPeg(double r=0):radius(r){}; // 这样算有默认的构造器，否则继承会报错
    virtual double getRadius() const; // 其他类型的适配器，想要继承该方法，virtual是合适的
    ~RoundPeg();
};

double RoundPeg::getRadius() const // 这里依然需要增加const说明
{
    return radius;
}

RoundPeg::~RoundPeg()
{
}

#endif