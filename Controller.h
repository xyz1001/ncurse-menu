/******************************************************************************
* Controller.h - 操作控制类:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   负责提供对不同指令的响应函数，为静态函数
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*   1.添加退出时的对话框逻辑
*
******************************************************************************/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "InstructionGetter.h"

class Menu;
using std::vector;

class Controller
{
    private:
        vector<InstructionGetter *> instructionGetterVector;

        Controller();
        Controller(const Controller&) {}
        Controller &operator=(const Controller&) {}
        ~Controller();

        static Controller *instance; //单例

        class CGarbo //它的唯一工作就是在析构函数中删除IndexMenu的实例
        {
            public:
                ~CGarbo()
                {
                    if(Controller::instance)
                        delete Controller::instance;
                }
        };
        static CGarbo garbo; //定义一个静态成员，程序结束时，系统会自动调用它的析构函数

        static int getType(int instruction);  //获取指令对应的操作码，0:无效指令，1:上移，2:下移，3:左移，4:右移，5:回退

    public:
        bool operate(int instruction); //根据指令执行操作
        bool start(Menu *menu);    //启动程序
        bool addInstructionGetter(InstructionGetter *instructionGetter);
        static Controller *getInstance();    //唯一的全局接入点
};

#endif // CONTROLLER_H
