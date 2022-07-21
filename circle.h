#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
class CCircle :
    public CShape
{
public:
    // 无参数构造
    CCircle(void);
    // 有参数构造(圆心坐标，半径)
    CCircle(char *, float x, float y, float r);
    // 析构函数
    ~CCircle(void);
    // 拷贝构造
    CCircle(const CCircle&);
    // 重载“+”操作符
    CCircle operator+(const float);

private:
    float x;
    float y;
    float r;
};

#endif // CIRCLE_H
