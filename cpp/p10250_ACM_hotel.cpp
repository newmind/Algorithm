#include <cstdio>

/**
 * ACM 호텔
 * 10250
 */

using namespace std;

int main() {
  int T, h, w, n;
  scanf("%d", &T);

  while (T--) {
    scanf("%d %d %d", &h, &w, &n);
    n--;
    printf("%d%02d\n", (n%h)+1, (int)(n/h) + 1);
  }
  return 0;
}
