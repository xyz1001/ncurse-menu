#include "MenuHistory.h"
#include <stack>

MenuHistory* MenuHistory::instance = nullptr;

MenuHistory::MenuHistory()
{

}

MenuHistory *MenuHistory::getInstance()
{
    if(instance)
        return instance;

    instance = new MenuHistory();
    instance->menuHistory = new stack<MenuRecord *>;
    instance->currentMenu = new MenuRecord;
    return instance;
}

MenuHistory::~MenuHistory()
{
    /*
     * 栈无法使用for(auto &i:(*MenuHistory)) {...},
     * 因为栈不提供顺序迭代器
     */
    do
    {
        auto &i = menuHistory->top();
        delete i;
        menuHistory->pop();
    }while(!(menuHistory->empty()));

    delete menuHistory;
    delete currentMenu;
}

bool MenuHistory::isEmpty() const
{
    return menuHistory->empty();
}

MenuRecord* MenuHistory::getTop()
{
    return menuHistory->top();
}

bool MenuHistory::removeTop()
{
    menuHistory->pop();
    return true;
}

bool MenuHistory::removeCurrentMenu()
{
    if(currentMenu)
    {
        delete currentMenu;
        return true;
    }
    else return false;
}

void MenuHistory::addHistory(MenuRecord *menuRecord)
{
    menuHistory->push(menuRecord);
}

MenuRecord *MenuHistory::getCurrentMenu() const
{
    return currentMenu;
}

void MenuHistory::setCurrentMenu(MenuRecord *menuRecord)
{
    this->currentMenu = menuRecord;
}

