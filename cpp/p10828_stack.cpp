#include <iostream>
#include <string>

/**
 * 스택
명령은 총 다섯 가지이다.
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 스택에 들어있는 정수의 개수를
출력한다. empty: 스택이 비어있으면 1, 아니면 0을 출력한다. top: 스택의 가장 위에
있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

 */
using namespace std;

struct Stack {
  int buf[10001];
  int head = -1;
  void push(int a) { buf[++head] = a; }
  int pop() {
    if (head == -1) return -1;
    return buf[head--];
  }
  int size() { return head + 1; }
  int empty() { return head == -1 ? 1 : 0; }
  int top() {
    if (head == -1) return -1;
    return buf[head];
  }
};

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  Stack stack;

  int N;
  cin >> N;
  while (N--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int op;
      cin >> op;
      stack.push(op);
    } else if (cmd == "pop") {
      cout << stack.pop() << '\n';
    } else if (cmd == "size") {
      cout << stack.size() << '\n';
    } else if (cmd == "empty") {
      cout << stack.empty() << '\n';
    } else if (cmd == "top") {
      cout << stack.top() << '\n';
    }
  }
  cout.flush();
  return 0;
}
