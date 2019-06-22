#include <iostream>

/**
 * 곱셈 빠른 제곱
 * boj.kr/1629
 */
using namespace std;

typedef long long ll;

ll fast_pow(ll a, ll n, int mod) {
  if (n == 0)
    return 1;
  if (n%2 == 1)
    return (fast_pow(a, n-1, mod) * a) % mod;
  ll half = fast_pow(a, n/2, mod) % mod;
  return (half * half) % mod;
}

ll fast_pow2(int A, int B, int C) {
  ll ans = 1;
	while (B > 0)
	{
		if (B % 2 == 1) ans =(ans*A)%C;
		A = (A*A) % C;
		B /= 2;
	}
  return ans;
}

int main() {
  ll a, b, mod;
  cin >> a >> b >> mod;

  cout << fast_pow(a, b, mod) << endl;
  return 0;
}