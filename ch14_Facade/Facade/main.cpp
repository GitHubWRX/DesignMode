#include "Facader.h"

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
