#include <vector>
#include <iostream>
#include <algorithm>
#include "MouseEventArgs.h"
#include "Line.h"
#include "Rect.h"
#include "Form.h"
using namespace std;

class MainForm: public Form
{
private:
    /* data */
    Point p1;
    Point p2;

    vector<Line> lineVector;
    vector<Rect> rectVector;

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
        Line line(p1, p2)
        lineVector.push_back(line);
    }else if(rdoRect.Checked){
        Rect rect(p1, abs(p2.x-p1.x), abs(p2.y-p1.y));
        rectVector.push_back(rect);
    }

    // 刷新页面，这个应当是
    this->Refresh();
    Form::OnMouseUp(e);

}

// 看起来这里会每次都全部重新绘制所有的内容，并且绘制完成后没有pop操作
void MainForm::OnPaint(const MouseEventArgs e){
    
    // 针对直线
    for(int i = 0; i < lineVector.size(); i++){
        // 应当是调用了系统绘制直线
        e.Graphics.DrawLine(
            Pens.Red, // need color and so on.
            lineVector[i].start.x,
            lineVector[i].start.y,
            lineVector[i].end.x,
            lineVector[i].end.y
        );
    }

    // 针对矩形
    for(int i = 0; i < rectVector.size(); i++){
        e.Graphics.DrawRectangle(
            Pens.Yellow,
            rectVector[i].leftup,
            rectVector[i].width,
            rectVector[i].height
        );
    }

    Form::OnPaint(e);
}