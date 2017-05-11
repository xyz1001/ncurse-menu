/******************************************************************************
* Subumenu.h - 属性为子菜单的条目类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   属性为子菜单的条目类，右移显示子菜单，左移无效果
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*
*
******************************************************************************/
#ifndef SUBMENUITEM_H
#define SUBMENUITEM_H

#include "Submenu.h"
#include "Item.h"

class SubmenuItem : public Item
{
    private:
        Menu *submenu;  //子菜单指针

    public:
        SubmenuItem();
        SubmenuItem(int x, int y, string name, int id, Menu *submenu);
        ~SubmenuItem();

        void draw();
        void update();
        bool moveLeft();
        bool moveRight();
        bool enter();
        bool backspace();
        bool input(int ch);

};

#endif // SUBMENUITEM_H
