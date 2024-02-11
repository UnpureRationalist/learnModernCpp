#include <future>
#include <iostream>
#include <thread>
using namespace std;

int doAsyncWork() {
  cout << "doAsyncWork..." << endl;
  return 0;
}

int main() {
  auto f = std::async(std::launch::async, doAsyncWork);
  cout << f.get() << " main thread..." << endl;
  return 0;
};
