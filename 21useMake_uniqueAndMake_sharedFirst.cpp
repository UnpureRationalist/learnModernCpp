#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/*
    优先选用 std::make_unique 和 make_shared ,而非直接使用 new 。
    make 系列函数第三个： allocate_shared
    make 系列函数功能：
        将任意实参集合完美转发非动态分配内存对象的构造函数
        但是， make 系列函数不允许自定义析构器；不能完美转发大括号{ }初始化物

    对于 shared_ptr ，不建议使用 make 系列函数的额外场景包括：
        1. 自定义内存管理的类
        2. 内存紧张的系统、非常大的对象、以及存在比指涉到相同对象的 shared_ptr
   生存期更久的 weak_ptr
*/

class Widget {
 private:
  int data;

 public:
  Widget() = default;

  Widget(int d) : data(d) {}
};

int computePriority() {}

void proessWidget(shared_ptr<Widget> spw, int priority) {}

int main() {
  auto upw1(make_unique<Widget>());            // use make_unique
  std::unique_ptr<Widget> upw2(new Widget());  // use new, not recommend

  auto spw1(make_shared<Widget>());

  // make 系列函数能保证异常安全
  proessWidget(shared_ptr<Widget>(new Widget),
               computePriority());  // 导致潜在的资源泄露
  proessWidget(make_shared<Widget>(),
               computePriority());  // 不会发生潜在的资源泄露风险

  auto delWidget = [](Widget *pw) -> void {
    cout << "自定义析构器" << endl;
    delete pw;
  };
  unique_ptr<Widget, decltype(delWidget)> upw(new Widget(), delWidget);
  shared_ptr<Widget> spw(new Widget, delWidget);  // 自定义析构器

  // make 系列函数不能完美转发大括号{ }初始化物
  // 解决方法：
  auto initList = {10, 20};
  auto spv = make_shared<vector<int>>(initList);
  return 0;
}
