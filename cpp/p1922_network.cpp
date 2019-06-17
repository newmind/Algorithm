#include <iostream>
#include <queue>
#include <string>
#include <vector>

// 최소 비용 트리 MST prim
using namespace std;

struct _d {
  int n;
  int w;
};

struct comp {
  bool operator()(const _d& a, const _d& b) {
    return a.w > b.w;
  }  // 반대로 비교
};

int prim(int N, vector<vector<int>>& v) {
  vector<vector<_d>> g(N + 1);
  for (size_t i = 0; i < v.size(); i++) {
    int a, b, c;
    a = v[i][0];
    b = v[i][1];
    c = v[i][2];
    g[a].push_back(_d{b, c});
    g[b].push_back(_d{a, c});
  }

  int min_cost = 0;

  vector<bool> visited(N + 1);
  priority_queue<_d, vector<_d>, comp> q;
  q.push(_d{1, 0});

  while (!q.empty()) {
    _d t = q.top();
    q.pop();

    if (visited[t.n]) continue;

    visited[t.n] = true;
    min_cost += t.w;

    for (_d& tt : g[t.n]) {
      if (!visited[tt.n]) {
        q.push(tt);
      }
    }
  }
  return min_cost;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M, a, b, c;
  cin >> N;
  cin >> M;

  vector<vector<int>> v(M);
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    v[i].push_back(a);
    v[i].push_back(b);
    v[i].push_back(c);
  }

  // int N = 6;
  // vector<vector<int>> v = {{1, 2, 5}, {1, 3, 4}, {2, 3, 2},
  //                          {2, 4, 7}, {3, 4, 6}, {3, 5, 11},
  //                          {4, 5, 3}, {4, 6, 8}, {5, 6, 8}};

  cout << prim(N, v) << '\n';
  cout.flush();
  return 0;
}