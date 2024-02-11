#include <iostream>
#include <typeinfo>
using namespace std;

/*
    如何查看型别推导结果
    1. IDE 内查看
    2. 编译器诊断信息
    3. 运行时输出(使用boost库 boost::typeindex::type_id_with_cvr)
*/

int main() {
  const int ans = 10;
  auto x = ans;   // int
  auto y = &ans;  // const int *

  cout << typeid(x).name() << endl;
  cout << typeid(y).name() << endl;
  return 0;
}
