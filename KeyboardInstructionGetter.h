/******************************************************************************
* KeyboardInstructionGetter.h - 通过键盘获取控制指令的类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   开启单独的一个线程，负责通过键盘获取控制指令，继承至控制指令获取类，实现了run()函数
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*
*
******************************************************************************/
#ifndef KEYBOARDINSTRUCTIONGETTER_H
#define KEYBOARDINSTRUCTIONGETTER_H

#include "InstructionGetter.h"

class KeyboardInstructionGetter : public InstructionGetter
{
    private:
        void run(); //实现

    public:
        KeyboardInstructionGetter();
};

#endif // KEYBOARDINSTRUCTIONGETTER_H
