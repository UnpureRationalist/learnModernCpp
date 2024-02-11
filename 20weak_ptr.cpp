#include <iostream>
#include <memory>
using namespace std;

/*
    对于类似 shared_ptr 但是有可能空悬的指针使用 weak_ptr

    weak_ptr 一般通过 shared_ptr 进行创建，但是 weak_ptr 不改变引用计数

    weak_ptr 用处：缓存、观察者列表、避免 shared_ptr
   指针环路（导致资源永远不能释放，从而内存泄漏）
*/

class Widget {};

int main() {
  auto spw = std::make_shared<Widget>();
  weak_ptr<Widget> wpw(spw);  // 由 shared_ptr 创建 weak_ptr

  // 由 weak_ptr 创建 shared_ptr 有两种方法
  auto spw1 = wpw.lock();  // 若 weak_ptr 无效，则 spw1 为空
  shared_ptr<Widget> spw2(
      wpw);  // 若 weak_ptr 无效，则抛 std::bad_weak_ptr 型别的异常
  return 0;
}
