#include <iostream>
#include <vector>
using namespace std;

class Widget
{
private:
    int x = 0;
    int y{0};
    // int z(0);     // 错误 除了不可复制对象，如 std::atomic<T> ，可以小括号初始化，但不能 = 初始化

public:
    Widget() = default;

    Widget(double d, bool b) { cout << "double  and bool " << endl; }

    Widget(initializer_list<long double> il) { cout << "initial_list" << endl; }
};

int main()
{
    vector<int> v{1, 2, 3, 4, 5}; // 大括号初始化

    /*
        大括号初始化禁止内建类型之间进行隐式窄化型别转换，但 = 和 () 允许
    */
    double x = 1e20, y(1e20), z{1e20};
    int sum1{x + y + z}; // warning: narrowing conversion of '((x + y) + z)' from 'double' to 'int' [-Wnarrowing]
    int sum2(x + y + z);
    int sum3 = x + y + z;

    Widget w(); // 声明了一个函数，并不是默认构造
    auto f = w; // Widget (*f) ()

    Widget w2{}; // right: 默认构造函数

    Widget w3(10, true); // double bool
    Widget w4{10, true}; // initializer_list

    vector<int> v1(10, 20); // 10 elements ; values:20
    vector<int> v2{10, 20}; // 2 elements(10 and 20)
    return 0;
}

Widget w()
{
    return Widget{}; // 此处执行默认构造函数 而非空的 initializer_list 构造
    // 如果非要调用空的 initiaizer_list 构造函数，可如下书写：
    return Widget{{}};
    // or
    return Widget({});
}