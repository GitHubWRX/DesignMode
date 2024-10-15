// 此处采用抽象设计模式，每个类都只需要继承Shape，然后实现自己的Draw，但是可以使用多态
#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    /* data */
    
public:
    Shape(/* args */);
    // 这里必须被继承，只是一个壳子
    virtual void Draw(const Graphics& g) = 0;
    ~Shape();
};

Shape::Shape(/* args */)
{
}

Shape::~Shape()
{
}

#endif