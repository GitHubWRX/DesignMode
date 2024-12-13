#include "SquareAdapter.h"
#include "RoundHole.h"

int main(){
    // 固定圆孔半径
    double hole_r = 8;
    RoundHole rh(hole_r);

    // 首先尝试圆形钉子->圆孔
    double round_r = 9;
    RoundPeg rp(round_r);
    bool res_r = rh.fits(rp);
    printf("puts RoundPeg with radius %f into RoundHole with radius %f: %s \n", round_r, hole_r, res_r ? "ok" : "too big");

    // 其次尝试方形钉子->圆孔
    double square_w = 9;
    SquarePeg sp(square_w);
    SquareAdapter sa(sp);
    bool res_s = rh.fits(sa);
    printf("puts SquarePeg with width %f into RoundHole with radius %f: %s \n", square_w, hole_r, res_s ? "ok" : "too big");
}