### Facade（门面模式）简介
门面模式（Facade Pattern） 是一种结构型设计模式，用于为复杂的子系统提供一个简化的统一接口，使客户端可以通过这个接口访问子系统的功能，而无需了解子系统的具体实现。

#### 核心思想：
封装复杂性：隐藏子系统的实现细节。
简化接口：提供一个简单的接口供外部使用。

#### 门面模式的特点
简化客户端接口：将多个子系统的功能封装到一个统一的接口中，客户端不需要直接与子系统交互。
降低耦合性：客户端与子系统之间的依赖被降低，只需依赖门面类。
灵活扩展：子系统可以独立扩展，而无需修改客户端代码。


#### 门面模式的结构：UML 类图
Facade（门面类）：提供统一的接口，调用子系统中的类完成实际工作。
Subsystem Classes（子系统类）：执行具体功能，门面类将它们组合起来。
Client（客户端）：通过门面类与子系统交互。

### C++ 实现示例
场景：家庭影院
假设我们有一个家庭影院系统，包含以下子系统：

DVDPlayer：控制 DVD 播放。
Amplifier：控制音响。
Projector：控制投影仪。
Light：控制灯光。
我们通过门面类 HomeTheaterFacade 简化它们的调用。

子系统类
```cpp
#include <iostream>
using namespace std;

// DVD播放器
class DVDPlayer {
public:
    void on() { cout << "DVD Player is ON." << endl; }
    void play(string movie) { cout << "Playing movie: " << movie << endl; }
    void off() { cout << "DVD Player is OFF." << endl; }
};

// 音响
class Amplifier {
public:
    void on() { cout << "Amplifier is ON." << endl; }
    void setVolume(int level) { cout << "Volume set to " << level << endl; }
    void off() { cout << "Amplifier is OFF." << endl; }
};

// 投影仪
class Projector {
public:
    void on() { cout << "Projector is ON." << endl; }
    void setInput(string input) { cout << "Projector input set to: " << input << endl; }
    void off() { cout << "Projector is OFF." << endl; }
};

// 灯光
class Light {
public:
    void dim(int level) { cout << "Lights dimmed to " << level << "%" << endl; }
    void on() { cout << "Lights are ON." << endl; }
};

```

门面类
```cpp
class HomeTheaterFacade {
private:
    DVDPlayer* dvdPlayer;
    Amplifier* amplifier;
    Projector* projector;
    Light* light;

public:
    HomeTheaterFacade(DVDPlayer* dvd, Amplifier* amp, Projector* proj, Light* light)
        : dvdPlayer(dvd), amplifier(amp), projector(proj), light(light) {}

    void watchMovie(string movie) {
        cout << "Preparing to watch a movie..." << endl;
        light->dim(20);
        projector->on();
        projector->setInput("DVD");
        amplifier->on();
        amplifier->setVolume(10);
        dvdPlayer->on();
        dvdPlayer->play(movie);
        cout << "Enjoy your movie!" << endl;
    }

    void endMovie() {
        cout << "Shutting down the home theater..." << endl;
        dvdPlayer->off();
        amplifier->off();
        projector->off();
        light->on();
    }
};
```

客户端代码
```cpp
int main() {
    // 创建子系统对象
    DVDPlayer dvd;
    Amplifier amp;
    Projector proj;
    Light light;

    // 创建门面对象
    HomeTheaterFacade homeTheater(&dvd, &amp, &proj, &light);

    // 客户端通过门面接口操作子系统
    homeTheater.watchMovie("Inception");
    cout << endl;
    homeTheater.endMovie();

    return 0;
}
```