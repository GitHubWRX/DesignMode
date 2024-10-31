#include "../../common.h"
#include "Form.h"
#include "TextBox.h"
#include "FileSpliter.h"

// 重定义可以使用using或者typedef
// using TextBox1 = string;
// typedef string TextBox2;

class mainForm : public Form
{
private:
    /* data */
    TextBox* txtFilePath; // 待分割文件的路径
    TextBox* txtFileNumber; // 待分割文件的个数
public:
    mainForm(/* args */);

    void Button1_Click(){
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        FileSpliter spliter(filePath, number);
        spliter.split();
    }

    ~mainForm();
};

mainForm::mainForm(/* args */)
{
}

mainForm::~mainForm()
{
}
