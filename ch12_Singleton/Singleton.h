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

// 非线程安全版本，多线程下，均可能执行到23行，但未执行24行，重复创建
inline Singleton *Singleton::getInstance()
{   
    Lock lock; // 此处为伪代码，意味着会获取锁，但是开销比较大，每个调用均获取
    if (m_instance == nullptr){
        m_instance = new Singleton();
    }
    return m_instance;
}

Singleton::~Singleton()
{
}


#endif // SINGLETON_H
