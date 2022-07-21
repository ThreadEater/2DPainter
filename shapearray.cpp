#include "ShapeArray.h"


CShapeArray::CShapeArray(void)
{
}

CShapeArray::~CShapeArray(void)
{
}

void CShapeArray::add(CShape *s)
{
    vec.push_back(s);
}

void CShapeArray::insert(int pos, CShape s)
{
    vector<CShape*>::iterator it = vec.begin();
    vec.insert(it + pos, &s);
}

void CShapeArray::del(int pos)
{
    vector<CShape*>::iterator it = vec.begin();
    vec.erase(it + pos);
}

void CShapeArray::clear(void)
{
    vec.clear();
}

CShape* CShapeArray::get(int pos)
{
    try {
        return vec.at(pos);
    } catch(const exception& e) {
        // 如果访问越界，抛出异常
        cout << e.what();
    }
    // 访问越界则返回一个空形状
    return new CShape();
}

void CShapeArray::copy(int pos1, int pos2)
{
    vector<CShape*>::iterator it = vec.begin();
    CShape& s = *vec.at(pos1);
    CShape *tmp = &s;
    vec.insert(it + pos2, tmp);
}

void CShapeArray::drawAll(void)
{
    cout << "--------------------------所有形状--------------------------" << endl;
    for(int i = 0; i < getSize(); i++) {
        // 形状序号
        cout << i + 1 << "、";
        vec.at(i)->Draw();
    }
    cout << "------------------------------------------------------------" << endl;
}

int CShapeArray::getSize(void)
{
    return vec.size();
}

int CShapeArray::findByName(char *name)
{
    for(int i = 0; i < getSize(); i++) {
        if(strcmp(vec.at(i)->getName(), name) == 0)
            return i;
    }
    return -1;
}
