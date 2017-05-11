#include "FIFOInstructionGetter.h"
#include "Controller.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FIFO "my_fifo"  //命名管道名

FIFOInstructionGetter::FIFOInstructionGetter()
{

}

void FIFOInstructionGetter::run()
{
    /*
     * 判断命名管道是否存在，若不存在则创建
     */
    if(access(FIFO, F_OK) == -1)
    {
        mkfifo(FIFO,0777);
    }
    int fd = open(FIFO, O_RDONLY|O_NONBLOCK);   //打开命名管道

    char buff[100]; //指令缓冲流
    memset(buff, '\0', 100);    //指令流置空
    int num = 0;    //读取的指令数

    while(1)
    {
        //读取管道中的指令，单次读取上限100个
        if ((num = read(fd, buff, 100)) > 0)
        {
            //依次执行读取的指令流
            for (unsigned int i=0; i<strlen(buff); ++i)
            {
                char instruction = buff[i];
                Controller::getInstance()->operate(instruction);
                buff[i] = '\0'; //清楚已执行的指令，防止后续未覆盖时再次执行
            }
        }
        else
        {
            usleep(1000);   //睡眠一毫秒，防止无输入时无限空循环占用大量CPU
        }
    }
}
