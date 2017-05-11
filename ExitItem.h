/******************************************************************************
* ExitItem.h - 退出程序条目类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   当选中该条目时退出程序
*
* Author: Zhang Fan@2016/07/29
*
* modification history:
*
*
******************************************************************************/
#ifndef EXITITEM_H
#define EXITITEM_H

#include "Item.h"

class ExitItem : public Item
{
    public:
        ExitItem();
        ExitItem(int x, int y, int id);

        void draw();
        void update();
        bool moveLeft();
        bool moveRight();
        bool enter();
        bool backspace();
        bool input(int ch);
};

#endif // EXITITEM_H
