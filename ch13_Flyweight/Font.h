#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H
#include "../common.h"
// 这里Font指的是单个共享模块

class Font
{
private:
    /* data */
    string m_key;
public:
    Font(const string& key);
    // 打印当前 Font 的键值
    void display() const;
    ~Font();
};

Font::Font(const string& key)
{
    m_key = key;
}

// 常成员函数 的作用是 不能修改对象的成员变量（除非它们是 mutable 类型）。
// 对 const 对象的调用： 只有 const 成员函数才能被 const 对象调用(非const对象均可调用)
void Font::display() const {
    cout << "Font with key: " << m_key << endl;
}

Font::~Font()
{
}




#endif