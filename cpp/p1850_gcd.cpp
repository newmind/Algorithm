#include <iostream>
#include <vector>

/**
 * 최소공배수
 * boj.kr/1850
 */

typedef int64_t ll;

using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

ll gcd(ll a, ll b) {
  while (b != 0) {
    ll m = a % b;
    a = b;
    b = m;
  }
  return a;
}

int main() {
  FASTIO;

  ll a, b;
  cin >> a >> b;
  ll g = gcd(a, b);

  cout << string(g, '1') << endl;

  return 0;
}
