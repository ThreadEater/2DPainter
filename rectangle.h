#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "shape.h"
class CRectangle :
    public CShape
{
public:
    // 无参数构造
    CRectangle(void);
    // 有参数构造
    CRectangle(char*, float, float, float, float);
    // 析构函数
    ~CRectangle(void);
    // 拷贝构造
    CRectangle(const CRectangle&);
    // 重载运算符
    CRectangle operator+(float);

private:
    float x1;
    float y1;
    float x2;
    float y2;
};
#endif // SHAPEARRAY_H
