#include <stdio.h>
#include <vector>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  while (N--) {
    int n, t, s = 0, m = 0;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &t);
      s += t;
      v.push_back(t);
      if (t > m)
        m = t;
    }
    double avg = (double)s / n;
    int s_high = 0;
    for (auto e : v) {
      if (e > avg)
        s_high++;
    }
    printf("%.3lf%%\n", s_high / double(n) * 100);
  }
  return 0;
}
