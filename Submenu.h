/******************************************************************************
* Submenu.h - 子菜单类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   子菜单，可存在多个
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*
*
******************************************************************************/
#ifndef SUBMENU_H
#define SUBMENU_H

#include "Menu.h"

class Submenu : public Menu
{
    public:
        Submenu();
        Submenu(string name);
        ~Submenu();
};

#endif // SUBMENU_H
