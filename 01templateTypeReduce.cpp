#include <iostream>
using namespace std;

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
  return N;
}

int main() {
  int a[] = {1, 23, 4, 5, 6};
  const char name[] = "ad sdfs-s sd,sas";
  cout << "arraySize = " << arraySize(a) << endl;
  cout << "arraySize = " << arraySize(name) << endl;

  char copy[arraySize(name)] = {'a', 'b', 'c'};

  return 0;
}
