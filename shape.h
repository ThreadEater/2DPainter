#ifndef SHAPE_H
#define SHAPE_H


#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>

using namespace std;

class CShape
{
public:
    const static int SHAPE_CIRCLE = 1;
    const static int SHAPE_POINT = 2;
    const static int SHAPE_LINE = 3;
    const static int SHAPE_POLYGON = 4;
    const static int SHAPE_RECTANGLE = 5;
    const static int SHAPE_TRIANGLE = 6;
    // 无参数构造
    CShape(void);
    // 有参数构造
    CShape(char*);
    // 析构函数
    ~CShape(void);
    // 拷贝构造
    CShape(const CShape&);
    // 获取名称
    char *getName();
    // 显示名称等信息，使用虚函数
    virtual void Draw(void);
    // 计算并显示周长，使用虚函数
    virtual void Calc(void);
    // 保存至文件
    virtual void saveToFile(ofstream&);
    // 从文件读取
    virtual CShape& loadFromFile(ifstream&);
    // 判断形状是否存在
    virtual int exist();

protected:
    // 图形的名称
    char* name;
    int shape;
};

#endif // SHAPE_H
