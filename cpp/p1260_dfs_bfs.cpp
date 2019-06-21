#include <iostream>
#include <cstring>
#include <queue>

/**
 * DFS와 BFSs
 * boj.kr/1260
 */
using namespace std;

bool adj[1001][1001];
bool visited[1001];
int visited_count = 0;

void dfs(int v, int n) {
  if (n == visited_count || visited[v]) {
    return;
  }

  visited[v] = true;
  visited_count++;
  cout << v << (n != visited_count ? " " : "");

  for (size_t to = 1; to < 1001; to++) {
    if (to != v && adj[v][to] && !visited[to])
      dfs(to, n);
  }
}

void bfs(int v, int n) {
  queue<int> q;
  q.push(v);

  while (!q.empty()) {
    int i = q.front();
    q.pop();

    if (visited[i]) continue;

    visited[i] = true;
    visited_count++;
    cout << i << (n != visited_count ? " " : "");

    for (size_t to = 1; to < 1001; to++) {
      if (to != i && adj[i][to] && !visited[to])
        q.push(to);
    }
  }
}

int main() {
  // cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M, V;
  cin >> N >> M >> V;
  int a, b;
  while (M--) {
    cin >> a >> b;
    adj[a][b] = true;
    adj[b][a] = true;
  }

  dfs(V, N);
  cout << '\n';
  memset(visited, false, sizeof(visited));
  visited_count = 0;
  bfs(V, N);

  cout.flush();
  return 0;
}
