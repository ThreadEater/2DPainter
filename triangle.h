#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "polygon.h"

class CTriangle :
    public CPolygon
{
public:
    // 无参数构造
    CTriangle(void);
    // 有参数构造
    CTriangle(char*, float*, float*);
    // 析构函数
    ~CTriangle(void);
    // 拷贝构造
    CTriangle(const CTriangle&);
    // 重载运算符
    CTriangle operator+(float);


private:
};

#endif // TRIANGLE_H
