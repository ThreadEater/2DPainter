#include "Circle.h"

CCircle::CCircle(void)
{
    shape = SHAPE_CIRCLE;
    name = "圆形";
    x = 0;
    y = 0;
    r = 1;
}

CCircle::CCircle(char* name, float x, float y, float r)
{
    shape = SHAPE_CIRCLE;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->x = x;
    this->y = y;
    this->r = r;
}

CCircle::~CCircle(void)
{
    delete[] name;
}

CCircle::CCircle(const CCircle& src)
{
    shape = SHAPE_CIRCLE;
    name = new char[strlen(src.name)];
    strcpy(name, src.name);
    x = src.x;
    y = src.y;
    r = src.r;
}

CCircle CCircle::operator+(const float f)
{
    x += f;
    return *this;
}
