#include <iostream>
#include <memory>
using namespace std;

/*
    使用 std::unique_ptr 管理具备所有权的资源
*/

class Investment
{
public:
    virtual ~Investment()
    {
    }
};

class Stock : public Investment
{
};

class Bond : public Investment
{
};

class RealEsate : public Investment
{
};

void makeLogEntry(Investment *p);

auto delInvmt = [](Investment *p) {
    makeLogEntry(p);
    delete p;
};

template <typename... Ts>
auto // 即： unique_ptr<Investment, decltype(delInvmt)>
makeInvestment(Ts &&...params)
{
    unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt); // 第二个参数为自定义析构器

    if (/* 应该创建一个 Stock 型别对象 */)
    {
        pInv.reset(new Stock(std::forward<Ts>(params)...)); // 使用完美转发
    }
    else if ()
    {
        // 略
    }
    else if ()
    {
    }
    return pInv;
}

// unique_ptr 也可以指向数组 不过一般不使用
unique_ptr<int[]> pt;

shared_ptr<Investment> sp = makeInvestment();   // unique_ptr 可自动转换为 shared_ptr

int main()
{

    return 0;
}