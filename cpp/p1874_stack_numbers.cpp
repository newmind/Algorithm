#include <iostream>
#include <sstream>
#include <string>

/**
 * 스택 수열
 * https://www.acmicpc.net/problem/1874
 */
using namespace std;

struct Stack {
  int buf[100001];
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

  stringstream ss;
  Stack stack;

  int N;
  cin >> N;
  int input[N];
  for (int i = 0; i < N; i++) {
    cin >> input[i];
  }

  int input_i = 0;
  for (int i = 1; i <= N; i++) {
    stack.push(i);
    ss << "+\n";

    while (!stack.empty() && stack.top() == input[input_i]) {
      stack.pop();
      ss << "-\n";
      input_i++;
    }
  }

  if (stack.size() == 0)
    cout << ss.str();
  else
    cout << "NO" << endl;
  return 0;
}
