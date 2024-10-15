#ifndef POINT_H
#define POINT_H

class Point
{
public:
    /* data */
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    ~Point();
};

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

#endif