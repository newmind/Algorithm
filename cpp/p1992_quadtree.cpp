#include <iostream>
#include <vector>

/**
 * 쿼드트리
 * boj.kr/1992
 */

using namespace std;

string q_compress(vector<string>& v, int x, int y, int n) {
  if (n == 1) {
    return std::to_string(v[y][x] - '0');
  }
  string s1 = q_compress(v, x, y, n / 2);
  string s2 = q_compress(v, x + n / 2, y, n / 2);
  string s3 = q_compress(v, x, y + n / 2, n / 2);
  string s4 = q_compress(v, x + n / 2, y + n / 2, n / 2);
  if (s1.length() == 1 && s2.length() == 1 && s3.length() == 1 &&
      s4.length() == 1 && !s1.compare(s2) && !s2.compare(s3) &&
      !s3.compare(s4)) {
    return s1;
  } else {
    return "(" + s1 + s2 + s3 + s4 + ")";
  }
}

int main() {
  int N;
  cin >> N;

  vector<string> v(N);

  for (size_t i = 0; i < N; i++) {
    string s;
    std::getline(std::cin, s);
    while (s.length() == 0) std::getline(std::cin, s);
    v[i] = s;
  }

  string q_tree = q_compress(v, 0, 0, N);

  cout << q_tree << endl;
  return 0;
}
