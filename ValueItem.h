/******************************************************************************
* ValueItem.h - 属性为数值的条目类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   属性为整形数值的条目类，左移右移可改变其数值大小
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*
*
******************************************************************************/
#ifndef VALUEITEM_H
#define VALUEITEM_H

#include <string>
#include "Item.h"

using std::string;

class ValueItem: public Item
{
    private:
        int value;  //当前值
        int minValue;   //最小值
        int maxValue;   //最大值

    public:
        ValueItem();
        ValueItem(int x, int y, string name, int id, int minValue, int maxValue, int value = 0);

        void draw();
        void update();
        bool moveLeft();
        bool moveRight();
        bool enter();
        bool backspace();
        bool input(int ch);

};

#endif
