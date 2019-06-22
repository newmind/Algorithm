#include <deque>
#include <iostream>
#include <string>
#include <vector>

#define FASTIO        \
  std::cin.tie(NULL); \
  std::ios::sync_with_stdio(false);

/**
 * AC
 * boj.kr/5430
 */
using namespace std;

int main() {
  FASTIO;

  int T;
  cin >> T;
  while (T--) {
    string cmd, s;
    int n;
    cin >> cmd >> n >> s;

    deque<string> dq;
    for (size_t i = 1; i < s.length() - 1; i++) {
      int pos = s.find(',', i);
      if (pos != string::npos) {
        string sub = s.substr(i, pos - i);
        dq.push_back(sub);
        i = pos;
      } else {
        string sub = s.substr(i, s.length() - 1 - i);
        dq.push_back(sub);
        break;
      }
    }

    bool error = false;
    bool reverse = false;
    int left = 0;
    int right = dq.size() - 1;
    for (auto e : cmd) {
      if (e == 'R') {
        reverse = !reverse;
      } else {
        if (left > right) {
          error = true;
          break;
        }
        if (reverse)
          right--;
        else
          left++;
      }
    }

    if (error) {
      cout << "error" << '\n';
    } else {
      int begin = reverse ? right : left;
      int end = reverse ? left - 1 : right + 1;
      int inc = reverse ? -1 : 1;
      cout << "[";
      for (size_t i = begin; i != end; i += inc) {
        cout << dq[i];
        if (i + inc != end) cout << ",";
      }
      cout << "]" << '\n';
    }
  }
  cout.flush();
  return 0;
}
