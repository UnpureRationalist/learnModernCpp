#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    优先选用 const_iterator,而非 iterator
*/
int main()
{
    vector<int> v = {12, 43, 5, 232, 454, 32, -234, -23, -56, 0, 23, 2};
    auto iter = find(v.cbegin(), v.cend(), 32);
    if (iter != v.cend())
        cout << *iter << endl;
    return 0;
}