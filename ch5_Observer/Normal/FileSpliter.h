#ifndef FileSpliter_H
#define FileSpliter_H
#include "../../common.h"

class FileSpliter
{
private:
    /* data */
    string filePath;
    int number;
public:
    FileSpliter(string filePath, int nubmer);
    void split(){};
    ~FileSpliter();
};

FileSpliter::FileSpliter(string filePath, int nubmer)
{   
    filePath = filePath;
    number = number;
}

void FileSpliter::split(){
    cout << "I am Splitting the" << filePath << "to" << number << "Part" << endl;
    for (int i = 0; i <= number; i++){
        cout << i << "/" << number << "..." << endl;
    }
}

FileSpliter::~FileSpliter()
{
}


#endif