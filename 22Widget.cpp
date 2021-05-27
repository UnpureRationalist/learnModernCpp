#include "22Widget.h"
#include "22gadget.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

struct Widget::Impl
{
    string name;
    vector<double> data;
    Gadget g1, g2, g3;
};

Widget::Widget() : pImpl(make_unique<Impl>())       // make_unique
{
    cout << "construct" << endl;
}

Widget::~Widget() = default;

Widget::Widget(Widget&& rhs)     // 实现
{
    cout << "move construct" << endl;
}

Widget& Widget::operator=(Widget&& rop) = default;

Widget::Widget(const Widget &rop) : pImpl(make_unique<Impl>(*rop.pImpl))
{

}   // 拷贝构造函数

Widget& Widget::operator=(const Widget& rop)
{
    *pImpl = *rop.pImpl;
    return *this;
}   // 拷贝赋值运算符