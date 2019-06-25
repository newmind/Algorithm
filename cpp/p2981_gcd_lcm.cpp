#include <algorithm>
#include <iostream>
#include <vector>

/**
 * 공통된 나머지
 * boj.kr/2981
 * 먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로
 * 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야
 * 한다. N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.
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

  int n;
  cin >> n;

  vector<int> v(n);

  for (size_t i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  int g = v[1] - v[0];
  for (int i = 2; i < n; i++) {
    g = gcd(g, v[i] - v[i - 1]);
  }

  vector<int> ans;
  ans.push_back(g);
  for (size_t i = 2; i * i <= g; i++) {
    if (g % i == 0) {
      ans.push_back(i);
      if (i != (int)(g / i)) ans.push_back(g / i);
    }
  }
  sort(ans.begin(), ans.end());

  for (auto e : ans) cout << e << ' ';

  return 0;
}
