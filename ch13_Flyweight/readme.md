Flyweight 和 Singleton 模式的区别
Flyweight（享元模式） 和 Singleton（单例模式） 是两种不同的设计模式，虽然在某些场景中可能会结合使用，但它们的目的和实现方式是不同的。

1. Flyweight（享元模式）
目的：

通过共享大量细粒度对象来减少内存使用。
将对象的可变状态和不可变状态分离，共享不可变状态以减少重复。
适用场景：

系统需要大量细粒度对象，且这些对象存在共享的可能性。
这些对象中有相同的部分（内部状态）和不同的部分（外部状态）。
实现：

享元工厂（Flyweight Factory）： 管理和维护共享对象。
享元对象（Flyweight）： 负责存储共享数据。
外部状态： 在需要时由客户端维护。
2. Singleton（单例模式）
目的：

确保一个类只有一个实例，并提供一个全局访问点。
提供对唯一实例的受控访问。
适用场景：

应用中需要一个全局共享的资源，例如配置对象、日志记录器或线程池。
实现：

控制类的实例化过程，通过私有构造函数限制实例化。
提供一个静态方法获取唯一实例。
核心区别
特性	Flyweight	Singleton
目标	减少内存使用，支持对象共享	保证类只有一个实例
实例个数	可以有多个共享实例	仅有一个实例
共享机制	共享对象的内部状态	不涉及共享机制
主要关注点	提升性能，减少重复对象	提供一个全局访问点
典型实现	需要工厂管理共享对象	使用静态变量和静态方法创建唯一实例
示例代码
Flyweight 示例： 用享元模式实现一个文本编辑器中的字符对象共享。

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// Flyweight: 共享的字符对象
class Character {
public:
    Character(char c) : symbol(c) {}
    void display(int size) const {
        std::cout << "Character: " << symbol << " with size: " << size << "\n";
    }

private:
    char symbol;
};

// Flyweight Factory: 管理共享的字符对象
class CharacterFactory {
public:
    std::shared_ptr<Character> getCharacter(char c) {
        if (characters.find(c) == characters.end()) {
            characters[c] = std::make_shared<Character>(c);
        }
        return characters[c];
    }

private:
    std::unordered_map<char, std::shared_ptr<Character>> characters;
};

// Client
int main() {
    CharacterFactory factory;

    // 创建共享对象
    auto a1 = factory.getCharacter('A');
    auto a2 = factory.getCharacter('A'); // 重用已创建的对象
    auto b = factory.getCharacter('B');

    // 使用外部状态
    a1->display(12);
    a2->display(14); // 共享同一个内部对象，但外部状态不同
    b->display(18);

    return 0;
}
```

Singleton 示例： 实现一个简单的日志记录器。
```cpp
#include <iostream>
#include <string>
#include <mutex>

// Singleton: 日志记录器
class Logger {
public:
    // 获取唯一实例
    static Logger& getInstance() {
        static Logger instance; // 唯一实例
        return instance;
    }

    // 禁用拷贝和赋值
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "[LOG]: " << message << "\n";
    }

private:
    Logger() = default; // 私有构造函数
    std::mutex mutex_;
};

// Client
int main() {
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();

    // 确保唯一实例
    logger1.log("This is a log message.");
    logger2.log("This is another log message.");

    return 0;
}
```
结合使用:在某些场景中，Flyweight 工厂本身可以用 Singleton 实现。例如：

```cpp
class FlyweightFactorySingleton {
public:
    static FlyweightFactorySingleton& getInstance() {
        static FlyweightFactorySingleton instance;
        return instance;
    }

    // Flyweight 逻辑
    std::shared_ptr<Character> getCharacter(char c) {
        if (characters.find(c) == characters.end()) {
            characters[c] = std::make_shared<Character>(c);
        }
        return characters[c];
    }

private:
    FlyweightFactorySingleton() = default;
    std::unordered_map<char, std::shared_ptr<Character>> characters;
};
```
这种实现确保工厂类也只有一个实例，从而避免不必要的重复。