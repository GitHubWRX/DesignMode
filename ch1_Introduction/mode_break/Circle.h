#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle
{
public:
    /* data */
    Point origin;
    int radius;
public:
    Circle(const Point& origin, const int& radius);
    ~Circle();
};

Circle::Circle(const Point& origin, const int& radius)
{
    this->origin = origin;
    this->radius = radius;
}

Circle::~Circle()
{
}

#endif