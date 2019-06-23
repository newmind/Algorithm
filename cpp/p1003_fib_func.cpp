#include <iostream>

/**
 * 피보나치 함수
 * boj.kr/1003

 0,1 의 갯수도 피보나치로 증가
 ll f0[45]={1,0,}, f1[45]={0,1,};

 for(int i=2;i<=40;i++){
		f0[i]=f0[i-1]+f0[i-2];
		f1[i]=f1[i-1]+f1[i-2];
 *
 */

using namespace std;

typedef long long ll;

int count0 = 0, count1 = 0;

ll fibo[40+1] = {0, 1};

ll fibonacci_prepare(ll n) {
    if (n == 0) {
        // count0++;
        return 0;
    } else if (n == 1) {
        // count1++;
        return 1;
    } else {
      if (fibo[n] == 0) {
        fibo[n] = fibonacci_prepare(n-1) + fibonacci_prepare(n-2);
      } else {
      }
      return fibo[n];
    }
}

// int fibonacci(int n) {
//     if (n == 0) {
//         count0++;
//         return 0;
//     } else if (n == 1) {
//         count1++;
//         return 1;
//     } else {
//       fibo[n] = fibonacci(n-1) + fibonacci(n-2);
//       return fibo[n];
//     }
// }

int main() {
  ll T = 0, n;
  cin >> T;

  fibonacci_prepare(40);
  while (T--) {
    cin >> n;
    cout << (n == 0? 1 : fibo[n-1]) << ' ' << fibo[n] << '\n';

    // test
    // count0 = 0, count1 = 0;
    // fibonacci(n);
    // cout << count0 << ' ' << count1 << '\n';
  }
  cout.flush();
  return 0;
}