### 动机
面临复杂对象的创建工作，其各个部分的子对象用一定的算法构成，由于需求的变化，各个组成部分经常面临着剧烈的变化，但是将它们组合再一起的算法却相对稳定，所以这个组合算法可以认为是builder或者director，类似于template method。**算法结构稳定，但是先多变**

### 简介
构建器模式（Builder Pattern） 是一种创建型设计模式，主要用于通过一个**指挥者（Director）**来控制多个步骤的构建过程，从而构造一个复杂对象。构建器模式允许我们将一个复杂对象的创建过程与它的表示分离，使得同样的构建过程可以创建不同的表示。

目的和应用场景
目的是简化复杂对象的创建过程，使其更加灵活且易于扩展。
常见应用场景：对象的构建步骤较为复杂，且对象的构建过程可能会根据不同的需求有不同的表现。
例如：
构建一个包含多个子组件的大型对象，比如一辆汽车，其中包括车轮、引擎、座椅等组件。
复杂的HTML页面、文档、报告的生成，可能需要根据用户需求选择不同的格式和内容。

### 组成部分
构建器模式通常由以下几部分组成：

1. 产品（Product）：
    表示最终构建的复杂对象。
2. 抽象建造者（Builder）：
    提供构建产品各个部分的接口。每个具体建造者负责构建产品的某一部分。
3. 具体建造者（ConcreteBuilder）：
    实现了抽象建造者接口，负责创建一个产品的具体部分。
4. 指挥者（Director）：
    控制构建过程，并且调用具体建造者的步骤，构建出完整的产品。
5. 客户端（Client）：
    负责选择使用哪个具体建造者，并通过指挥者获取产品。

### 构建器模式的优点
1. 分离了复杂对象的构建和表示：客户端不需要知道对象是如何构建的，避免了直接与复杂构建过程交互。
2. 支持不同表现形式的产品：可以通过不同的建造者实现相同产品的不同表现形式。
3. 代码清晰易扩展：每个具体建造者负责不同的部分，使得扩展产品变得容易，符合开放/封闭原则。

### 示例

假设我们要构建一个复杂的**Computer**对象，它包含多个部分，如 CPU、内存、硬盘和操作系统。


```cpp
// 1. 定义产品（Product）
class Computer {
public:
    std::string CPU;
    std::string RAM;
    std::string HDD;
    std::string OS;

    void showDetails() {
        std::cout << "CPU: " << CPU << std::endl;
        std::cout << "RAM: " << RAM << std::endl;
        std::cout << "HDD: " << HDD << std::endl;
        std::cout << "OS: " << OS << std::endl;
    }
};


// 2. 抽象建造者（Builder）
class ComputerBuilder {
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildHDD() = 0;
    virtual void buildOS() = 0;
    virtual Computer* getComputer() = 0;
};

// 3. 具体建造者（ConcreteBuilder）
class GamingComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    GamingComputerBuilder() { computer = new Computer(); }

    void buildCPU() override {
        computer->CPU = "Intel i9 10900K";
    }

    void buildRAM() override {
        computer->RAM = "32GB DDR4";
    }

    void buildHDD() override {
        computer->HDD = "1TB SSD";
    }

    void buildOS() override {
        computer->OS = "Windows 10";
    }

    Computer* getComputer() override {
        return computer;
    }
};


class OfficeComputerBuilder : public ComputerBuilder {
private:
    Computer* computer;

public:
    OfficeComputerBuilder() { computer = new Computer(); }

    void buildCPU() override {
        computer->CPU = "Intel i5 10400";
    }

    void buildRAM() override {
        computer->RAM = "8GB DDR4";
    }

    void buildHDD() override {
        computer->HDD = "500GB SSD";
    }

    void buildOS() override {
        computer->OS = "Windows 10";
    }

    Computer* getComputer() override {
        return computer;
    }
};

// 4. 指挥者（Director）
class Director {
private:
    ComputerBuilder* builder;

public:
    Director(ComputerBuilder* builder) : builder(builder) {}

    Computer* construct() {
        builder->buildCPU();
        builder->buildRAM();
        builder->buildHDD();
        builder->buildOS();
        return builder->getComputer();
    }
};


// 5. 客户端（Client）
int main() {
    // 使用GamingComputerBuilder构建高端游戏电脑
    ComputerBuilder* gamingBuilder = new GamingComputerBuilder();
    Director director(gamingBuilder);
    Computer* gamingPC = director.construct();
    std::cout << "Gaming PC details:" << std::endl;
    gamingPC->showDetails();

    std::cout << "\n";

    // 使用OfficeComputerBuilder构建办公电脑
    ComputerBuilder* officeBuilder = new OfficeComputerBuilder();
    Director officeDirector(officeBuilder);
    Computer* officePC = officeDirector.construct();
    std::cout << "Office PC details:" << std::endl;
    officePC->showDetails();

    delete gamingPC;
    delete officePC;

    return 0;
}

```

输出结果
```output
Gaming PC details:
CPU: Intel i9 10900K
RAM: 32GB DDR4
HDD: 1TB SSD
OS: Windows 10

Office PC details:
CPU: Intel i5 10400
RAM: 8GB DDR4
HDD: 500GB SSD
OS: Windows 10
```

### 总结
构建器模式非常适合用于构建需要多个步骤的复杂对象。
通过将构建过程和产品的表示分离，构建器模式使得创建复杂对象的过程更加灵活且可扩展。
在示例中，通过使用不同的建造者（GamingComputerBuilder 和 OfficeComputerBuilder），我们可以根据不同需求创建不同配置的电脑。构建器模式的关键在于**将产品的构建过程控制权交给指挥者**，从而使得客户端能够专注于选择适合的建造者，而不用关心具体的构建步骤。