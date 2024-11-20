### 动机
软件系统中，经常面临某些复杂对象的创建工作，虽然对象经常面临着剧烈的变化，但是他们却拥有比较稳定一直的接口。

如何应对这种变化，如何向客户程序隔离出这些以便对象，从而使得以来这些易变对象的客户程序“不随着需求改变而改变”？

以上为什么是原型模式的动机？

#### 原型模式的动机
复杂对象的创建
某些对象可能需要复杂的初始化过程（比如加载配置文件、初始化大量数据、或者需要与外部系统交互），但这些对象本身在逻辑上并不经常变化。如果每次都通过直接创建（new）来生成这些对象，会导致代码重复、性能低下，甚至引入不必要的耦合。

#### 对象频繁变化而接口稳定
尽管对象的内部数据或属性经常需要修改，但它的接口通常是固定不变的。例如，在一个系统中，不同类型的报告可能使用相同的接口生成，但具体的生成逻辑和数据是不同的。我们需要一种机制来生成这些变化的对象，而不会影响到使用这些对象的客户代码。

#### 客户程序的解耦
客户代码的稳定性很重要。如果客户代码直接依赖于复杂对象的具体创建逻辑（例如调用多个构造函数、初始化流程等），当对象的需求变化时，客户代码也需要修改，这违背了软件设计的开闭原则（对扩展开放，对修改关闭）。因此，需要一种机制隔离客户程序和对象的创建逻辑。

### 原型模式如何解决这些问题？
原型模式通过克隆现有对象来创建新对象，避免了直接调用复杂的构造函数或初始化流程。其动机体现在以下几个方面：

#### 简化复杂对象的创建
通过复制（clone）已经存在的对象，可以快速创建新对象，而不必重复复杂的初始化操作。例如：

一个对象需要从数据库加载大量数据，初始化一次后，可以克隆来复用这个对象。
隔离对象创建的复杂性
客户代码不需要关心对象如何创建，只需要调用其 clone 方法。这种隔离使得客户代码与对象创建逻辑解耦，当对象需求发生变化时，只需修改原型对象，无需改动客户代码。

#### 灵活应对对象变化
使用原型模式时，可以轻松定制新对象：

克隆一个原型对象后，**只需对新对象进行少量修改即可满足需求**。
即使对象本身发生较大变化，客户代码仍然只依赖于其稳定的接口。
原型模式的核心动机是应对复杂对象创建的变化性，同时隔离客户程序与具体对象的创建逻辑。
它通过克隆现有对象来代替直接创建对象，使得代码更灵活、扩展性更强，并且降低了客户程序与对象变化之间的耦合性。这种设计遵循了**开闭原则**，使得软件更易于维护和扩展。


### GPT 问答


```cpp
class Report {
public:
    virtual void generate() = 0;  // 生成报告
    virtual Report* clone() = 0;  // 克隆当前报告对象
    virtual ~Report() {}
};
```
内部数据经常变化
具体的报告（如销售报告和库存报告）需要的数据和生成逻辑会不断变化。例如：

销售报告可能需要添加更多的统计指标（如同比增长率）。
财务报告可能需要修改生成格式（如增加图表支持）。
这些变化会导致对应的具体实现类需要频繁调整，但客户代码依赖的接口 generate() 并不会改变。

具体实现
```cpp
// 销售报告（SalesReport）
class SalesReport : public Report {
private:
    std::string data;  // 销售数据
public:
    SalesReport(const std::string& initialData) : data(initialData) {}
    void generate() override {
        std::cout << "Generating Sales Report with data: " << data << std::endl;
    }
    Report* clone() override {
        return new SalesReport(*this);  // 克隆自己
    }
};

// 库存报告（InventoryReport）
class InventoryReport : public Report {
private:
    std::string inventoryData;  // 库存数据
public:
    InventoryReport(const std::string& initialData) : inventoryData(initialData) {}
    void generate() override {
        std::cout << "Generating Inventory Report with data: " << inventoryData << std::endl;
    }
    Report* clone() override {
        return new InventoryReport(*this);  // 克隆自己
    }
};

// 客户代码（统一依赖接口） 客户代码只依赖 Report 接口，无需关心报告的具体类型和实现：
void generateReport(Report* prototype) {
    // 克隆原型
    Report* newReport = prototype->clone();
    // 生成新报告
    newReport->generate();
    delete newReport;
}

int main() {
    SalesReport salesPrototype("Initial Sales Data");
    InventoryReport inventoryPrototype("Initial Inventory Data");

    // 使用原型生成不同类型的报告
    generateReport(&salesPrototype);
    generateReport(&inventoryPrototype);

    return 0;
}

```
客户代码解耦的好处：
1. 接口固定。
   客户代码依赖于 Report 接口，只需要调用 generate() 和 clone() 方法，而不需要知道具体实现类的内部细节。

