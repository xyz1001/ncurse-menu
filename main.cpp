/******************************************************************************
* main.cpp - 菜单程序:
*
* Copyright (c) 20016-2016  Zix
*
* DESCRIPTION: -
*   一个选项菜单程序，可以同时受键盘和其他进程通过my_fifo命名管道（FIFO）发送过来的指令进行控制
*
* Author: Zhang Fan@2016/07/26
*
* modification history:
*   1.完成UI界面的基本功能，只能通过键盘WASDQ键控制
*
*
* Author: Zhang Fan@2016/07/27
*
* modification history:
*   1.添加键盘功能键控制及命名管道指令控制且可以同时响应
*   2.修复了FIFO指令控制响应速度过慢的BUG
*
*
* Author: Zhang Fan@2016/07/28
*
* modification history:
*   1.新增退出提示框
*   2.修复了内存泄漏问题
*   3.修复了CPU占用率过高的问题
*   4.对部分重复代码进行了重构
*   5.移除了部分无用的代码
*
* Author: Zhang Fan@2016/07/29
*
* modification history:
*   1.新增输入条目类(InputItem)和退出条目类(ExitItem)
*   2.光标可循环移动
*   3.指令获取提取成一系列类，继承InstructionGetter类，子类只需重新实现父类的run()函数
******************************************************************************/

#include <curses.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <unistd.h>
#include "Item.h"
#include "ValueItem.h"
#include "BoolItem.h"
#include "SubmenuItem.h"
#include "Menu.h"
#include "Submenu.h"
#include "IndexMenu.h"
#include "MenuHistory.h"
#include "Controller.h"
#include "InstructionGetter.h"
#include "KeyboardInstructionGetter.h"
#include "FIFOInstructionGetter.h"
#include "ExitItem.h"
#include "InputItem.h"

using std::cin;

Menu *createMenu()
{
    //创建Panel Setting子菜单及其条目
    Item *panelOnItem = new BoolItem(1, 0, "Panel On", 1);
    Item *backlightOnItem = new BoolItem(2, 0, "Backlight On", 2);
    Menu *panelSettingsMenu = new Submenu("Panel Settings");
    panelSettingsMenu->addItem(panelOnItem);
    panelSettingsMenu->addItem(backlightOnItem);

    //创建Picture Settings子菜单及其条目
    Item *brightnessItem = new ValueItem(1, 0, "Brightness", 1, 0, 100, 50);
    Item *contrastItem = new ValueItem(2, 0, "Contrast", 2, 0, 100, 50);
    Menu *pictureSettingsMenu = new Submenu("Picture Settings");
    pictureSettingsMenu->addItem(brightnessItem);
    pictureSettingsMenu->addItem(contrastItem);

    //创建Sound Settings子菜单及其条目
    Item *trebleItem = new ValueItem(1, 0, "Treble", 1, 0, 64, 32);
    Item *bassItem = new ValueItem(2, 0, "Bass", 2, 0, 32, 16);
    Item *balanceItem = new ValueItem(3, 0, "Balance", 3, -50, 50, 0);
    Menu *soundSettingsMenu = new Submenu("Sound Settings");
    soundSettingsMenu->addItem(trebleItem);
    soundSettingsMenu->addItem(bassItem);
    soundSettingsMenu->addItem(balanceItem);

    //创建主菜单及其条目
    Item *panelSettingsItem = new SubmenuItem(1, 0, "Panel Settings", 1, panelSettingsMenu);
    Item *pictureSettingsItem = new SubmenuItem(2, 0, "Picture Settings", 2, pictureSettingsMenu);
    Item *soundSettingsItem = new SubmenuItem(3, 0, "Sound Settings", 3, soundSettingsMenu);
    Item *debugOnItem = new BoolItem(4, 0, "Debug On", 4, true);
    Item *BoolTestItem1 = new BoolItem(5, 0, "Test1", 5, true);
    Item *ValueTestItem1 = new ValueItem(6, 0, "Test2", 6, 0, 500, 200);
    Item *BoolTestItem2 = new BoolItem(7, 0, "Test3", 7, false);
    Item *ValueTestItem2 = new ValueItem(8, 0, "Test4", 8, -1000, 0, -234);
    Item *BoolTestItem3 = new BoolItem(9, 0, "Test5", 9, true);

    Item *inputItem = new InputItem(10, 0, "Input", 10, "123");
    Item *exitItem = new ExitItem(11, 0, 11);
    Menu *indexMenu = IndexMenu::getInstance();
    indexMenu->addItem(panelSettingsItem);
    indexMenu->addItem(pictureSettingsItem);
    indexMenu->addItem(soundSettingsItem);
    indexMenu->addItem(debugOnItem);
    indexMenu->addItem(BoolTestItem1);
    indexMenu->addItem(ValueTestItem1);
    indexMenu->addItem(BoolTestItem2);
    indexMenu->addItem(ValueTestItem2);
    indexMenu->addItem(BoolTestItem3);

    indexMenu->addItem(inputItem);
    indexMenu->addItem(exitItem);

    return indexMenu;
}

int main()
{

    InstructionGetter *keyboardInstructionGetter = new KeyboardInstructionGetter();
    InstructionGetter *fifoInstructionGetter = new FIFOInstructionGetter();
    Controller::getInstance()->addInstructionGetter(keyboardInstructionGetter);
    Controller::getInstance()->addInstructionGetter(fifoInstructionGetter);

    Controller::getInstance()->start(createMenu());

    /*
     * 无限循环保证主线程不退出
     */
    while(MenuHistory::getInstance()->getCurrentMenu() != nullptr)
    {
        usleep(1000);   //减慢循环速度，降低CPU占用率
    }

    delete keyboardInstructionGetter;
    delete fifoInstructionGetter;

    //getch();  //防止闪退
    endwin();   //关闭窗口

    return 0;
}
