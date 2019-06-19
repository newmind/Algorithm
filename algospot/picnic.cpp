#include <iostream>
#include <memory>
#include <vector>

/**
 * https://algospot.com/judge/problem/read/PICNIC
 * 소풍,  조합 짝 짓기
 */
using namespace std;

int countPair(vector<bool>& taken, bool areFriends[][10]) {
  int firstFree = -1;
  for (int i = 0; i < taken.size(); i++) {
    if (!taken[i]) {
      firstFree = i;
      break;
    }
  }

  if (firstFree == -1) return 1;
  int ret = 0;
  for (int to = firstFree + 1; to < taken.size(); to++) {
    if (!taken[to] && areFriends[firstFree][to]) {
      taken[to] = taken[firstFree] = true;
      ret += countPair(taken, areFriends);
      taken[to] = taken[firstFree] = false;
    }
  }

  return ret;
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int C;
  cin >> C;

  while (C--) {
    int n, m;
    cin >> n >> m;

    vector<bool> taken(n);
    bool areFriends[10][10] = {
        {
            false,
        },
    };

    while (m--) {
      int a, b;
      cin >> a >> b;
      areFriends[a][b] = true;
      areFriends[b][a] = true;
    }
    cout << countPair(taken, areFriends) << endl;
  }
  return 0;
}