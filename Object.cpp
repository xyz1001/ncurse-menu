#include "Object.h"

Object::Object() {}

Object::Object(int x, int y, string name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}

Object::~Object() {}

int Object::getX() const
{
    return x;
}

int Object::getY() const
{
    return y;
}

string Object::getName() const
{
    return this->name;
}
