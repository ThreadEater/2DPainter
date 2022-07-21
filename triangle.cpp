#include "Triangle.h"


CTriangle::CTriangle(void)
{
    shape = SHAPE_TRIANGLE;
    name = "三角形";
    edges = 3;
    float x[] = {0, 0, 1};
    float y[] = {0, 1, 0};
    px = new float[edges];
    py = new float[edges];
    for(int i = 0; i < edges; i++) {
        this->px[i] = x[i];
        this->py[i] = y[i];
    }
}

CTriangle::CTriangle(char *name, float *px, float *py)
{
    shape = SHAPE_TRIANGLE;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->edges = 3;
    this->px = new float[3];
    this->py = new float[3];
    for(int i = 0; i < 3; i++) {
        this->px[i] = px[i];
        this->py[i] = py[i];
    }
}

CTriangle::CTriangle(const CTriangle& src)
{
    shape = SHAPE_TRIANGLE;
    name = new char[strlen(src.name)];
    strcpy(name, src.name);
    this->edges = 3;
    this->px = new float[3];
    this->py = new float[3];
    for(int i = 0; i < 3; i++) {
        this->px[i] = src.px[i];
        this->py[i] = src.py[i];
    }
}

CTriangle::~CTriangle(void)
{
    delete[] name;
}

CTriangle CTriangle::operator+(float f)
{
    px[0] += f;
    px[1] += f;
    px[2] += f;
    return *this;
}
