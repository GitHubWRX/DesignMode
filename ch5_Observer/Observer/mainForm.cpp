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
#include "Pie.h" // 方法 setDegree


// 重定义可以使用using或者typedef
// using TextBox1 = string;
// typedef string TextBox2;

class mainForm : public Form, public IProgress
{
private:
    /* data */
    TextBox* m_txtFilePath; // 待分割文件的路径
    TextBox* m_txtFileNumber; // 待分割文件的个数
    ProgressBar* m_progressBar; // 这里不用修改，依然使用具体的类，其内部的setValue方法将被包装
public:
    mainForm(TextBox* txtFilePath, TextBox* txtFileNumber, ProgressBar* progressBar);

    void Button1_Click(){
        string filePath = m_txtFilePath->getText();
        int number = atoi(m_txtFileNumber->getText().c_str());

        FileSpliter spliter(filePath, number, this); // 可传递本类的指针，因实现了IProgress
        spliter.split();
    }

    virtual void DoProgress(float value);

    ~mainForm();
};

mainForm::mainForm(TextBox* txtFilePath, TextBox* txtFileNumber, ProgressBar* progressBar):
    m_txtFilePath(txtFilePath), 
    m_txtFileNumber(txtFileNumber), 
    m_progressBar(progressBar){ // 具体类型的传递1
}

void mainForm::DoProgress(float value)
{
    m_progressBar->setValue(value);  // 不同的具体类使用不同的方法，但都封装成DoProgress
}

mainForm::~mainForm()
{
}
