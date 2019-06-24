#include <iostream>

/**
 * 정수 삼각형
 * boj.kr/1932
 */
using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

int main() {
  FASTIO;
  int N;
  cin >> N;

  int arr[N][N] = {{0,}, };
  for (size_t i = 1; i <= N; i++) {
    for (size_t j = 1; j <= i; j++) {
      cin >> arr[i-1][j-1];
    }
  }

  for (size_t i = 1; i < N; i++) {
    for (size_t j = 0; j <= i; j++) {
      if (j == 0)
        arr[i][j] += arr[i-1][0];
      else if (j == i) 
        arr[i][j] += arr[i-1][j-1];
      else 
        arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
    }
  }

  int m = 0;
  for (size_t i = 0; i < N; i++) {
    m = max(m, arr[N-1][i]);
  }
  
  cout << m << endl;
  return 0;
}
