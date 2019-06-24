#include <iostream>

/**
 * RGB거리
 * boj.kr/1149
 */
using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

int main() {
  FASTIO;
  int N;
  cin >> N;

  int arr[N][3];
  for (size_t i = 0; i < N; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  for (size_t i = 1; i < N; i++) {
    arr[i][0] += min(arr[i-1][1], arr[i-1][2]);
    arr[i][1] += min(arr[i-1][0], arr[i-1][2]);
    arr[i][2] += min(arr[i-1][0], arr[i-1][1]);
  }

  cout << min(arr[N-1][2], min(arr[N-1][0], arr[N-1][1])) << endl;
  return 0;
}
