#include <iostream>

/**
 * 피보나치
 */
using namespace std;

typedef long long ll;

int main() {
  ll n = 0;
  cin >> n;

  if (n < 2) {
    cout << n << endl;
    return 0;
  }
  long long fib_2 = 0, fib_1 = 1;
  for (size_t i = 2; i <= n; i++) {
    fib_1 = fib_2 + fib_1;
    fib_2 = fib_1 - fib_2;
  }

  cout << fib_1 << endl;
  return 0;
}