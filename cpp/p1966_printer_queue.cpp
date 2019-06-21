#include <iostream>
#include <deque>

/**
 * 프린터 큐
 * boj.kr/1966
 */
using namespace std;
int main() {
  // cin.tie(NULL);
  ios::sync_with_stdio(false);

  int T, N, M, P;
  cin >> T;


  while (T--) {
    cin >> N >> M;

    deque<pair<int, int>> q;
    for (size_t i = 0; i < N; i++) {
      cin >> P;
      q.push_back(make_pair(P, i));
    }

    int pop_count = 0;
    while (true) {
      auto e = q.front();
      q.pop_front();

      bool foundHigh = false;
      for (size_t i = 0; i < q.size(); i++) {
        if (q[i].first > e.first) {
          foundHigh = true;
          q.push_back(e);
          break;
        }
      }

      if (!foundHigh) {
        pop_count++;
        if (e.second == M) {
          cout << pop_count << '\n';
          break;
        }
      }
    }
  }

  cout.flush();
  return 0;
}
