#include <iostream>
using namespace std;

class Base
{
private:
    int data;

public:
    Base() = delete; // 使用删除函数

    Base(int i) : data(i) {}

    // 如果要禁止拷贝 如 cout、cin 等类那样
    Base &operator=(const Base &) = delete; // 禁止拷贝
};

// delete 也可作用于普通函数 禁止模板具象化 int 类型
bool comp(int a, int b) = delete;

template <typename Type>
bool comp(Type a, Type b)
{
    return a < b;
}

int main()
{

    return 0;
}