2. 内部数据变化灵活
   如果需要修改报告的数据或生成逻辑，只需要在具体的 SalesReport 或 InventoryReport 类中修改，而无需改动客户代码。例如：

   1. 销售报告增加新的统计字段。
   2. 库存报告调整格式或添加新功能。

3. 动态扩展支持
   如果需要新增一种新类型的报告（比如财务报告），只需创建新的类实现 Report 接口，而无需修改客户代码。

#### 总结
尽管对象的内部数据或属性经常需要修改，但它的接口通常是固定不变的。在这个例子中：

固定不变的接口：Report 提供统一的 generate 和 clone 方法。
变化的内部逻辑：SalesReport 和 InventoryReport 的数据和实现可以不断变化。
通过这种设计，客户代码可以解耦具体对象的实现，专注于依赖稳定的接口，从而应对变化的需求而不影响现有系统。


<!-- 您说：
这个是多态的应用，传进来不同的类型对象，调用它实际的方法。
只不过并没有修改原始的指针，而是克隆了一份新的，
这样就不用初始化一个复杂的指针对象，我这么理解对么。 -->

<!-- ChatGPT 说：
是的，你的理解是对的！这确实是多态的一个应用，同时结合了原型模式的思想，
通过克隆机制实现了对象的复用和独立性。 -->

我们可以更清晰地拆解你的理解，进一步确认每个关键点：

1. 多态的应用
在这个设计中，客户代码只依赖抽象的 Report 接口，调用的具体方法是由传入的实际对象类型决定的。这正是多态的体现：通过 virtual 关键字和接口，客户代码对所有具体实现类一视同仁。调用 generate() 方法时，根据对象的真实类型，调用对应的具体实现。
```cpp
generateReport(&salesPrototype);  // 调用 SalesReport::generate()
generateReport(&inventoryPrototype);  // 调用 InventoryReport::generate()
```

1. 克隆创建新对象
这里的关键是克隆一份新的对象，而不是直接修改原始对象。这带来了几个好处：

避免对原始对象的影响:原型模式通过克隆创建一个新的对象，而不是直接操作原型对象本身，保证原型对象可以在其他地方复用或用作模板，不受后续操作的污染。

例如，如果需要基于 SalesReport 的原型生成多个不同的销售报告，每个报告有不同的细节：

```cpp
// 每次克隆都会创建一个独立的对象，可以根据需要修改其内容，而不会影响原型对象或其他克隆实例。
Report* report1 = salesPrototype.clone();
Report* report2 = salesPrototype.clone();
```

简化复杂对象的初始化
```cpp
// 如果初始化一个对象需要复杂的过程（比如加载大量数据或配置），通过克隆可以避免重复初始化
SalesReport salesPrototype("Initial Sales Data");  // 初始化一次
Report* newReport = salesPrototype.clone();       // 直接克隆，无需再次初始化
```

解耦对象的创建和使用
通过克隆对象，客户代码无需关心对象的初始化细节，而是通过原型获取已经初始化好的对象的副本。这种设计符合单一职责原则（对象的初始化和使用分离）：
克隆不仅避免了复杂初始化，还保证了原型对象的独立性，提升了对象的复用性。
这种设计在保证灵活性和效率的同时，还解耦了客户代码与具体对象的创建逻辑，使得系统更易扩展和维护。
这就是原型模式和多态结合的一个典型应用场景！ 🎉


### 把原型模式理解为一种模板复制的机制
每个原型对象就是一个模板，每次需要时直接复制，而不是重新创建。