#include <iostream>
#include <vector>

/**
 * 부녀회장이 될테야
 * boj.kr/2775
 */

using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

int main() {
  FASTIO;

  int N;
  cin >> N;

  vector<vector<int>> v(15, vector<int>(15));
  for (int i = 1; i < 15; i++) {
    v[0][i] = i;
  }

  for (int y = 1; y < 15; y++) {
    for (int x = 1; x < 15; x++) {
      v[y][x] = v[y][x - 1] + v[y - 1][x];
    }
  }

  int k, n;
  while (N--) {
    cin >> k >> n;
    cout << v[k][n] << '\n';
  }

  cout.flush();

  return 0;
}
