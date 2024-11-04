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

// 重定义可以使用using或者typedef
// using TextBox1 = string;
// typedef string TextBox2;

class mainForm : public Form
{
private:
    /* data */
    TextBox* m_txtFilePath; // 待分割文件的路径
    TextBox* m_txtFileNumber; // 待分割文件的个数
    ProgressBar* m_progressBar; // 具体类型传递1
    Pie* m_pie; // 具体类型传递2
public:
    mainForm(TextBox* txtFilePath, TextBox* txtFileNumber, ProgressBar* progressBar, Pie* pie);

    void Button1_Click(){
        string filePath = m_txtFilePath->getText();
        int number = atoi(m_txtFileNumber->getText().c_str());

        FileSpliter spliter(filePath, number, m_progressBar, m_pie); // 修改，具体类型传递2
        spliter.split();
    }

    ~mainForm();
};

mainForm::mainForm(TextBox* txtFilePath, TextBox* txtFileNumber, ProgressBar* progressBar, Pie* pie):
    m_txtFilePath(txtFilePath), 
    m_txtFileNumber(txtFileNumber), 
    m_progressBar(progressBar), // 具体类型的传递1
    m_pie(pie){ // 具体类型的传递2
}

mainForm::~mainForm()
{
}
