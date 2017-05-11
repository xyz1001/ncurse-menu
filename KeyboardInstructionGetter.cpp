#include "KeyboardInstructionGetter.h"
#include "Controller.h"
#include <curses.h>

KeyboardInstructionGetter::KeyboardInstructionGetter()
{

}

void KeyboardInstructionGetter::run()
{
    while(1)
    {
            int c = getch();

        Controller::getInstance()->operate(c);
    }
}
