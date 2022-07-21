#ifndef SHAPEARRAY_H
#define SHAPEARRAY_H


#include "Shape.h"
#include <vector>
#include <string>

class CShapeArray
{
public:
    CShapeArray(void);
    ~CShapeArray(void);
    // 添加
    void add(CShape*);
    // 插入
    void insert(int, CShape);
    // 删除
    void del(int);
    // 清除全部
    void clear(void);
    // 查询
    CShape* get(int);
    // 复制
    void copy(int, int);
    // 显示所有元素
    void drawAll(void);
    // 获取元素数目
    int getSize(void);
    // 根据名称查询
    int findByName(char*);

private:
    vector<CShape*> vec;
};

#endif // SHAPEARRAY_H
