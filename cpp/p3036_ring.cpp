#include <string>
#include <vector>
#include <iostream>

// 링
// boj.kr/3036

using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

int gcd(int a, int b)
{
  while (b != 0)
  {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  FASTIO;
  int N, a, b;
  cin >> N >> a;

  N--;
  while (N--) {
    cin >> b;
    int g = gcd(a, b);
    cout << (int)(a/g) << '/' << (int)(b/g) << '\n';
  }

  cout.flush();
  return 0;
}
