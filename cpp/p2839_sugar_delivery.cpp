#include <iostream>
using namespace std;

// 첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)
// 상근이가 배달하는 봉지의 최소 개수를 출력한다. 만약, 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.

int main()
{
  auto A = 0;
  cin >> A;

  int n5 = A / 5;
  int n3 = (A % 5) / 3;
  int n3mod = (A % 5) % 3;
  while (n5 > 0 && n3mod != 0)
  {
    n5--;
    n3 = (A - (5 * n5)) / 3;
    n3mod = (A - (5 * n5)) % 3;
  }
  int r = (n3mod > 0) ? -1 : (n5 + n3);
  cout << r << endl;
  return 0;
}