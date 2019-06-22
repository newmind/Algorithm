#include <iostream>

/**
 * 피보나치3
 * boj.kr/2749
 * 피사노 주기
 * https://www.acmicpc.net/blog/view/28
 * 2749번 문제: 피보나치 수 3번은 지금까지 풀었던 세 문제와 똑같이 N번째
 * 피보나치 수를 구하는 문제입니다. 그런데, N이 1018로 매우 큽니다. 다행히도
 * 1,000,000로 나눈 나머지를 출력하는 문제네요. 피보나치 수를 K로 나눈 나머지는
 * 항상 주기를 가지게 됩니다. 이를 피사노 주기(Pisano Period)라고 합니다.
 * 피보나치 수를 3으로 나누었을 때, 주기의 길이는 8입니다.
 * 첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.
 */
using namespace std;

typedef long long ll;

const int mod = 1000000;
const int p = mod/10*15; // 피보나치 수를 3으로 나누었을 때, 주기의 길이는 8 (2^3) 임.
int fibo[p] = {0, 1, 1};

int main() {
  ll n = 0;
  cin >> n;

  for (size_t i = 2; i < p; i++) {
    fibo[i] = fibo[i-1] + fibo[i-2];
    fibo[i] %= mod;
  }

  cout << fibo[n%p] << endl;
  return 0;
}