#include <iostream>
using namespace std;

/*
    理解特种成员函数的生成机制
    特种成员函数包括：
        默认构造函数
        析构函数
        拷贝构造函数
        拷贝赋值运算符
        移动构造函数
        移动赋值运算符

    大三律：如果你声明了拷贝构造函数、拷贝赋值运算符、析构函数中的任意一个，则需要同时声明所有这三个。

    移动操作的生成条件：
        1. 该类未声明任何复制（拷贝）操作
        2. 该类未声明任何移动操作
        3. 该类未声明析构函数

    成员函数模板的存在会阻止编译器生成任何特种成员函数。
*/

class Widget {
 public:
  ~Widget();  // 用户定义的析构函数

  Widget(const Widget &) = default;  // 默认复制构造函数的行为是正确的

  Widget &operator=(const Widget &) =
      default;  // 默认拷贝赋值运算符行为是正确的

  Widget(Widget &&rhs);  // 移动构造函数

  Widget &operator=(Widget &rhs);  // 移动赋值运算符
};

class Try {
 public:
  Try() = default;

  template <typename T>
  Try(const T &rhs) {}
};

int main() {
  Try t(12);
  t = t;
  return 0;
}
