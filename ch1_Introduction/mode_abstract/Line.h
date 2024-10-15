#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "Shape.h"

class Line: public Shape{
public:
    /* data */
    Point start; 
    Point end;
public:
    Line(const Point& start, const Point& end);
    // 实现自己的Draw
    virtual void Draw(const Graphics& g);
    ~Line();
};

Line::Line(const Point& start, const Point& end): start(start), end(end)
{
}

void Line::Draw(const Graphics& g){
    g.DrawLine(
        Pens.Red,
        start.x,
        start.y,
        end.x,
        end.y
    );
}

Line::~Line()
{
}

#endif