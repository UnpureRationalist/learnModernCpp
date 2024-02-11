#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

/*
    使用 shared_ptr 管理具备共享所有权的资源

    shared_ptr<T> 内部包括一个指向类型 T 对象的指针和一个指向控制块的指针
                控制块包括：引用计数、弱计数、其他数据（如自定义删除器、分配器等）

    何时创建控制块？
        1. std::make_shared 总是创建一个控制块
        2. 从具备专属所有权的指针（unique_ptr 和 auto_ptr）出发构造 shared_ptr
   会创建控制块
        3. 当 std::shared_ptr 的构造函数从一个裸指针构造时，会创建一个控制块
*/

class Widget;

vector<shared_ptr<Widget>> processWidgets;

// 奇妙递归模板模式（ The Curiously Template Pattern, CRTP ）
class Widget : public std::enable_shared_from_this<Widget> {
 private:
  int data;

  // 构造函数

 public:
  void process() {
    // 处理对象本身（*this）

    // 将指涉到当前对象的 shared_ptr 加入 processWidgets
    processWidgets.emplace_back(shared_from_this());
  }

  // 将实参完美转发给 private 的】构造函数的工厂函数
  template <typename... Ts>
  static shared_ptr<Widget> create(Ts &&...params) {}
};

int main() {
  shared_ptr<int> spi(new int);
  cout << "sizeof(spi) = " << sizeof(spi) << endl;

  auto delfun = [](int *pi) { delete pi; };
  shared_ptr<int> spi2(new int, delfun);  // 自定义析构器

  // 错误代码：
  /*
      int *pi = new int;
      shared_ptr<int> sp1(pi);
      shared_ptr<int> sp2(pi);
  */
  // 正确代码：
  shared_ptr<string> sps(new string(10, 'a'));  // 直接把 new 表达式放在括号内
  return 0;
}
