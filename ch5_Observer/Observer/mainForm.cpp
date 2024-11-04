/*
改变1：增加一个观察者，即进度条 ProgressBar:当文件分割的时候，展示进度条
    需要将文件切割进度通知到另一个类，这个类应当是由指针传递进来的，这样可以被别的类读取
*/

#include "../../common.h"
#include "Form.h"
#include "TextBox.h"
#include "FileSpliter.h"
#include "ProgressBar.h"
#include "Pie.h"
#include "IProgress.h"

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
