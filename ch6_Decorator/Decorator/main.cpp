#include "FileStream.h"
#include "MemoryStream.h"
#include "BufferedStream.h"
#include "CryptoStream.h"
#include "BufferedStream.h"

int main(){
    // 对于多态运行时来说，不论是new还是栈对象，在使用值转换时都会发生
    // 使用指针进行转化基类，不会发生对象切片
    Stream* fileStream = new FileStream();
    Stream* bufferdStream = new BufferdStream(fileStream);
    Stream* cryptoStream = new CryptoStream(fileStream);
    Stream* bufferdCryptoStream = new BufferdStream(cryptoStream);
    Stream* cryptoBufferdStream = new CryptoStream(bufferdStream);
    
    delete cryptoBufferdStream;
    delete bufferdCryptoStream;
    delete cryptoStream;
    delete bufferdStream;
    delete fileStream;
}
