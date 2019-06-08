#include <iostream>
using namespace std;
int main()
{
  auto a = 0, b = 0;
  cin >> a >> b;
  cout << fixed;
  cout.precision(9);
  cout << (double)a / b << endl;
  return 0;
}