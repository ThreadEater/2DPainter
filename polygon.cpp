# include <math.h>

#include "Polygon.h"


CPolygon::CPolygon(void)
{
    shape = SHAPE_POLYGON;
    name = "多边形";
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

CPolygon::CPolygon(char *name, int edges, float *px, float *py)
{
    shape = SHAPE_POLYGON;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->edges = edges;
    this->px = new float[edges];
    this->py = new float[edges];
    for(int i = 0; i < edges; i++) {
        this->px[i] = px[i];
        this->py[i] = py[i];
    }
}

CPolygon::CPolygon(const CPolygon& src)
{
    shape = SHAPE_POLYGON;
    name = new char[strlen(src.name)];
    strcpy(name, src.name);
    edges = src.edges;
    this->px = new float[edges];
    this->py = new float[edges];
    for(int i = 0; i < edges; i++) {
        this->px[i] = src.px[i];
        this->py[i] = src.py[i];
    }
}

CPolygon::~CPolygon(void)
{
    delete[] name;
}

CPolygon CPolygon::operator+(float f)
{
    for(int i = 0; i < edges; i++)
        px[i] += f;
    return *this;
}
