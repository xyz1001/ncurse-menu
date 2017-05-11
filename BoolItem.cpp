#include "BoolItem.h"

/*
 * 根据当前布尔值获取TRUE或FALSE字符串
 */
const char* getBool(bool value)
{
    return value?"TRUE":"FALSE";
}

BoolItem::BoolItem()
{

}

BoolItem::BoolItem(int x, int y, string name, int id, bool value):Item(x, y, name, id)
{
    this->value = value;
}

void BoolItem::draw()
{
    Item::draw();

    /*
     * 绘制属性值
     */
    move(x, COLUMN4);
    printw("%s", getBool(value));

    refresh();
}

void BoolItem::update()
{
    //重绘新的属性值
    move(x, COLUMN4);
    printw("%s  ",getBool(value));
    move(x, COLUMN1);   //保持光标在星号上

    refresh();
}

bool BoolItem::moveLeft()
{
    value=!value;
    update();
    return true;
}

bool BoolItem::moveRight()
{
    return moveLeft();  //与左移效果一致
}


bool BoolItem::enter()
{
    return false;
}

bool BoolItem::backspace()
{
    return false;
}

bool BoolItem::input(int ch)
{
    return false;
}
