#include <iostream>
#include <queue>

/**
 * 조세퍼스 문제
 * boj.kr/1158
 */
using namespace std;
int main() {
  // cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  queue<int> q;
  for (size_t i = 1; i <= N; i++) {
    q.push(i);
  }

  cout << '<';

  int count = 0;
  while (!q.empty()) {
    auto e = q.front();
    q.pop();
    count++;
    count %= K;
    if (count != 0) {
      q.push(e);
    } else {
      cout << e << (!q.empty() ? ", " : "");
    }

  }
  cout << '>';
  cout.flush();
  return 0;
}
