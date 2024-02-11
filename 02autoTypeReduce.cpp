#include <iostream>
using namespace std;

int main() {
  auto i1 = 10;
  auto i2(10);     // int
  auto i3 = {10};  // std::initializer_list<int>
  auto i4{10};     // int
  cout << i4 << endl;
  /*
      auto 会假定 {} 括起来的初始化表达式类型为 std::initializer_list
      模板类型推导则不会
  */
  return 0;
}
