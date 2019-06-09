// 열 개씩 끊어 출력하기
#include <iostream>
#include <string>

using namespace std;
int main() {
  string s;
  cin >> s;
  for (size_t i = 0; i < s.size(); i++) {
    putchar(s[i]);
    if ((i + 1) % 10 == 0)
      putchar('\n');
  }

  return 0;
}