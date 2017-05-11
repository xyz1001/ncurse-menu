#include "ValueItem.h"
#include <curses.h>

ValueItem::ValueItem() {}

ValueItem::ValueItem(int x, int y, string name, int id, int minValue, int maxValue, int value):Item(x, y, name, id)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->value = value;
}

void ValueItem::draw()
{
    Item::draw();

    /*
     * 绘制属性值
     */
	move(x, COLUMN4);
	printw("%d", value);

	refresh();
}

void ValueItem::update()
{
    //重绘新的属性值
    move(x, COLUMN4);
    printw("%d   ",value);

    move(x, COLUMN1);   //保持光标在星号上
    refresh();
}

bool ValueItem::moveLeft()
{
    if(value == minValue)   //已到达最小值
		return false;
	--value;

    update();
    return true;
}

bool ValueItem::moveRight()
{
    if(value == maxValue)   //已到达最大值
		return false;
	++value;

    update();
    return true;
}

bool ValueItem::enter()
{
    return false;
}


bool ValueItem::backspace()
{
    return false;
}


bool ValueItem::input(int ch)
{
    return false;
}

