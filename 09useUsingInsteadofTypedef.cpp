#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <type_traits> // 型别特征
using namespace std;

template <typename T>
using my_remove_const = typename remove_const<T>::type;

int main()
{
    using containSize = vector<int>::size_type;

    using UPtrMapSS = std::unique_ptr<std::unordered_map<string, string>>;

    typedef void (*fp)(const string &s, int);
    using fp2 = void (*)(const string &s, int);

    const int a = 10;
    remove_const<int>::type; // C++ 11
    remove_const_t<int>;     // C++ 14

    return 0;
}