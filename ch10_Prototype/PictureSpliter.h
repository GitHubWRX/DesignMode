#ifndef PictureSpliter_H
#define PictureSpliter_H

#include "ISpliter.h"

class PictureSpliter : public ISpliter
{
private:
    /* data */
public:
    PictureSpliter(/* args */);
    virtual void split(){
        cout << "I am a PictureSpliter, I am splitering Picture File" << endl;
    }
    virtual PictureSpliter* clone(){
        return new PictureSpliter(*this);
    }
    virtual ~PictureSpliter();
};

PictureSpliter::PictureSpliter(/* args */)
{
}

PictureSpliter::~PictureSpliter()
{
}

#endif