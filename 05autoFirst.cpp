#include <iostream>
#include <functional>
#include <vector>
#include <map>
using namespace std;

class Widget
{
private:
    int data;

public:
    bool operator<(const Widget &rop) const
    {
        return data < rop.data;
    }
};

int main()
{
    auto x = 0; // auto 声明必须初始化 否则编译器无法推导出类型

    auto comp = [](const auto &p1, const auto &p2) { return *p1 < *p2 }; // C++ 14 lambda形参中也可以写 auto

    std::function<bool(const std::unique_ptr<Widget> &,
                       const std::unique_ptr<Widget> &)>
        func = [](const std::unique_ptr<Widget> &p1,
                  const std::unique_ptr<Widget> &p2) { return *p1 < *p2; };

    vector<int> v = {1, 2, 3};
    auto sz = v.size(); // std::vector<int>::size_type

    unordered_map<string, int> m;
    for (auto &p : m) // p 类型: pair<const string, int> &
    {
    }
    /*
    for(pair<string, int> &p : m)   // 报错，原因：哈希表中键值类型为const 应该声明为 pair<const string, int>
    {
        
    }
    */
    return 0;
}