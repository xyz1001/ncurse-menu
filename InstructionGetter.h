/******************************************************************************
* InstructionGetter.h - 指令获取类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   负责获取不同渠道来的控制指令，供具体指令传输方式类实现
*
* Author: Zhang Fan@2016/07/29
*
* modification history:
*
*
******************************************************************************/
#ifndef INSTRUCTIONGETTER_H
#define INSTRUCTIONGETTER_H

#include <pthread.h>

class InstructionGetter
{
    private:
        static void *startThread(void *arg);    //中间函数，负责链接start()函数中的pthread_create函数和run()函数

    protected:
        pthread_t threadID; //线程ID
        virtual void run() = 0; //执行函数

    public:
        InstructionGetter();
        virtual ~InstructionGetter();
        bool start();   //开始函数
};

#endif // INSTRUCTIONGETTER_H
