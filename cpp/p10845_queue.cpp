#include <iostream>
#include <string>

/**
 * 큐
 */
using namespace std;

struct Queue {
  int buf[10001];
  int _back = -1;
  int _front = -1;
  void push(int a) {
    buf[++_back] = a;
  }
  int pop() {
    if (empty()) return -1;
    return buf[++_front];
  }
  int size() { return _back - _front; }
  int empty() { return _front == _back ? 1 : 0; }
  int front() {
    if (empty()) return -1;
    return buf[_front+1];
  }
  int back() {
    if (empty()) return -1;
    return buf[_back];
  }
};

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  Queue q;

  int N;
  cin >> N;
  while (N--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int op;
      cin >> op;
      q.push(op);
    } else if (cmd == "pop") {
      cout << q.pop() << '\n';
    } else if (cmd == "size") {
      cout << q.size() << '\n';
    } else if (cmd == "empty") {
      cout << q.empty() << '\n';
    } else if (cmd == "front") {
      cout << q.front() << '\n';
    } else if (cmd == "back") {
      cout << q.back() << '\n';
    }
  }
  cout.flush();
  return 0;
}
