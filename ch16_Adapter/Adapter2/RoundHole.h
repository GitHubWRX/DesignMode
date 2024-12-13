#ifndef ROUNDHOLE_H
#define ROUNDHOLE_H
#include "RoundPeg.h"

class RoundHole
{
private:
    /* data */
    double radius; // 圆孔半径
public:
    RoundHole(double r):radius(r){}
    // 【这里很重要，必须使用RoundPeg的指针或者引用，否则不会产生多态行为！！！】
    bool fits(const RoundPeg& peg) const{
        double r = peg.getRadius();
        printf("roundPeg has radius %f\n", r);
        return r <= radius;
    }
    ~RoundHole();
};

RoundHole::~RoundHole()
{
}


#endif