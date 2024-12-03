#include "Components.h"

int main() {
    // 创建子系统对象
    DVDPlayer dvd;
    Amplifier amp;
    Projector proj;
    Light light;

    // 客户端手动调用子系统方法
    cout << "Preparing to watch a movie..." << endl;
    light.dim(20);                  // 调节灯光
    proj.on();                      // 打开投影仪
    proj.setInput("DVD");           // 设置投影仪输入
    amp.on();                       // 打开音响
    amp.setVolume(10);              // 设置音量
    dvd.on();                       // 打开DVD
    dvd.play("Inception");          // 播放电影
    cout << "Enjoy your movie!" << endl;

    cout << endl;

    // 手动关闭系统
    cout << "Shutting down the home theater..." << endl;
    dvd.off();                      // 关闭DVD
    amp.off();                      // 关闭音响
    proj.off();                     // 关闭投影仪
    light.on();                     // 打开灯光

    return 0;
}

