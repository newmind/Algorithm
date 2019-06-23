#include <iostream>
#include <vector>

/**
 * 최소공배수
 * boj.kr/13241
 */

typedef int64_t ll;

using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

int gcd(int a, int b) {
  while (b != 0) {
    int m = a % b;
    a = b;
    b = m;
  }
  return a;
}

int main() {
  FASTIO;

  ll a, b;
  cin >> a >> b;
  cout << a * b / gcd(a, b) << '\n';

  cout.flush();
  return 0;
}
