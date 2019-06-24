#include <algorithm>
#include <iostream>
#include <sstream>

/**
 * K번째 수
 * boj.kr/11004
 */

using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

int main() {
  FASTIO;

  int N, K;
  cin >> N >> K;

  int arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

/*
  string line;
  line.reserve(5000000*9);
  std::getline(std::cin, line);
  while (line.length() == 0) {
    std::getline(std::cin, line);
  }

  stringstream ss(line);
  for (int i = 0; i < N; i++) {
    ss >> arr[i];
  }
*/

  sort(arr, arr+N);

  cout << arr[K-1] << endl;
  cout.flush();

  return 0;
}
