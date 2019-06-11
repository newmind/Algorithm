#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
void print(std::vector<T> const& input) {
  for (int i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << ' ';
  }
}
template <typename T>
void print(std::set<T> const& input) {
  for (auto& e : input) {
    std::cout << e << ' ';
  }
}
void print(int n) { std::cout << n << '\n'; }

void perm_print(int n, vector<int>& picked, int toPick) {
  // 기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력한다.
  if (toPick == 0) {
    print(picked);
    cout << '\n';
    return;
  }
  // 고를 수 있는 가장 작은 번호를 계산한다.
  int smallest = 0;  // picked.empty() ? 0 : picked.back() + 1;
  // 이 단계에서 원소 하나를 고른다.
  for (int next = smallest; next < n; ++next) {
    if (find(picked.begin(), picked.end(), next) != picked.end()) continue;

    picked.push_back(next);
    perm_print(n, picked, toPick - 1);
    picked.pop_back();
  }
}

void perm_print(int n, vector<int>& src, vector<int>& picked,
                vector<bool>& visited, int toPick) {
  // 기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력한다.
  if (toPick == 0) {
    print(picked);
    cout << '\n';
    return;
  }
  for (int next = 0; next < n; ++next) {
    int e = src[next];
    if (visited[e]) continue;

    picked.push_back(e);
    visited[e] = true;
    perm_print(n, src, picked, visited, toPick - 1);
    picked.pop_back();
    visited[e] = false;
  }
}

void dfs(int N, int x, vector<int>& picked, vector<bool>& visited) {
  if (x > N) {
    print(picked);
    cout << '\n';
  }
  for (size_t i = 1; i <= N; i++) {
    if (!visited[i]) {
      picked.push_back(i);
      visited[i] = true;
      dfs(N, x + 1, picked, visited);
      picked.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N = 8;
  // cin >> N;

  //// fast
  // vector<int> picked;
  // vector<bool> visited(N + 1, false);
  // dfs(N, 1, picked, visited);

  //// fast
  vector<int> nodes;
  for (size_t i = 0; i < N; i++) {
    nodes.push_back(i + 1);
  }

  print(nodes);
  cout << '\n';

  vector<int> picked;
  vector<bool> visited(N + 1, false);
  perm_print(N, nodes, picked, visited, N);

  //// fast
  // vector<vector<int>> perm;
  // while (next_permutation(nodes.begin(), nodes.end())) {
  //   // perm.push_back(tmp);
  //   print(nodes);
  //   cout << '\n';
  // }
}
