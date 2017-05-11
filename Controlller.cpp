#include "Controller.h"
#include <curses.h>
#include <stdlib.h>
#include "MenuHistory.h"
#include "Menu.h"
#include "Parameter.h"
#include <string>
//#include "QuitBox.h"
#include <cctype>
#include "FIFOInstructionGetter.h"
#include "KeyboardInstructionGetter.h"

Controller* Controller::instance = nullptr; //单例对象必须定义

Controller::Controller()
{

}

Controller::~Controller()
{
    for(auto &i:instructionGetterVector)
    {
        delete i;
    }
}

Controller *Controller::getInstance()
{
    /*
     * 懒汉模式，以时间换空间
     */
    if(instance)
        return instance;

    instance = new Controller();
    return instance;
}

/*
 * modeified Zhang Fan@2016/07/29
 * 增加了对Enter和可显示字符（大小写字母，数字和下划线）的处理
 */
int Controller::getType(int instruction)
{
    switch (instruction)
    {
        /*
         * 向上键返回1
         */
        case KEY_UP:
        case 0x01:
            return 1;
            /*
         * 向下键返回2
         */
        case KEY_DOWN:
        case 0x02:
            return 2;
            //    case 'a':
            /*
         * 向左键返回3
         */
        case KEY_LEFT:
        case 0x03:
            return 3;
            /*
         * 向右键返回4
         */
        case KEY_RIGHT:
        case 0x04:
            return 4;
            /*
         * 退格键返回5
         */
        case KEY_BACKSPACE:
        case 0x05:
            return 5;
            /*
         * 回车键返回6
         */
        case KEY_ENTER:
        case 10:
        case 0x06:
            return 6;
        default:
            break;
    }

    /*
     * 大小写字母，数字和下划线直接返回其ASCII码
     */
    if(isalnum(instruction) || instruction == '_')
    {
        return instruction;
    }

    /*
     * 其他符号返回0
     */
    return 0;
}

bool Controller::operate(int instruction)
{
    MenuHistory *menuHistory = MenuHistory::getInstance();
    MenuRecord *currentMenu = menuHistory->getCurrentMenu();

    int code = getType(instruction);

    switch (code)
    {
        case 1:
            if(!(currentMenu->isEditing))   //非编辑状态下菜单响应上移事件
            {
                currentMenu->menu->moveUp();
            }
            break;
        case 2:
            if(!(currentMenu->isEditing))   //非编辑状态下菜单响应下移事件
            {
                currentMenu->menu->moveDown();
            }
            break;
        case 3:
            currentMenu->menu->getItems()->at(currentMenu->selectedItem-1)->moveLeft(); //当前所选条目响应左移事件
            break;
        case 4:
            currentMenu->menu->getItems()->at(currentMenu->selectedItem-1)->moveRight();  //当前所选条目响应右移事件
            break;
        case 5:
            if(currentMenu->isEditing)  //编辑状态下由条目响应退格事件
            {
                currentMenu->menu->getItems()->at(currentMenu->selectedItem-1)->backspace();
            }
            else    //非编辑状态下由菜单响应退格事件
            {
                currentMenu->menu->backspace();
            }
            break;
        case 6:
            if(currentMenu->menu->getItems()->at(currentMenu->selectedItem - 1)->enter())  //条目响应回车事件，进入/退出编辑状态
            {
                currentMenu->isEditing = !currentMenu->isEditing;   //切换编辑状态/非编辑状态
            }
            break;
        default:
            if(currentMenu->isEditing && code != 0) //处于编辑状态时响应字符输入
            {
                currentMenu->menu->getItems()->at(currentMenu->selectedItem - 1)->input(code);
            }
            break;
    }



    return true;
}

bool Controller::start(Menu *menu)
{
    initscr();  //初始化窗口

    cbreak();   //设置接受除"Del"和"Ctrl"以外的控制键字符输入
    raw();  //禁止行缓冲
    curs_set(0);    //设置光标不可见
    keypad(stdscr, TRUE);   //开启功能键响应模式
    noecho();   //当执行getch()函数的时候关闭键盘回显

    /*
     * 创建主菜单并将其设为当前菜单
     */
    MenuRecord *currentMenu = new MenuRecord;
    currentMenu->menu = menu;
    currentMenu->selectedItem = 1;  //设置当前指向条目1
    MenuHistory::getInstance()->setCurrentMenu(currentMenu);
    currentMenu->menu->draw();  //绘制菜单

    for(auto &i:instructionGetterVector)
    {
        i->start();
    }
}

bool Controller::addInstructionGetter(InstructionGetter *instructionGetter)
{
    instructionGetterVector.push_back(instructionGetter);
}
