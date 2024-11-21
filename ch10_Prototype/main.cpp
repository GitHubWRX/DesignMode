#include "BinarySpliterFactory.h"
#include "PictureSpliterFactory.h"
#include "TextSpliterFactory.h"
#include "VedioSpliterFactory.h"
#include "mainForm.cpp"

int main() {
    // 使用 BinarySpliterFactory
    SpliterFactory* binaryFactory = new BinarySpliterFactory();
    mainForm binaryForm(binaryFactory);
    binaryForm.Button1_Click();

    // 使用 PictureSpliterFactory
    SpliterFactory* pictureFactory = new PictureSpliterFactory();
    mainForm pictureForm(pictureFactory);
    pictureForm.Button1_Click();

    return 0;
}
