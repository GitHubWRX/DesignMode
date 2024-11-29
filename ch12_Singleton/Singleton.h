#ifndef SINGLETON_H
#define SINGLETON_H

// 你的类定义和实现代码
class Singleton
{
private:
    Singleton();                               // 私有构造函数
    Singleton(const Singleton& other);         // 私有拷贝构造函数
public:
    static Singleton* getInstance();
    static Singleton* m_instance;
    ~Singleton();
};

/*
静态成员变量的初始化不能放在类的定义中。
你可以在类外部（通常是在 .cpp 文件中）初始化它。
通常静态指针在初始化时设为 nullptr，表示它还没有指向任何实例。
*/
// 定义静态成员
// Singleton::m_instance当作一个变量看待即可，声明其为Singleton* 指针，赋值为nullptr
Singleton* Singleton::m_instance = nullptr;

Singleton::Singleton(/* args */)
{
}

// 双检查锁，替换Lock降低开销（但是可能存在读未初始化的内存）
// 一般对象的new初始化：1.分配内存 2.使用构造器 3.返回指针
// 但有时编译器可能先3后2，即先返回指针，然后才真正调用new，这样会导致其他读取者误读
inline Singleton *Singleton::getInstance()
{   
    // 第一个检查点，防止读等待
    if (m_instance == nullptr){
        Lock lock; // 为空才去竞争，第二个检查点，防止写冲突
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

Singleton::~Singleton()
{
}


#endif // SINGLETON_H
