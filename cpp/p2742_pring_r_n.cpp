#include <iostream>
#include <sstream>

using namespace std;
int main() {
  auto a = 0;
  cin >> a;
  stringstream s;
  while (a > 0) {
    s << a << endl;
    --a;
  }
  cout << s.str();
  return 0;
}