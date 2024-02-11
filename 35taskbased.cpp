#include <future>
#include <iostream>
#include <thread>
using namespace std;

int doAsyncWork() {
  cout << "doAsyncWork..." << endl;
  return 0;
}

int main() {
  auto f = std::async(doAsyncWork);  // recommended
  thread t(doAsyncWork);             // not recommended
  t.join();
  return 0;
};
