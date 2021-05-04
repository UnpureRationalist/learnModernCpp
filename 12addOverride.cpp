#include <iostream>
#include <string>
using namespace std;

class Base
{
private:
    int id;

public:
    Base() = default;

    virtual void doSomething() const
    {
        cout << "from Base class" << endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base
{
private:
    string name;

public:
    Derived() = default;

    // 重载时添加 override 声明，降低出错几率
    void doSomething() const override
    {
        cout << "from Derived class" << endl;
    }

    virtual ~Derived() = default;
};

void host(const Base& obj)
{
    obj.doSomething();
}

int main()
{
    Base b;
    Derived d;
    host(b);
    host(d);
    return 0;
}