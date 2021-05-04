#include <iostream>
using namespace std;

// 限定作用域的枚举型别
enum class Color
{
    Red,
    Green,
    Blue
};

// 指定枚举变量底层型别
enum class Status : std::uint32_t
{
    Movein,
    Acc,
    Reduce,
    Error = 100
};

int main()
{
    Color red = Color::Red; // 必须加作用域访问运算符才能访问枚举成员
    int Red = 10;   // 不会发生作用域泄露
    return 0;
}