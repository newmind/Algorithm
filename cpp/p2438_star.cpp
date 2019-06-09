#include <iostream>
#include <sstream>

using namespace std;
int main() {
  int N;
  cin >> N;
  stringstream s;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) s << "*";
    s << endl;
  }

  cout << s.str();
  return 0;
}