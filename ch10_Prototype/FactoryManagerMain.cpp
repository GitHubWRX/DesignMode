#include "FactoryManager.h"
#include "FactoryManagerMainForm.cpp"

int main() {
    FactoryManager factoryManager;

    try {
        // 动态选择 binary 工厂
        mainForm binaryForm(&factoryManager, "binary");
        binaryForm.Button1_Click();

        // 动态选择 picture 工厂
        mainForm pictureForm(&factoryManager, "picture");
        pictureForm.Button1_Click();

        // 动态选择 text 工厂
        mainForm textForm(&factoryManager, "text");
        textForm.Button1_Click();

        // 动态选择 vedio 工厂
        mainForm vedioForm(&factoryManager, "vedio");
        vedioForm.Button1_Click();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
