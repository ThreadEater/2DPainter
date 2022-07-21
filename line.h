#ifndef LINE_H
#define LINE_H

#include "shape.h"
class CLine :
    public CShape
{
public:
    // 无参数构造
    CLine(void);
    // 有参数构造
    CLine(char*, float, float, float, float);
    // 析构函数
    ~CLine(void);
    // 拷贝构造
    CLine(const CLine&);
    // 重载运算符
    CLine operator+(float);

private:
    float x1;
    float y1;
    float x2;
    float y2;
};

#endif // LINE_H
