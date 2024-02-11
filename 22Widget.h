#pragma once

#include <memory>
using namespace std;

class Widget {
 public:
  Widget();

  ~Widget();  // 必须声明 否则编译错误
  // invalid application of 'sizeof' to incomplete type 'Widget::Impl'   79 |
  // static_assert(sizeof(_Tp)>0,

  Widget(Widget&& rhs);

  Widget& operator=(Widget&& rhs);

  Widget(const Widget&);

  Widget& operator=(const Widget&);

 private:
  struct Impl;             // 声明
  unique_ptr<Impl> pImpl;  // 指涉到实现的指针
};
