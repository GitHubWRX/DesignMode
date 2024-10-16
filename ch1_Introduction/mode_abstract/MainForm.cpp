#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "MouseEventArgs.h"
#include "Line.h"
#include "Rect.h"
#include "Circle.h"
#include "Form.h"
#include "Shape.h"

using namespace std;

class MainForm: public Form
{
private:
    /* data */
    Point p1;
    Point p2;

    // no need use different type of vector, all can be Shape Pointer
    vector<Shape*> shapeVector;

public:
    MainForm(/* args */);
    void Refresh();
    ~MainForm();

protected:
    virtual void OnMouseDown(const MouseEventArgs e);
    virtual void OnMouseUp(const MouseEventArgs e);
    virtual void OnPaint(const MouseEventArgs e);

};

MainForm::MainForm(/* args */)
{
}

MainForm::~MainForm()
{
}

// 负责刷新
void MainForm::Refresh(){
    cout << "MainForm is Refreshing" << endl;
}

void MainForm::OnMouseDown(const MouseEventArgs e){
    p1.x = e.x;
    p1.y = e.y;
    Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs e){
    p2.x = e.x;
    p2.y = e.y;

    // 判断画的是哪种形状，选择绘制方法（这里的判断可能是来自于预先设置的某个全局变量）
    if(rdoLine.Checked){
        Shape* shape = new Line(p1, p2);
        shapeVector.push_back(shape);
    }else if(rdoRect.Checked){
        shapeVector.push_back(new Rect(p1, abs(p2.x-p1.x), abs(p2.y-p1.y)));
    }else if(rdoCircle.Checked){
        shapeVector.push_back(new Circle(p1, sqrt((float)(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2)))));
    }

    // 刷新页面，这个应当是
    this->Refresh();
    Form::OnMouseUp(e);

}

// 看起来这里会每次都全部重新绘制所有的内容，并且绘制完成后没有pop操作
void MainForm::OnPaint(const MouseEventArgs e){
    
    // 不再区分针对直线或者矩形
    for(int i = 0; i < shapeVector.size(); i++){
        shapeVector[i]->Draw(e.Graphics); // 多态调度，各负其责
    }

    Form::OnPaint(e);
}