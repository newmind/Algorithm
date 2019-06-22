#include <iostream>
#include <map>

/**
 * 피보나치 6
 * boj.kr/11444
 * 행렬곱셈
 *
 * https://www.acmicpc.net/blog/view/28
 * 피보나치 수 3번은 지금까지 풀었던 세 문제와 똑같이 N번째
 * 피보나치 수를 구하는 문제입니다. 그런데, N이 1018로 매우 큽니다. 다행히도
 * 1,000,000로 나눈 나머지를 출력하는 문제네요. 피보나치 수를 K로 나눈 나머지는
 * 항상 주기를 가지게 됩니다. 이를 피사노 주기(Pisano Period)라고 합니다.
 * 피보나치 수를 3으로 나누었을 때, 주기의 길이는 8입니다.
 *
 * 첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.
 */
using namespace std;

#define ll long long

map<ll, ll> d;
const ll mod = 1000000007LL;
ll fibo(ll n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else if (d.count(n) > 0) {
        return d[n];
    } else {
        if (n % 2 == 1) {
            ll m = (n+1) / 2;
            ll t1 = fibo(m);
            ll t2 = fibo(m-1);
            d[n] = t1*t1 + t2*t2;
            d[n] %= mod;
            return d[n];
        } else {
            ll m = n/2;
            ll t1 = fibo(m-1);
            ll t2 = fibo(m);
            d[n] = (2LL*t1 + t2)*t2;
            d[n] %= mod;
            return d[n];
        }
    }
}
int main() {
    ll n;
    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}