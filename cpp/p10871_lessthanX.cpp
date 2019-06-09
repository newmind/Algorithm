#include <iostream>

using namespace std;
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N, X, t;
  cin >> N >> X;
  while (N--) {
    cin >> t;
    if (t < X)
      cout << t << ' ';
  }
  return 0;
}
