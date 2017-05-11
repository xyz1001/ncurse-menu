#include "IndexMenu.h"

IndexMenu* IndexMenu::instance = nullptr;

IndexMenu::IndexMenu()
{

}

IndexMenu::IndexMenu(string name)
    :Menu(name)
{

}

IndexMenu::~IndexMenu()
{

}

IndexMenu *IndexMenu::getInstance()
{
    /*
     * 懒汉模式，以时间换空间
     */
    if(instance)
        return instance;

    instance = new IndexMenu("Index Page");
    return instance;
}
