/* (A+B)%C는 (A%C + B%C)%C 와 같을까?

(A×B)%C는 (A%C × B%C)%C 와 같을까?
 */

#include <iostream>
using namespace std;
int main()
{
  auto A = 0, B = 0, C = 0;
  cin >> A >> B >> C;
  // cout << fixed;
  // cout.precision(9);
  cout << (A + B) % C << endl;
  cout << (A % C + B % C) % C << endl;
  cout << (A * B) % C << endl;
  cout << (A % C * B % C) % C << endl;
  return 0;
}