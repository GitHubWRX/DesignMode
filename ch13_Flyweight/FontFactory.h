#ifndef FACTORYFONT_H
#define FACTORYFONT_H
#include <mutex>
#include "Font.h"

class FontFactory
{
private:
    // 这里不存储Font实例，而是存储器地址节约内存，要注意释放时的删除
    unordered_map<string, Font*> fontPool;
    std::mutex mtx; // 用于线程同步
public:
    FontFactory(/* args */);
    Font* GetFont(const string& key){
        std::lock_guard<std::mutex> lock(mtx); // 加锁
        unordered_map<string, Font*>::iterator item = fontPool.find(key);
        if (item != fontPool.end()){
            return fontPool[key];
        }else{
            Font* newFont = new Font(key);
            fontPool[key] = newFont;
            return newFont;
        }
    }
    ~FontFactory();
};

FontFactory::FontFactory(/* args */)
{
}

FontFactory::~FontFactory()
{
    for(auto font : fontPool){
        delete font.second;
    }
}

#endif