#include "Item.h"

Item::Item() {}

Item::Item(int x, int y, string name, int id):Object(x, y, name)
{
    this->id = id;
}

Item::~Item()
{

}

void Item::draw()
{
    /*
     * 绘制序号
     */
    move(x, COLUMN2);
    printw("%02d", id);

    /*
     * 绘制条目名
     */
    move(x, COLUMN3);
    printw("%s", name.c_str());

}
