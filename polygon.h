#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
class CPolygon :
    public CShape
{
public:
    // 无参数构造
    CPolygon(void);
    // 有参数构造
    CPolygon(char*, int, float*, float*);
    // 析构函数
    ~CPolygon(void);
    // 拷贝构造
    CPolygon(const CPolygon&);
    // 重载运算符
    CPolygon operator+(float);

protected:
    int edges;
    float* px;
    float* py;
};



#endif // POLYGON_H
