/*
最简单的观察者，需要继承IProgress并实现DoProgress，持有具体的观察者（而不去修改它）
*/
#ifndef PROGRESSBARNOTIFIER_H
#define PROGRESSBARNOTIFIER_H

#include "../../common.h"
#include "IProgress.h" // 方法 DoProgress
#include "ProgressBar.h" // 方法 setDegree


class ProgressBarNotifier : public IProgress
{
private:
    ProgressBar* m_progressBar; // 这里不用修改，依然使用具体的类，其内部的setValue方法将被包装
public:
    ProgressBarNotifier(ProgressBar* pie);
    virtual void DoProgress(float value);
    ~ProgressBarNotifier();
};

ProgressBarNotifier::ProgressBarNotifier(ProgressBar* progressBar):
    m_progressBar(progressBar){ // 具体类型的传递1
}

void ProgressBarNotifier::DoProgress(float value)
{
    m_progressBar->setValue(value);  // 不同的具体类使用不同的方法，但都封装成DoProgress
}

ProgressBarNotifier::~ProgressBarNotifier()
{
}

#endif