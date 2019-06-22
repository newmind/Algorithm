#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * 회전하는 큐
 * boj.kr/1021
 */
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<int> arr(N);
  for (size_t i = 0; i < N; i++) {
    arr[i] = i + 1;
  }

  int count = 0;
  int center = 0;
  while (M--) {
    int x;
    cin >> x;

    int i = 0;
    for (; i < arr.size(); i++) {
      if (arr[i] == x) break;
    }
    if (i > center)
      count += min(i - center, center + (int)(arr.size() - i));
    else if (i < center) {
      count += min(center - i, (int)(arr.size() - center) + i);
    }
    arr.erase(arr.begin() + i);
    center = i;
  }

  cout << count << endl;
  cout.flush();
  return 0;
}
