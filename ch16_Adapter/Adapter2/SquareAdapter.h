#ifndef SQUAREADAPTER_H
#define SQUAREADAPTER_H
#include "RoundPeg.h"
#include "SquarePeg.h"
#include "cmath"

// 用于包装SquarePeg称为RoundPeg，所以必须继承，因为RoundHoled.fits只接受该类型
class SquareAdapter : public RoundPeg
{
private:
    /* data */
    const SquarePeg& squarePeg; // 传递引用会更高效
public:
    SquareAdapter(const SquarePeg& sp):RoundPeg(8),squarePeg(sp){} // 这里可以省略const，非const可以转为const是可以的
    double getRadius() const override{ // 不能遗漏const，因为override需要与基类行为一致
        cout << "the SquareAdapter init RoundPeg's Radius is useless\n";
        return squarePeg.getWidth() * std::sqrt(2) / 2;
    }
    ~SquareAdapter();
};

SquareAdapter::~SquareAdapter()
{
}

#endif