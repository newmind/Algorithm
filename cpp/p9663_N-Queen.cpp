#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 15;
bool _col[N] = {false,};
bool _slash[N * 2 - 1] = {false,};  //   slash / , i = x+y
bool _slash2[N * 2 - 1] = {false,};  //   back slash \ , i = 3+(x-y)

int g_count = 0;

void find_queen(int n, int y, int q_count) {
  if (n == y) {
    g_count++;
    return;
  }

  int n2 = n; 
  if (y == 0) n2 = n/2; // 최적화, 좌우 대칭이므로 

  for (size_t i = 0; i < n2; i++) {
    if (_col[i] || _slash[i + y] || _slash2[n + (i - y)]) continue;
    _col[i] = _slash[i + y] = _slash2[n + (i - y)] = true;
    find_queen(n, y + 1, q_count + 1);
    _col[i] = _slash[i + y] = _slash2[n + (i - y)] = false;
  }

  // 최적화, 좌우 대칭이므로 
  if (y == 0) {
      g_count *= 2;
      if (n % 2) { // 홀수이면 가운데 하나에 대한거따로 계산
        int i = n2;
        _col[i] = _slash[i + y] = _slash2[n + (i - y)] = true;
        find_queen(n, y + 1, q_count + 1);
        _col[i] = _slash[i + y] = _slash2[n + (i - y)] = false;
      }
  } 

  return;
}

int solution(int n) {
  int answer = 0;
  if (n == 1) return 1;
  if (n <= 3) return 0;

  g_count = 0;
  find_queen(n, 0, 0);

  return g_count;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cout << solution(n) << endl;
  
//   cout << solution(4) << endl;
//   cout << solution(8) << endl;
//   cout << solution(10) << endl;
//   cout << solution(14) << endl;
}
