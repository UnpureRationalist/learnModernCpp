#include <iostream>
using namespace std;

/*
    只移型别： unique_ptr、 future、 thread 等

    move 和 forward 都是仅仅执行类型转换的函数模板

    move 仅仅将类型强制转换为右值型别
    forward 则仅当传入的实参为右值时，才针对该实参实施向右值型别的强制型别转换

    在运行期， move 和 forward 都不会做任何操作.
*/

int main()
{
    
    return 0;
}