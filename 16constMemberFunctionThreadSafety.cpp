#include <atomic>
#include <cmath>
#include <iostream>
#include <mutex>
#include <vector>
using namespace std;

/*
     保证 const 成员函数的线程安全性
*/

class Polynomial {
 public:
  using RootsType = vector<double>;

  RootsType roots()
      const  // 问题：两个线程同时调用某个对象的该函数时，产生线程安全性问题。解决方法：引入互斥量
  {
    /*
        添加以下代码
    */
    std::lock_guard<std::mutex> g(
        m);  // 加上互斥量 lock_guard
             // 是一个模板类，利用类的构造和析构管理互斥量的加锁和解锁
    if (!rootsAreValid) {
      // 计算 并存入 rootVals
      rootsAreValid = true;
    }
    return rootVals;
  }

 private:
  mutable bool rootsAreValid{false};
  mutable RootsType rootVals{};  // mutable 关键字 运行在 const 成员函数中改变值

  mutable std::mutex
      m;  // 互斥量
          // std::mutex是个只移型别，即只能移动但不能复制，导致类本身也失去了可复制性，但仍可移动
};

/*
    使用 std::atomic 型别的计数器计算一个成员函数被调用的次数
    可以确保其它线程可以以不加分割的方式观察到其操作发生
*/
class Point {
 public:
  double distanceFromOrigin() const noexcept {
    ++callCount;  // 带原子性的自增操作
    return sqrt((x * x) + (y * y));
  }

 private:
  mutable std::atomic<unsigned> callCount{
      0};  // 只移型别 对类的影响同上文 mutex
  double x, y;
};

/*
    对于单个要求同步的变量或内存区域，使用 std::atmoic 就足够了。
    但是如果有两个或者更多个变量或内存区域需要作为一整个单位进行操作时，就要动用互斥量了。
*/
int expensiveComputation1();
int expensiveComputation2();
class Widget {
 public:
  int magicValue() const {
    std::lock_guard<std::mutex> guard(m);  // 给 m 加上互斥量
    if (cacheValid)
      return cachedValue;
    else {
      auto val1 = expensiveComputation1();
      auto val2 = expensiveComputation2();
      cachedValue = val1 + val2;
      cacheValid = true;
      return cachedValue;
    }
    // 函数执行完毕退出后 自动执行析构 释放互斥量
  }

 private:
  mutable std::mutex m;
  mutable int cachedValue;         // 不再具备原子性
  mutable bool cacheValid{false};  // 不再具备原子性
};

int main() { return 0; }
