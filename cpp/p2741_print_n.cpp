#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main() {
  auto a = 0;
  cin >> a;
  stringstream s;
  int i = 1;
  while (i <= a) {
    // s += (i != a) ? to_string(i) + '\n' : to_string(i);
    s << i << endl;
    ++i;
  }
  // cout << s.str();
  return 0;
}