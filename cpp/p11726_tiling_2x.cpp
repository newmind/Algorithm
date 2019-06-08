#include <iostream>
using namespace std;

int tiling_2x(int n)
{
  int answer = 0;
  if (n < 3)
    return n;

  int n_1 = 1;
  int n_2 = 2;

  for (int i = 3; i <= n; ++i)
  {
    int n_3 = (n_2 + n_1);
    n_1 = n_2 % 10007;
    n_2 = n_3 % 10007;
  }
  return n_2;
}

int main()
{
  auto a = 0;
  cin >> a;

  cout << tiling_2x(a) << endl;
  return 0;
}