#include <iostream>
#include <string>

/**
 * 올바른 괄호
 * Parenthesis String, PS
 * Valid PS, VPS
 */

using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  string s;
  cin >> N;
  while (N--) {
    cin >> s;

    int count_open = 0;
    for (auto e: s) {
      if (e == '(') count_open++;
      else count_open--;
      if (count_open < 0) break;
    }
    if (count_open != 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  // cout.flush();
  return 0;
}