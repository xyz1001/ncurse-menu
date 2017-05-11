/******************************************************************************
* Menu.h - 菜单类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   所有菜单部件的基类
*
* Author: Zhang Fan@2016/07/28
*
* modification history:
*   1.新增steps变量成员，保存移动步长
*   2.新增update()函数，移动光标时只重绘光标
*   3.修改moveUp()和moveDown()函数，加入形参int steps = 1，实现单次多步移动
*
******************************************************************************/
#ifndef MENU_H
#define MENU_H

#include "Item.h"
#include "Object.h"
#include <string>
#include <vector>
#include <stack>
#include "MenuHistory.h"

using std::string;
using std::vector;

class Menu : public Object
{
    protected:
        vector<Item*> *items = nullptr; //条目数组，保存该菜单下所有条目
        unsigned int currentSelectedItem = 1;
        int steps = 1;  //单次移动的距离

    public:
        Menu();
        Menu(string name);
        virtual ~Menu();

        void setCurrentSelectedItem(int currentSelectedItem) {this->currentSelectedItem = currentSelectedItem;}
        void setName(string name) {this->name = name;}
        vector<Item*> *getItems() const {return items;}
        string getName() const {return name;}
        int getCurrentSelectedItem() const {return currentSelectedItem;}


        virtual void draw();
        virtual void update();
        virtual void addItem(Item *item);   //添加条目
        virtual bool moveUp(int steps = 1); //上移事件响应函数
        virtual bool moveDown(int steps = 1);   //下移事件响应函数
        virtual bool backspace();   //回退事件响应函数
};

#endif // MENU_H
