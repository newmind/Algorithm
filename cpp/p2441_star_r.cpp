#include <iostream>
#include <sstream>

using namespace std;
int main() {
  int N;
  cin >> N;
  stringstream s;
  for (int i = N; i > 0; i--) {
    for (int j = 1; j <= N; j++) s << ((N - j < i) ? "*" : " ");
    s << endl;
  }

  cout << s.str();
  return 0;
}