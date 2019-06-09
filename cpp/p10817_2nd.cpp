#include <iostream>

using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((a >= b || a >= c) && (a <= c || a <= b))
    cout << a << endl;
  else if ((b >= a || b >= c) && (b <= c || b <= a))
    cout << b << endl;
  else if ((c >= a || c >= b) && (c <= b || c <= a))
    cout << c << endl;
  return 0;
}

/*
int main()
{
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);
        printf("%d", a > b ? (c > a ? a : (c > b ? c : b)) : (c > b ? b : (a > c
? a : c)));

        return 0;
}
 */