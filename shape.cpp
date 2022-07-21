#include "Shape.h"


CShape::CShape(void)
{
    name = "形状";
}

CShape::CShape(char *name)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

CShape::~CShape(void)
{
    delete[] name;
}

CShape::CShape(const CShape& src)
{
    name = new char[strlen(src.name)];
    strcpy(name, src.name);
}

void CShape::Draw(void)
{
    // 如果子类出错，则调用此方法
    cout << "未定义形状" << endl;
}

void CShape::Calc(void)
{
    // 如果子类出错，则调用此方法
    cout << "无法计算周长" << endl;
}

char *CShape::getName(void)
{
    return name;
}

void CShape::saveToFile(ofstream&)
{
}

CShape& CShape::loadFromFile(ifstream&)
{
    return *new CShape();
}

int CShape::exist()
{
    return 1;
}
