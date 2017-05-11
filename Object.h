/******************************************************************************
* Object.h - 部件类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   所有部件的基类
*
* Author: Zhang Fan@2016/07/28
*
* modification history:
*   1.新增更新函数update()，部件有变化时只重绘变化的部分
*
******************************************************************************/
#ifndef OBJECT_H
#define OBJECT_H

#include <curses.h>
#include <string>
#include <iostream>
#include "Parameter.h"

using std::string;

class Object
{
    protected:
        string name;    //部件名
        int x;  //部件右上角的横坐标
        int y;  //部件右上角的纵坐标

    public:
        Object();
        Object(int x, int y, string name);
        virtual ~Object();

        int getX() const;
        int getY() const;
        string getName() const;

        virtual void draw() = 0;    //部件绘制函数
        virtual void update() = 0;  //部件更新函数
};

#endif
