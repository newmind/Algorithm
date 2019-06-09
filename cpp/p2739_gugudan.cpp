#include <iostream>
#include <sstream>

using namespace std;
int main() {
  int N;
  cin >> N;
  stringstream s;
  for (int i = 1; i <= 9; i++) {
    s << N << " * " << i << " = " << N * i << endl;
  }

  cout << s.str();
  return 0;
}