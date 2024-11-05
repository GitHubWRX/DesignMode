/*
最简单的观察者，需要继承IProgress并实现DoProgress，持有具体的观察者（而不去修改它）
*/

#include "../../common.h"
#include "Form.h"
#include "TextBox.h"
#include "FileSpliter.h"

#include "IProgress.h" // 方法 DoProgress
#include "Pie.h" // 方法 setDegree


class PieNotifier : public IProgress
{
private:
    Pie* m_pie; // 这里不用修改，依然使用具体的类，其内部的setValue方法将被包装
public:
    PieNotifier(Pie* pie);
    virtual void DoProgress(float value);
    ~PieNotifier();
};

PieNotifier::PieNotifier(Pie* pie):
    m_pie(pie){ // 具体类型的传递1
}

void PieNotifier::DoProgress(float value)
{
    m_pie->setDegree(value);  // 不同的具体类使用不同的方法，但都封装成DoProgress
}

PieNotifier::~PieNotifier()
{
}
