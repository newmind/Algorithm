#include <iostream>
#include <string>

/**
 * https://algospot.com/judge/problem/read/ENDIANS
 *
 */
using namespace std;

int main() {
  unsigned int C, d;
  cin >> C;
  while (C--) {
    cin >> d;
    unsigned int d2 = (d << 24) | ((d<<8) & 0xFF0000) | ((d>>8) & 0xFF00) | ((d>>24) & 0xFF);
	  cout << d2 << endl;
  }
}
