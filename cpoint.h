#ifndef CPOINT_H
#define CPOINT_H


#include "shape.h"

// 由于CPoint为VS中的保留类名，故此处用CCPoint代替，以免产生干扰
class CCPoint :
    public CShape
{
public:
    // 无参数构造
    CCPoint(void);
    // 有参数构造
    CCPoint(char*, float, float);
    // 析构函数
    ~CCPoint(void);
    // 拷贝构造
    CCPoint(const CCPoint&);
    // 重载运算符
    CCPoint operator+(float);

private:
    float x;
    float y;
};




#endif // CPOINT_H
