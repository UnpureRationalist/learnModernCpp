#include <Windows.h>

#include <iostream>
#include <vector>
using namespace std;

/*
    区分万能引用和右值引用

    T&& 有两种含义：右值引用 和 万能引用
*/

// 万能引用
template <typename T>
void f(T &&param) {}

int getInt() { return 0; }

template <typename T>
void f2(vector<T> &&param)  // 是右值引用，不是万能引用
{}

void f3(int n) {
  for (int i = 0; i < n; ++i)
    ;
}

int main() {
  auto &&var1 = getInt();  // 万能引用 涉及型别推导则为万能引用 否则为右值引用

  vector<int> v;
  // f2(v); // 报错 模板不匹配

  // 计算函数执行时间 C++ 14
  auto timeFuncInvocation = [](auto &&func, auto &&...params) {
    auto start = GetTickCount();  // 计时器启动
    forward<decltype(func)>(func)(
        forward<decltype(params)>(params)...);  // 函数调用

    auto end = GetTickCount();  // 计时器停止并计算时间间隔
    cout << "run time = " << end - start << " ms" << endl;
  };
  timeFuncInvocation(f3, 10000000);
  return 0;
}
