/******************************************************************************
* BoolItem.h - 属性为布尔值的条目类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   属性为布尔值的条目类，左移右移切换TRUE/FALSE
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*
*
******************************************************************************/
#ifndef BOOLITEM_H
#define BOOLITEM_H

#include "Item.h"

class BoolItem : public Item
{
    private:
        bool value; //布尔值

    public:
        BoolItem();
        BoolItem(int x, int y, string name, int id, bool value = false);

        void draw();
        void update();
        bool moveLeft();
        bool moveRight();
        bool enter();
        bool backspace();
        bool input(int ch);
};

#endif // BOOLITEM_H
