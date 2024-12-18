### 中介者模式（Mediator Pattern）
中介者模式是一种行为型设计模式，它旨在通过引入一个中介者对象来减少对象之间的直接通信和依赖关系。这样，多个对象之间不再直接相互交互，而是通过中介者来协调它们的行为。这样做的好处是减少了对象之间的耦合，使得系统更加模块化，容易维护和扩展。

### 主要参与者
Mediator（中介者接口）：定义中介者与各个同事类之间的交互接口。
ConcreteMediator（具体中介者）：实现中介者接口，协调各个同事类之间的交互。
Colleague（同事类）：**每个同事类都知道中介者**并通过中介者与其他同事类进行交互，而不直接相互交互。
ConcreteColleague（具体同事类）：实现同事类接口，并在需要时与中介者交互。

### 适用场景
对象之间有复杂的交互关系时，希望通过集中管理对象的交互来简化系统。
减少对象之间的直接联系，让一个中介者集中处理协调工作。

### 中介者模式的优点
降低耦合度：对象之间不再直接通信，所有的交互都通过中介者进行，这使得系统中的对象解耦。
集中控制：中介者模式将交互的控制集中到一个对象中，便于管理。
易于扩展：如果添加新的同事类，现有的同事类不需要修改，只需要在中介者中添加逻辑即可。

### 中介者模式的缺点
中介者可能过于复杂：随着系统规模的增大，中介者对象可能变得非常庞大和复杂，导致其本身变得难以维护。
破坏了单一职责原则：中介者对象承担了协调所有对象的职责，这可能导致该对象承担过多的责任。

### C++ 中的实现
假设我们有一个聊天室的例子，其中有多个用户，每个用户可以发送消息给其他用户。通过中介者模式，我们可以将消息的发送交给聊天室中介者来处理，而不是用户之间直接发送消息。

#### 类图示意
```lua
+----------------+            +------------------+
|    Mediator    |<-----------|    ConcreteColleague |
|----------------|            |----------------------|
|+ notify()      |            |+ sendMessage()       |
+----------------+            +-----------------------+
           ^
           |
           |          
   +----------------+
   | ConcreteMediator|
   +----------------+
           |
   +-------------------+        +-------------------+
   | ConcreteColleague |        | ConcreteColleague |
   +-------------------+        +-------------------+
   | sendMessage()     |        | sendMessage()     |
   +-------------------+        +-------------------+

```

#### C++实现
```cpp
#include <iostream>
#include <vector>
#include <string>

// 中介者接口
class Mediator {
public:
    virtual void sendMessage(const std::string& message, class Colleague* colleague) = 0;
};

// 同事类接口
class Colleague {
protected:
    Mediator* mediator;  // 每个同事类持有一个中介者对象的引用

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void sendMessage(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& message) = 0;
};

// 具体中介者类
class ConcreteMediator : public Mediator {
private:
    // 为什么不在Meidator
    std::vector<Colleague*> colleagues;  // 存储所有的同事类对象

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void sendMessage(const std::string& message, Colleague* colleague) override {
        // 通过中介者将消息广播给所有的同事类
        for (auto c : colleagues) {
            // 不向发送消息的同事发送消息
            if (c != colleague) {
                c->receiveMessage(message);
            }
        }
    }
};

// 具体同事类 - 用户A
class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator* mediator) : Colleague(mediator) {}

    void sendMessage(const std::string& message) override {
        std::cout << "User A sends message: " << message << std::endl;
        mediator->sendMessage(message, this);
    }

    void receiveMessage(const std::string& message) override {
        std::cout << "User A received message: " << message << std::endl;
    }
};

// 具体同事类 - 用户B
class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator* mediator) : Colleague(mediator) {}

    void sendMessage(const std::string& message) override {
        std::cout << "User B sends message: " << message << std::endl;
        mediator->sendMessage(message, this);
    }

    void receiveMessage(const std::string& message) override {
        std::cout << "User B received message: " << message << std::endl;
    }
};

int main() {
    ConcreteMediator mediator;

    // 创建两个用户并添加到中介者中
    ConcreteColleagueA userA(&mediator);
    ConcreteColleagueB userB(&mediator);

    mediator.addColleague(&userA);
    mediator.addColleague(&userB);

    // 用户A发送消息
    userA.sendMessage("Hello from A");

    // 用户B发送消息
    userB.sendMessage("Hello from B");

    return 0;
}

```

#### 解释
Mediator（中介者接口）：Mediator 定义了 sendMessage 方法，它允许同事类通过它来发送消息。

Colleague（同事类接口）：Colleague 是所有具体同事类的基类，它定义了 sendMessage 和 receiveMessage 方法。

ConcreteMediator（具体中介者类）：ConcreteMediator 实现了 Mediator 接口，并负责管理多个同事类（用户）。它的职责是协调各个同事之间的消息传递。

ConcreteColleagueA 和 ConcreteColleagueB（具体同事类）：这些类代表具体的用户，每个用户都知道中介者对象，并通过中介者来与其他用户通信。每个用户都有一个 sendMessage 和 receiveMessage 方法，sendMessage 用于发送消息，receiveMessage 用于接收消息。

#### 输出示例
```txt
User A sends message: Hello from A
User A received message: Hello from A
User B received message: Hello from A
User B sends message: Hello from B
User A received message: Hello from B
User B received message: Hello from B
```

### 总结
中介者模式 通过引入一个中介者来协调各个对象之间的通信，而不是让对象直接通信，这样减少了对象之间的耦合。
优点：可以减少类之间的依赖关系，使得系统更加灵活和可扩展。
缺点：中介者本身可能会变得过于庞大，充当了过多的职责。