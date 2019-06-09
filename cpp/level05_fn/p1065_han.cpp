#include <stdio.h>
// 한수
// 등차수열 갯수

int main() {
  int N, cnt = 0;
  scanf("%d", &N);

  if (N >= 1000) N = 999;

  for (size_t i = 1; i <= N; i++) {
    if (i < 100)
      cnt++;
    else {
      int n1 = i % 10;
      int n2 = i / 10 % 10;
      int n3 = i / 100 % 10;
      if (n1 - n2 == n2 - n3) cnt++;
    }
  }

  printf("%d", cnt);
}