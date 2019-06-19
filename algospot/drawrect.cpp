#include <iostream>

/**
 * https://algospot.com/judge/problem/read/DRAWRECT
 *
 */
using namespace std;

int main() {
  unsigned int T, x[3], y[3];
  cin >> T;
  while (T--) {
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    if (x[0] == x[1])
	    cout << x[2];
    else if (x[0] == x[2])
      cout << x[1];
    else
      cout << x[0];
    cout << ' ';

    if (y[0] == y[1])
	    cout << y[2];
    else if (y[0] == y[2])
      cout << y[1];
    else
      cout << y[0];
    cout << endl;
  }
}
