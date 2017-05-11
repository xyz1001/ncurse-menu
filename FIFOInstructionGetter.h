/******************************************************************************
* FIFOInstructionGetter.h - 通过命名管道获取控制指令的类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   开启单独的一个线程，负责通过命名管道获取控制指令，继承至控制指令获取类，实现了run()函数
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*
*
******************************************************************************/
#ifndef FIFOINSTRUCTIONGETTER_H
#define FIFOINSTRUCTIONGETTER_H

#include "InstructionGetter.h"

class FIFOInstructionGetter : public InstructionGetter
{
    private:
        void run(); //实现

    public:
        FIFOInstructionGetter();
};

#endif // FIFOINSTRUCTIONGETTER_H
