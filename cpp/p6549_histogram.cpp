#include <algorithm>
#include <iostream>
#include <vector>

/**
 * 쿼드트리
 * boj.kr/1992
 */

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

using namespace std;

typedef int64_t ll;

ll max_area(vector<int>& v) {
  ll max_area = 0l;

  vector<pair<int, int>> stack;
  stack.push_back({0, v[0]});
  for (size_t i = 1; i < v.size(); i++) {
    auto prev = stack.back();
    if (prev.second < v[i])
      stack.push_back({i, v[i]});
    else {  // prev > v[i]
      auto lastPoped = prev;
      while (prev.second >= v[i]) {
        stack.pop_back();
        lastPoped = prev;
        // 이전 세로 크기
        ll vertical = (ll)(i - prev.first) * prev.second;
        max_area = max(max_area, vertical);
        // 수평 크기
        ll horizontal = (ll)(i - prev.first + 1) * v[i];
        max_area = max(max_area, horizontal);
        if (!stack.empty())
          prev = stack.back();
        else
          break;
      }
      stack.push_back({lastPoped.first, v[i]});
    }
  }

  while (!stack.empty()) {
    auto prev = stack.back();
    stack.pop_back();

    ll horizontal = (ll)(v.size() - prev.first) * prev.second;
    max_area = max(max_area, horizontal);
  }

  return max_area;
}

int main() {
  FASTIO;

  int N;
  vector<int> vv;
  while (true) {
    cin >> N;

    if (N == 0) break;

    vv.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> vv[i];
    }
    cout << max_area(vv) << '\n';
  }

  // vector<int> v = {2, 1, 4, 5, 1, 3, 3};
  // cout << max_area(v) << '\n';

  // vector<int> v2 = {1000, 1000, 1000, 1000};
  // cout << max_area(v2) << '\n';

  return 0;
}
