#include "ExitItem.h"

ExitItem::ExitItem()
{

}

ExitItem::ExitItem(int x, int y, int id):Item(x, y, "Exit", id)
{

}

void ExitItem::draw()
{
    Item::draw();
}

void ExitItem::update()
{

}

bool ExitItem::moveLeft()
{
    return false;
}

bool ExitItem::moveRight()
{
    return false;
}

bool ExitItem::enter()
{
    return false;
}


bool ExitItem::backspace()
{
    return false;
}

bool ExitItem::input(int ch)
{
    return false;
}
