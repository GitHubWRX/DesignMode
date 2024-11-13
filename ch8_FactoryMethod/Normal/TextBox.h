#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "../../common.h"

class TextBox
{
private:
    /* data */
    string text;
public:
    TextBox(/* args */);
    string getText(){
        return text;
    }
    ~TextBox();
};

TextBox::TextBox(/* args */)
{
}

TextBox::~TextBox()
{
}



#endif