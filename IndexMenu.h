/******************************************************************************
* IndexMenu.h - 主菜单菜单类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   程序的主菜单，采用单例模式
*
* Author: Zhang Fan@2016/07/27
*
* modification history:
*   1.添加私有的复制构造函数和赋值函数，防止对象被复制
*
* Author: Zhang Fan@2016/07/28
*
* modification history:
*   1.添加内部类，用来析构对象，防止内存泄漏
******************************************************************************/
#ifndef INDEXMENU_H
#define INDEXMENU_H

#include "Menu.h"

class IndexMenu : public Menu
{
    private:
        /*
     * 屏蔽构造函数，复制构造函数和赋值函数
     */
        IndexMenu();
        IndexMenu(string name);
        IndexMenu(const IndexMenu&) = delete;
        IndexMenu &operator=(const IndexMenu&) = delete;
        ~IndexMenu();

        static IndexMenu *instance; //单例

        class CGarbo //它的唯一工作就是在析构函数中删除IndexMenu的实例
        {
            public:
                ~CGarbo()
                {
                    if(IndexMenu::instance)
                        delete IndexMenu::instance;
                }
        };
        static CGarbo garbo; //定义一个静态成员，程序结束时，系统会自动调用它的析构函数

    public:
        static IndexMenu *getInstance();    //唯一的全局接入点
};

#endif // INDEXMENU_H
