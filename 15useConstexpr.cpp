#include <array>
#include <iostream>
using namespace std;

/*
    constexpr对象：具备 const 属性；编译阶段就已知；其限制大于
   const，const可能运行期才知道值

    constexpr函数：函数实参为 constexpr
   对象，则编译阶段产生结果；否则运行期产生结果. 通常来说，constexpr
   函数里不允许出现 I/O 语句
*/

constexpr int pow(int base, int exp) noexcept {
  return (exp == 0 ? 1 : pow(base, exp - 1));
}

constexpr int pow2(int base, int exp) noexcept  // C++ 14
{
  auto result = 1;
  for (int i = 0; i < exp; ++i) result *= base;
  return result;
}

int main() {
  constexpr auto num = 10;
  constexpr auto exp = 2;
  array<int, pow(num, exp)> nums;
  return 0;
}
