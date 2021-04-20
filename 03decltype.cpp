#include <iostream>
#include <vector>
using namespace std;

/*
    decltype : declared type  声明类型
*/

// C++ 11
template <typename Container, typename Index>
auto authAndAccess(Container &c, Index i) -> decltype(c[i])
{
    return c[i];
}
/*
    尾序返回值好处：在指定返回值型别是可以使用函数形参  上面： -> decltype(c[i])
    若按照传统声明顺序，则由于 c 、 i 尚未声明，编译报错
*/

// C++ 14
template <typename COntainer, typename Index>
decltype(auto) authAndAccess2(COntainer &c, Index i)
{
    return c[i];
}

// C++ 14  万能引用
template <typename COntainer, typename Index>
decltype(auto) authAndAccess3(COntainer &&c, Index i)
{
    return std::forward<COntainer>(c)[i];
}

decltype(auto) f1()
{
    int x = 0;
    return x; // 返回值类型 int
}

decltype(auto) f2()
{
    int x = 0;
    return (x); // 返回值类型 int &   错误：返回了局部变量的引用！
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    authAndAccess(v, 1);

    authAndAccess2(v, 1);

    authAndAccess3(v, 1);
    authAndAccess3(vector<int>{1, 2, 3, 4}, 1);

    int x = 0;
    decltype(x) dx = 0;   // int
    decltype((x)) rx = x; // int &      C++ 中，表达式 (x) 是个左值
    return 0;
}