#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cin >> n;

  long long fib_2 = 0, fib_1 = 1;
  for (size_t i = 2; i <= n; i++) {
    fib_1 = fib_2 + fib_1;
    fib_2 = fib_1 - fib_2;
  }

  cout << fib_1 << endl;
  return 0;
}