#include <iostream>
#include <string>
#include <deque>

/**
 * 덱
 * boj.kr/10866
 */
using namespace std;

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  deque<int> q;

  int N;
  cin >> N;
  while (N--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push_back") {
      int op;
      cin >> op;
      q.push_back(op);
    } else if  (cmd == "push_front") {
      int op;
      cin >> op;
      q.push_front(op);
    } else if (cmd == "pop_back") {
      cout << (q.empty()? -1 : q.back()) << '\n';
      if (!q.empty()) q.pop_back();
    } else if (cmd == "pop_front") {
      cout << (q.empty()? -1 : q.front()) << '\n';
      if (!q.empty()) q.pop_front();
    } else if (cmd == "size") {
      cout << q.size() << '\n';
    } else if (cmd == "empty") {
      cout << (q.empty()? 1: 0) << '\n';
    } else if (cmd == "front") {
      cout << (q.empty() ? -1 : q.front()) << '\n';
    } else if (cmd == "back") {
      cout << (q.empty()? -1 : q.back()) << '\n';
    }
  }
  cout.flush();
  return 0;
}
