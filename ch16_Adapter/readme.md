### 简介
将一个类的接口，转换成客户希望的另一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

#### 举例deqeue作为adaptee

class stack{
private:
    deqeue container;
}

class queue{
private:
    deqeue container;
}

### Adapter模式简介
Adapter（适配器）模式 是一种结构型设计模式，用于将一个类的接口转换为另一个客户端期望的接口。适配器让原本由于接口不兼容而无法工作的类能够协同工作。

### Adapter模式的核心思想
适配器模式通过提供一个包装类（Adapter），将现有类的接口（Adaptee）转换为目标接口（Target）所需要的格式。客户端可以通过目标接口与适配器交互，而不需要了解被适配的类的内部细节。

### Adapter模式的结构
Target（目标接口）：定义客户端期望的接口。
Adaptee（被适配类）：已有接口，但不符合目标接口的要求。
Adapter（适配器类）：实现目标接口，并将调用委托给被适配类。

### C++ 示例代码
示例场景：圆孔与方钉适配
我们模拟一个场景：

有一个圆形孔（RoundHole），只能接受圆形钉子（RoundPeg）。
现在需要插入方形钉子（SquarePeg），但接口不匹配。
通过适配器（SquarePegAdapter）解决这一问题。



```cpp
#include <iostream>
#include <cmath>
using namespace std;

// 圆形钉子（目标接口）
class RoundPeg {
protected:
    double radius; // 半径

public:
    RoundPeg(double r = 0) : radius(r) {}
    virtual double getRadius() const { return radius; }
};

// 圆孔（客户端期望的接口）
class RoundHole {
private:
    double radius; // 圆孔半径

public:
    RoundHole(double r) : radius(r) {}

    // 检查钉子是否可以插入
    bool fits(const RoundPeg& peg) const {
        return peg.getRadius() <= radius;
    }
};


// 方形钉子（不兼容接口）
class SquarePeg {
private:
    double width; // 方钉的边长

public:
    SquarePeg(double w) : width(w) {}
    double getWidth() const { return width; }
};

// 方钉适配器，使其看起来像圆钉
class SquarePegAdapter : public RoundPeg {
private:
    SquarePeg& squarePeg; // 引用方形钉子

public:
    SquarePegAdapter(SquarePeg& peg) : squarePeg(peg) {}

    // 重写获取半径的方法
    double getRadius() const override {
        // 根据方钉的边长计算对角线的一半，即"拟合的圆形半径"
        return squarePeg.getWidth() * sqrt(2) / 2;
    }
};


int main() {
    // 创建一个圆孔，半径为5
    RoundHole hole(5.0);

    // 创建一个圆形钉子，半径为5
    RoundPeg roundPeg(5.0);
    cout << "Round peg fits in hole: " << (hole.fits(roundPeg) ? "Yes" : "No") << endl;

    // 创建一个方形钉子，边长为5
    SquarePeg squarePeg(5.0);

    // 方钉直接尝试插入会失败，因为接口不兼容
    // 通过适配器解决问题
    SquarePegAdapter adapter(squarePeg);
    cout << "Square peg fits in hole (via adapter): " << (hole.fits(adapter) ? "Yes" : "No") << endl;

    return 0;
}


```

<!-- 运行结果 -->
```txt
Round peg fits in hole: Yes
Square peg fits in hole (via adapter): Yes
```

### Adapter模式的分析
优点
1. 提高兼容性：解决接口不兼容的问题，复用已有类。
2. 分离职责：客户端与被适配类解耦，使用统一接口。
3. 灵活性：可以动态调整适配逻辑，不影响原始类的实现。
缺点
1. 代码复杂性增加：引入了额外的适配器类。
2. 性能开销：适配过程中可能有额外的处理逻辑。

### Adapter模式的实际应用
标准接口转换：如 C++ STL 的 std::vector 和遗留数组代码的适配。
第三方库集成：对接第三方 API 时，通过适配器将接口转换为符合项目需求的形式。
GUI 框架：适配不同平台的事件处理机制。
通过适配器模式，系统可以更灵活地兼容不同接口，提高代码的复用性和扩展性。

