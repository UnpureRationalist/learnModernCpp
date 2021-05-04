#include <iostream>
using namespace std;

class Base
{
private:
    
public:
    void print() const noexcept
    {
        cout << "from Base class" << endl;
    }

    void setup()
    {

    }

    void doWork() noexcept
    {
        setup();    // 允许在声明 noexcept 的函数中调用未声明 noexcept 的函数
    }
};

int main()
{

    return 0;
}