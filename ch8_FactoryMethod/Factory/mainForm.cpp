/*
改变1：增加一个观察者，即进度条 ProgressBar:当文件分割的时候，展示进度条
    需要将文件切割进度通知到另一个类，这个类应当是由指针传递进来的，这样可以被别的类读取
*/

#include "../../common.h"
#include "Form.h"
#include "TextBox.h"
#include "FileSpliter.h"

#include "IProgress.h" // 方法 DoProgress
// 以下两个类并不用继承IProgress，相反，调用他们的类继承了Progress，并将调用者指针传递给被观察者
// 如果直接继承IProgress，由于两个类生成进度的方法名不一样，那么各自要增加一个方法DoProgress
// 本着将修改封闭在特定区域，建议只修改使用者，比如mainForm为新增加的代码，让其继承IProgress
#include "ProgressBar.h" // 方法 setValue
#include "ProgressBarNotifier.h"
#include "Pie.h" // 方法 setDegree
#include "PieNotifier.h"
#include "SpliterFactory.h"
#include "ISpliter.h"

// 重定义可以使用using或者typedef
// using TextBox1 = string;
// typedef string TextBox2;

class mainForm : public Form
{
private:
    /* data */
    SpliterFactory* m_factory;
    TextBox* m_txtFilePath; // 待分割文件的路径
    TextBox* m_txtFileNumber; // 待分割文件的个数
    // 需要多少观察者，都在这里添加即可
    ProgressBar* m_progressBar; // 这里不用修改，依然使用具体的类，其内部的setValue方法将被包装
    Pie* m_pie; // 所有的实际观察者，都应当由外部用指针传入，否则外部无法访问该内存
public:
    mainForm(SpliterFactory* factory, TextBox* txtFilePath, TextBox* txtFileNumber, ProgressBar* progressBar, Pie* pie);

    void Button1_Click(){ // 在这里初始化被观察者，并添加不同的观察者，将自己也作为其中一个观察者
        string filePath = m_txtFilePath->getText();
        int number = atoi(m_txtFileNumber->getText().c_str());

        // 首个观察者，将持有file_spliter，然后将自己传递进去，那么其他观察者就没法传递了
        // 为了能够实现多观察者，需要将FileSpliter改造，支持向量存储多个指针
        // 这里实现得不是很优雅，因为让一个观察者负责其他观察者的接入，其他观察者也需要被IProgress子类持有
        
        
        ISpliter* spliter = m_factory->CreateSpliter(); // 可传递本类的指针，因实现了IProgress

        // 使用栈变量生成ProgressBarNotifier对象，并且传递给spliter
        ProgressBarNotifier progressBarNotifier(m_progressBar);
        spliter->add_IProgress(&progressBarNotifier);

        // 使用栈变量生成PieNotifier对象，并且传递给spliter
        PieNotifier pieNotifier(m_pie);
        spliter->add_IProgress(&pieNotifier);

        // spliter开始工作，通知各个观察者
        spliter->split();
    }

    virtual void DoProgress(float value);

    ~mainForm();
};

mainForm::mainForm(SpliterFactory* factory, TextBox* txtFilePath, TextBox* txtFileNumber, ProgressBar* progressBar, Pie* pie):
    m_factory(factory),
    m_txtFilePath(txtFilePath), 
    m_txtFileNumber(txtFileNumber), 
    m_progressBar(progressBar),
    m_pie(pie){ // 具体类型的传递1
}

void mainForm::DoProgress(float value)
{
    m_progressBar->setValue(value);  // 不同的具体类使用不同的方法，但都封装成DoProgress
}

mainForm::~mainForm()
{
}
