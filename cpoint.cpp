#include "CPoint.h"


CCPoint::CCPoint(void)
{
    shape = SHAPE_POINT;
    name = "点";
    x = 0;
    y = 0;
}

CCPoint::CCPoint(char *name, float x, float y)
{
    shape = SHAPE_POINT;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->x = x;
    this->y = y;
}

CCPoint::CCPoint(const CCPoint& src)
{
    shape = SHAPE_POINT;
    name = new char[strlen(src.name)];
    strcpy(name, src.name);
    x = src.x;
    y = src.y;
}

CCPoint::~CCPoint(void)
{
    delete[] name;
}

CCPoint CCPoint::operator+(float f)
{
    x += f;
    return *this;
}
