#include <iostream>
#include <string>

using namespace std;
int main() {
  auto a = 0;
  string s;
  cin >> a;
  cin >> s;
  a = 0;
  for (size_t i = 0; i < s.size(); i++) {
    a += s[i] - '0';
  }

  cout << a << endl;
  return 0;
}