#include "InputItem.h"
#include <string.h>

InputItem::InputItem()
{

}

InputItem::InputItem(int x, int y, string name, int id, const char *inputName)
    :Item(x, y, name, id)
{
    strcpy(this->inputName, inputName);
    this->inputName[strlen(this->inputName)] = '\0';
//    currentEditPos = inputName.size() - 1;
}

void InputItem::draw()
{
    Item::draw();

    /*
     * 绘制输入名
     */
    move(x, COLUMN4);
    printw("%s", inputName);

    refresh();
}

void InputItem::update()
{
    //重绘新的属性值
    move(x, COLUMN4);
    printw("%s   ", inputName);
    if(isEditing)   //编辑状态下使光标所在位置字符反白闪烁显示
    {
        move(x, COLUMN4 + currentEditPos);  //移动至光标所在位置
        attron(A_REVERSE|A_BLINK);  //开启反白，闪烁
        if(inputName[currentEditPos] == '\0')   //如果当前光标在字符串后一个位置，直接打印一个反白的空格
        {
            printw(" ");
        }
        else
        {
            printw("%c", inputName[currentEditPos]);
        }
        attroff(A_REVERSE|A_BLINK);
    }
    else
    {
        move(x, COLUMN1);   //保持光标在星号上
    }

    refresh();
}

bool InputItem::moveLeft()
{
    /*
     * 处于编辑状态且光标位置不在第一个字符时左移
     */
    if(isEditing && currentEditPos > 0)
    {
        --currentEditPos;
        update();
        return true;
    }
    else
    {
        return false;
    }
}

bool InputItem::moveRight()
{
    /*
     * 处于编辑状态且光标位置不在最后一个字符后一个位置时左移
     */
    if(isEditing && currentEditPos < strlen(inputName))
    {
        ++currentEditPos;
        update();
        return true;
    }
    else
    {
        return false;
    }
}

bool InputItem::enter()
{
    isEditing = !isEditing; //切换编辑状态/非编辑状态
    update();
    return true;
}


bool InputItem::backspace()
{
    /*
     * 当字符串不为0时删除最后一个字符
     */
    if(strlen(inputName) > 0)
    {
        inputName[strlen(inputName) - 1] = '\0';
        /*
         * 当光标在最后时光标也前移一位
         */
        if(currentEditPos > strlen(inputName))
        {
            currentEditPos = strlen(inputName);
        }

        update();
        return true;
    }

    return false;

}

bool InputItem::input(int ch)
{
    if(strlen(inputName) == 99) //如果字符串已存满
    {
        return false;
    }
    else
    {
        inputName[currentEditPos] = ch; //当前光标位置的字符修改为输入的字符

        /*
         * 如果光标在字符串最后，则在字符串后添加结束标志\0
         */
        if(currentEditPos > strlen(inputName) - 1)
        {
            inputName[strlen(inputName)] = '\0';
        }
        ++currentEditPos;   //光标后移

        update();

        return true;
    }
}
