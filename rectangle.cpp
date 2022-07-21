#include "Rectangle.h"


CRectangle::CRectangle(void)
{
    shape = SHAPE_RECTANGLE;
    name = "矩形";
    x1 = 0;
    y1 = 0;
    x2 = 2;
    y2 = 1;
}

CRectangle::CRectangle(char *name, float x1, float y1, float x2, float y2)
{
    shape = SHAPE_RECTANGLE;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

CRectangle::CRectangle(const CRectangle& src)
{
    shape = SHAPE_RECTANGLE;
    name = new char[strlen(src.name)];
    strcpy(name, src.name);
    x1 = src.x1;
    y1 = src.y1;
    x2 = src.x2;
    y2 = src.y2;
}

CRectangle::~CRectangle(void)
{
    delete[] name;
}

CRectangle CRectangle::operator+(float f)
{
    x1 += f;
    x2 += f;
    return *this;
}

