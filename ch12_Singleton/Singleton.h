#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>
#include <atomic>

class Singleton
{
private:
    Singleton();  // 私有构造函数
    Singleton(const Singleton& other);  // 私有拷贝构造函数
    Singleton& operator=(const Singleton& other);  // 私有赋值运算符

public:
    static Singleton* getInstance();  // 获取单例实例
    static std::atomic<Singleton*> m_instance;  // 单例实例的原子指针
    static std::mutex m_mutex;  // 用于保护实例创建的锁
    ~Singleton();  // 析构函数
};

// 静态成员变量的定义，需要在类外部定义
// m_instance 是一个原子指针，它用于确保多线程环境下对 Singleton 实例的访问是安全的。
std::atomic<Singleton*> Singleton::m_instance(nullptr);
std::mutex Singleton::m_mutex;

// 私有构造函数
Singleton::Singleton() {
    // 初始化代码
}

inline Singleton &Singleton::operator=(const Singleton &other)
{
    // TODO: 在此处插入 return 语句
}

// 双重检查锁定实现
inline Singleton* Singleton::getInstance()
{
    // 第一个检查：是否已创建实例
    Singleton* tmp = m_instance.load(std::memory_order_acquire);  // 获取当前实例
    if (tmp != nullptr) {
        return tmp;  // 如果实例已创建，直接返回
    }

    // 第二个检查：加锁后再次检查
    std::lock_guard<std::mutex> lock(m_mutex);
    tmp = m_instance.load(std::memory_order_acquire);  // 再次检查是否已经有其他线程创建了实例
    if (tmp == nullptr) {
        tmp = new Singleton();  // 创建实例
        m_instance.store(tmp, std::memory_order_release);  // 设置实例并发布给其他线程
    }

    return tmp;
}

// 析构函数
Singleton::~Singleton()
{
    // 清理资源的代码
}

#endif // SINGLETON_H
