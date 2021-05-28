#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

/*
    针对右值引用实施 move, 针对万能引用实施 forward
*/

class Widget
{
private:
    string name;
    shared_ptr<int> p;

public:
    // 移动构造函数
    Widget(Widget &&rhs) : name(move(rhs.name)), p(move(rhs.p)) {}

    // 万能引用
    template<typename T>
    void setName(T&& newName)
    {
        name = forward(newName);
    }
};

int main()
{

    return 0;
}