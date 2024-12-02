#include "FontFactory.h"

/// @brief FlyWeight其实就是搞了个字典存储通用的对象
/// @return 
int main() {
    FontFactory factory;

    // 创建多个 Font 对象
    Font* fontA1 = factory.GetFont("Arial");
    Font* fontA2 = factory.GetFont("Arial");
    Font* fontB = factory.GetFont("Times New Roman");

    // 显示 Font 信息
    fontA1->display();
    fontA2->display();
    fontB->display();

    // 验证共享对象
    if (fontA1 == fontA2) {
        cout << "fontA1 and fontA2 are the same instance (shared)." << endl;
    } else {
        cout << "fontA1 and fontA2 are different instances (not shared)." << endl;
    }

    return 0;
}
