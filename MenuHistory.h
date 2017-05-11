/******************************************************************************
* MenuHistory.h - 菜单历史记录类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   保存程序当前菜单信息及历史菜单信息，用来回退
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
#ifndef MENUHISTORY_H
#define MENUHISTORY_H

#include <stack>

using std::stack;
class Menu;

/*
 * 菜单信息，包括菜单对象和菜单所选择的条目号
 */
struct MenuRecord
{
        Menu *menu = nullptr;
        unsigned int selectedItem = 0;
        bool isEditing = false;
};


class MenuHistory
{
    private:
        stack<MenuRecord *> *menuHistory = nullptr; //历史菜单记录
        MenuRecord *currentMenu = nullptr;  //当前菜单信息

        MenuHistory();
        MenuHistory(const MenuHistory&) = delete;
        MenuHistory &operator=(const MenuHistory&) = delete;
        ~MenuHistory();

        static MenuHistory *instance;

        class CGarbo //它的唯一工作就是在析构函数中删除MenuHistory的实例
        {
            public:
                ~CGarbo()
                {
                    if(MenuHistory::instance)
                    {
                        delete MenuHistory::instance->menuHistory;
                        delete MenuHistory::instance->currentMenu;
                        delete MenuHistory::instance;
                    }
                }
        };
        static CGarbo garbo; //定义一个静态成员，程序结束时，系统会自动调用它的析构函数

    public:
        static MenuHistory *getInstance();  //唯一的全局接入点

        bool isEmpty() const;   //历史菜单记录是否为空
        MenuRecord* getTop();   //获取历史菜单记录中最近的菜单信息
        bool removeTop();   //移除历史菜单记录最近的一个
        bool removeCurrentMenu();   //删除当前菜单信息
        void addHistory(MenuRecord *menuRecord);    //添加历史菜单记录
        MenuRecord *getCurrentMenu() const; //获取当前菜单信息
        void setCurrentMenu(MenuRecord *menuRecord);    //设置当前菜单
};

#endif // MENUHISTORY_H
