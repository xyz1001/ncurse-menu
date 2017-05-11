#include "InstructionGetter.h"

InstructionGetter::InstructionGetter()
{

}

InstructionGetter::~InstructionGetter()
{

}

bool InstructionGetter::start()
{
    if (pthread_create(&threadID, NULL, startThread, (void *)this) == 0) //执行keyboardControl函数
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * 由于pthread_create函数第三个参数的函数形参必须是(void *)类型，而类的成员函数默认包含一个指向类对象的this指针，
 * 导致类的成员函数无法作为第三个参数传入，因此需要一个静态函数作为链接，将this指针作为参数传入后再调用run()函数
 */
void *InstructionGetter::startThread(void *arg)
{
    InstructionGetter *thread = (InstructionGetter *)arg;
    thread->run();
}
