#ifndef RECT_H
#define RECT_H
#include "Point.h"
#include "Shape.h"

class Rect: public Shape
{
public:
    /* data */
    Point leftup;
    int width;
    int height;
public:
    Rect(const Point& leftup, const int width, const int height);
    virtual void Draw(const Graphics& g);
    ~Rect();
};

Rect::Rect(const Point& leftup, const int width, const int height)
{
    this->leftup = leftup;
    this->width = width;
    this->height = height;
}

void Rect::Draw(const Graphics& g){
    g.DrawRect(            
        Pens.Yellow,
        leftup,
        width,
        height
    );
}

Rect::~Rect()
{
}

#endif