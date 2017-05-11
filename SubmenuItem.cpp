#include "SubmenuItem.h"

SubmenuItem::SubmenuItem()
{

}

SubmenuItem::SubmenuItem(int x, int y, string name, int id, Menu *submenu):Item(x, y, name, id)
{
    this->submenu = submenu;
}

SubmenuItem::~SubmenuItem()
{
    delete submenu;
}

void SubmenuItem::draw()
{
    Item::draw();

    /*
     * 绘制箭头
     */
    move(x, COLUMN4);
    printw(">>>");
    move(x, COLUMN1);   //返回星号位置

    refresh();
}

void SubmenuItem::update()
{
    clear();

    /*
     * 导入子菜单页信息（菜单及当前被选择条目）
     */
    MenuRecord *menuRecord = new MenuRecord;
    menuRecord->menu = submenu;
    menuRecord->selectedItem = 1;   //默认指向第一条条目

    /*
     * 将当前菜单信息保存至菜单历史中
     */
    MenuHistory::getInstance()->addHistory(MenuHistory::getInstance()->getCurrentMenu());
    MenuHistory::getInstance()->setCurrentMenu(menuRecord);

    submenu->draw();
}

bool SubmenuItem::moveLeft()
{
    return false;
}

bool SubmenuItem::moveRight()
{
    update();
    return true;
}

bool SubmenuItem::enter()
{
    return false;
}

bool SubmenuItem::backspace()
{
    return false;
}

bool SubmenuItem::input(int ch)
{
    return false;
}
