#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle: public Shape
{
public:
    /* data */
    Point origin;
    int radius;
public:
    Circle(const Point& origin, const int& radius);
    virtual void Draw(const Graphics& g);
    ~Circle();
};

Circle::Circle(const Point& origin, const int& radius)
{
    this->origin = origin;
    this->radius = radius;
}

void Circle::Draw(const Graphics& g){
    g.DrawCircle(
        Pens.Blue,
        origin,
        radius
    );
}

Circle::~Circle()
{
}

#endif