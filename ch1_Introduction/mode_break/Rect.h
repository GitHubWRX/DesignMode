#ifndef RECT_H
#define RECT_H
#include "Point.h"

class Rect
{
public:
    /* data */
    Point leftup;
    int width;
    int height;
public:
    Rect(const Point& leftup, const int width, const int height);
    ~Rect();
};

Rect::Rect(const Point& leftup, const int width, const int height)
{
    this->leftup = leftup;
    this->width = width;
    this->height = height;
}

Rect::~Rect()
{
}

#endif