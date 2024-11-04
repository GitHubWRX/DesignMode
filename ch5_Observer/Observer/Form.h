#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "MouseEventArgs.h"
using namespace std;

class Form
{
private:
    /* data */
public:
    Form(/* args */);
    ~Form();
protected:
    virtual void OnMouseDown(const MouseEventArgs e);
    virtual void OnMouseUp(const MouseEventArgs e);
    virtual void OnPaint(const MouseEventArgs e);
};

Form::Form(/* args */)
{
}

Form::~Form()
{
}

void Form::OnMouseDown(const MouseEventArgs e){
    cout << "Form's OnMouseDown" << endl;
}

void Form::OnMouseUp(const MouseEventArgs e){
    cout << "Form's OnMouseUp" << endl;
}

void Form::OnPaint(const MouseEventArgs e){
    cout << "Form's OnPaint" << endl;
}

#endif