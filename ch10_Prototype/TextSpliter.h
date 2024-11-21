#ifndef TextSpliter_H
#define TextSpliter_H

#include "ISpliter.h"

class TextSpliter : public ISpliter
{
private:
    /* data */
public:
    TextSpliter(/* args */);
    virtual void split(){
        cout << "I am a TextSpliter, I am splitering Text File" << endl;
    }
    virtual TextSpliter* clone(){
        return new TextSpliter(*this);
    }
    virtual ~TextSpliter();
};

TextSpliter::TextSpliter(/* args */)
{
}

TextSpliter::~TextSpliter()
{
}

#endif