/******************************************************************************
* InputItem.h - 输入条目类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   可以修改条目后的值名称，按下回车进入编辑状态，再次按下退出编辑状态，左右键移动光标，退格键删除最后一个字符，
*   可输入的字符包括大小写字母，数字和下划线
*
* Author: Zhang Fan@2016/07/29
*
* modification history:
*
*
******************************************************************************/
#ifndef INPUTITEM_H
#define INPUTITEM_H

#include "Item.h"

class InputItem : public Item
{
    private:
        char inputName[50]; //输入的名称
        bool isEditing = false; //是否为编辑状态
        unsigned int currentEditPos = 0;    //当前光标所在位置
    public:
        InputItem();
        InputItem(int x, int y, string name, int id, const char *inputName);

        void draw();
        void update();
        bool moveLeft();
        bool moveRight();
        bool enter();
        bool backspace();
        bool input(int ch);
};

#endif // INPUTITEM_H
