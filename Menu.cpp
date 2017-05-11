#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(string name):Object(0, 0, name)
{
    this->items = new vector<Item *>;
}

Menu::~Menu()
{
    /*
     * 释放菜单的条目列表中的条目对象
     */
    for(auto &i:(*items))
    {
        delete i;
    }
    delete items;   //释放条目列表
}

void Menu::draw()
{
    /*
     * 绘制菜单名称
     */
    int titlePos = (TOTAL_LENGTH - name.size())/2;  //计算菜单名居中绘制的位置
    move(0, titlePos);
    printw("%s", name.c_str());

    /*
     * 依次调用条目的绘制函数绘制条目
     */
    for(auto &i:*items)
    {
        i->draw();
    }

    /*
     * 绘制当前选择的菜单条目前的星号
     */
    move(MenuHistory::getInstance()->getCurrentMenu()->selectedItem, COLUMN1);
    printw("*");
    move(MenuHistory::getInstance()->getCurrentMenu()->selectedItem, COLUMN1);  //移动光标至星号位置
    refresh();
}

void Menu::update()
{
    /*
     * 删除当前所选行的星号，取消选中
     */
    move(MenuHistory::getInstance()->getCurrentMenu()->selectedItem, COLUMN1);
    printw(" ");


    (MenuHistory::getInstance()->getCurrentMenu()->selectedItem)+=steps;    //修改菜单历史对象中的当前菜单选中的行号

    /*
     * 判断当前条目号是否超过上下边界，如果是则设置为1或条目总数
     */
    if (MenuHistory::getInstance()->getCurrentMenu()->selectedItem < 1)
    {
        MenuHistory::getInstance()->getCurrentMenu()->selectedItem = items->size();
    }
    else if (MenuHistory::getInstance()->getCurrentMenu()->selectedItem > items->size())
    {
        MenuHistory::getInstance()->getCurrentMenu()->selectedItem = 1;
    }

    if(MenuHistory::getInstance()->getCurrentMenu()->menu->getItems()->at(MenuHistory::getInstance()->getCurrentMenu()->selectedItem - 1)->getName() == "Exit")
    {
        endwin();
        exit(0);
    }

    /*
     * 在待选中行前添加星号，标记选中状态
     */
    move(MenuHistory::getInstance()->getCurrentMenu()->selectedItem, COLUMN1);
    printw("*");
    move(MenuHistory::getInstance()->getCurrentMenu()->selectedItem, COLUMN1);

    refresh();
}

void Menu::addItem(Item *item)
{
    items->push_back(item); //存入条目列表中
}

bool Menu::moveUp(int steps)
{
//    /*
//     * 已到达菜单的第一条条目
//     */
//    if(MenuHistory::getInstance()->getCurrentMenu()->selectedItem == 1)
//        return false;

    this->steps = -steps;   //设置移动距离，向上为负
    update();

    return true;
}

/*
 * modify
 */
bool Menu::moveDown(int steps)
{
//    /*
//     * 已到达菜单的最后一条条目
//     */
//    if(MenuHistory::getInstance()->getCurrentMenu()->selectedItem == items->size())
//        return false;

//    if(MenuHistory::getInstance()->getCurrentMenu()->menu->getItems()->at(MenuHistory::getInstance()->getCurrentMenu()->selectedItem)->getName() == "Exit")
//    {
//        endwin();
//        exit(0);
//    }

    this->steps = steps;
    update();

    return true;
}

bool Menu::backspace()
{
    /*
     * 如果菜单历史记录为空，则回退失败
     */
    if(MenuHistory::getInstance()->isEmpty())
    {
        return false;
    }
    else
    {
        /*
         * 释放菜单历史对象中的当前菜单信息后将历史菜单记录中的最近一条菜单信息存入菜单历史对象的当前菜单信息
         */
        MenuHistory::getInstance()->removeCurrentMenu();
        MenuHistory::getInstance()->setCurrentMenu(MenuHistory::getInstance()->getTop());
        MenuHistory::getInstance()->removeTop();
        clear();

        MenuHistory::getInstance()->getCurrentMenu()->menu->draw();
        return true;
    }
}
