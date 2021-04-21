#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> v = {true, false, true, true, false, true};

    bool b = v[1];  // bool
    auto b2 = v[1]; // vector<bool>::reference

    auto b3 = static_cast<bool>(v[1]); // recommend
    return 0;
}