#include <stdio.h>

int main() {
  int N, t = 0, cnt = 0;
  scanf("%d", &N);

  t = N;
  do {
    int sum = (t / 10) + (t % 10);
    t = (t % 10) * 10 + (sum % 10);
    cnt++;
  } while (t != N);

  printf("%d", cnt);
}