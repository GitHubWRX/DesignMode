#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line
{
public:
    /* data */
    Point start; 
    Point end;
public:
    Line(const Point& start, const Point& end);
    ~Line();
};

Line::Line(const Point& start, const Point& end): start(start), end(end)
{
}

Line::~Line()
{
}

#endif