### 代理模式（Proxy Pattern）简介
代理模式（Proxy Pattern） 是一种结构型设计模式，提供了一个类来作为另一个类的接口或占位符。代理类通常用于控制对原始对象的访问，或为其添加额外功能。

### 代理模式的核心思想
代理模式通过创建一个代理类（Proxy Class），在不改变原始类（Real Subject）的前提下，通过代理类来间接访问实际对象。

### 代理模式的应用场景
远程代理（Remote Proxy）： 为位于不同地址空间的对象提供本地代表（例如分布式系统中的远程调用）。
虚拟代理（Virtual Proxy）： 在需要时延迟对象的创建或初始化，节省资源。
保护代理（Protection Proxy）： 控制对对象的访问权限。
智能代理（Smart Proxy）： 在访问对象时提供额外的功能，如日志记录、缓存等。

### 代理模式的结构
Subject（抽象主题类）： 定义代理类和真实对象的共同接口。
RealSubject（真实主题类）： 被代理的对象，实际完成工作。
Proxy（代理类）： 控制对真实对象的访问，可能会在访问前后增加功能。

### 示例场景：文件访问的保护代理
我们模拟一个文件读取操作，通过代理控制文件读取的权限。如果用户没有权限，则拒绝访问。

```cpp
#include <iostream>
#include <string>
using namespace std;


```cpp
// 抽象主题类
class File {
public:
    virtual void read() const = 0; // 抽象接口，供代理类和真实类实现
    virtual ~File() {}
};
```

```cpp
// 真实主题类
class RealFile : public File {
private:
    string filename;

public:
    RealFile(const string& name) : filename(name) {}
    void read() const override {
        cout << "Reading file: " << filename << endl;
    }
};
```

```cpp
// 代理类
class FileProxy : public File {
private:
    RealFile* realFile; // 持有真实对象的指针
    bool hasAccess;     // 用户访问权限

public:
    FileProxy(const string& filename, bool access) 
        : realFile(new RealFile(filename)), hasAccess(access) {}

    void read() const override {
        if (hasAccess) {
            realFile->read(); // 有权限，访问真实对象的方法
        } else {
            cout << "Access denied. You do not have permission to read the file." << endl;
        }
    }

    ~FileProxy() {
        delete realFile; // 清理资源
    }
};
```

```cpp
// 客户端代码
int main() {
    // 用户1：有权限
    File* fileWithAccess = new FileProxy("important_data.txt", true);
    fileWithAccess->read();

    cout << endl;

    // 用户2：无权限
    File* fileWithoutAccess = new FileProxy("important_data.txt", false);
    fileWithoutAccess->read();

    delete fileWithAccess;
    delete fileWithoutAccess;

    return 0;
}
```

运行结果
```txt
Reading file: important_data.txt

Access denied. You do not have permission to read the file.
```

### 代理模式的分析
优点
控制访问： 通过代理类可以在访问真实对象之前或之后添加额外的逻辑（如权限检查、缓存、日志等）。
延迟加载： 在需要时才创建真实对象，节省资源（虚拟代理）。
解耦： 客户端无需直接操作真实对象。
缺点
性能开销： 增加了额外的类和方法调用，可能影响性能。
实现复杂度： 代码层次变多，维护起来更复杂。