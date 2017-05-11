/******************************************************************************
* Item.h - 条目类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   所有条目部件的基类
*
* Author: Zhang Fan@2016/07/26
*
* Author: Zhang Fan@2016/07/29
*
* modification history:
*   1.增加对回车，回退和字符输入的响应函数
*
******************************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Item: public Object
{
    protected:
        int id; //条目ID

    public:
        Item(int x, int y, string name, int id);
        Item();
        virtual ~Item();

        virtual void draw();
        virtual void update() = 0;
        virtual bool moveLeft() = 0;    //右移事件响应函数
        virtual bool moveRight() = 0;   //左移事件响应函数
        virtual bool enter() = 0;   //回车事件响应函数
        virtual bool input(int ch) = 0;   //输入事件响应函数
        virtual bool backspace() = 0;   //退格事件响应函数
};

#endif
