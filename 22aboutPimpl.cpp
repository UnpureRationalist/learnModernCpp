#include <iostream>
#include <memory>
#include "22Widget.h"
using namespace std;

/*
    使用 Pimpl 习惯用法时，将特殊成员函数的定义放到实现文件中
    本节内容仅使用于 unique_ptr

    Pimpl: pointer to implemention 指涉到实现的指针

    编译器不会为像 unique_ptr 那样的只移型别生成赋值操作
    即使编译器生成，其生成的函数也只能复制 unique_ptr (即实施浅复制)，而我们希望复制指针指涉的内容(即深复制)

*/

Widget getWidget()
{
    return Widget{};
}


int main()
{
    Widget w1(move(getWidget()));   // 若为： w1(getWidget())   则由于编译优化因素 不执行移动构造
    Widget w2;
    return 0;
}