#include <iostream>

/**
 * quadtree
 * https://algospot.com/judge/problem/read/QUADTREE
 */
using namespace std;

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

string reverse(string& s, int& i) {
  int ch = s[i++];
  if (ch != 'x') {
    return string(1, ch);
  }
  string tl = reverse(s, i);
  string tr = reverse(s, i);
  string bl = reverse(s, i);
  string br = reverse(s, i);
  return "x" + bl + br + tl + tr;
}

int main() {
  FASTIO;

  // {
  //   int i = 0;
  //   string s = "w";
  //   cout << reverse(s, i, s.length()) << endl;
  //   i = 0;
  //   s = "xbwwb";
  //   cout << reverse(s, i, s.length()) << endl;
  //   i = 0;
  //   s = "xbwxwbbwb";
  //   cout << reverse(s, i, s.length()) << endl;
  //   i = 0;
  //   s = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb";
  //   cout << reverse(s, i, s.length()) << endl;
  // }

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;
    int i = 0;
    cout << reverse(s, i) << endl;
  }
}
