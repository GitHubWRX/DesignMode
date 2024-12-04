#include "FileProxy.h"

int main(){
    // 有权限的场景
    FileProxy fileProxy1("testFileNamePass", true);
    fileProxy1.read();
    // 无权限的场景
    FileProxy fileProxy2("testFileNameDeny", false);
    fileProxy2.read();
}