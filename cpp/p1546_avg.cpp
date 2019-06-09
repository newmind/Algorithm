// #include <vector>
// using namespace std;
// int main() {
//   int N, t, max = 0;
//   scanf("%d", &N);
//   vector<int> v;
//   while (N--) {
//     scanf("%d", &t);
//     v.push_back(t);
//     max = t > max ? t : max;
//   }
//   double total = 0;
//   for (auto e : v) {
//     total += e / (double)max * 100;
//   }
//   printf("%lf", total / v.size());
//   return 0;
// }

#include <stdio.h>
int main() {
  int N, t, a = 0, max = 0;
  scanf("%d", &N);
  int count = N;
  while (count--) {
    scanf("%d", &t);
    a += t;
    max = t > max ? t : max;
  }
  double nsum = (double)a / max * 100;
  printf("%lf", nsum / N);
  return 0;
}
