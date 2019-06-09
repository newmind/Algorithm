#include <stdio.h>

#define MAX 10000
bool dp[MAX + 1] = {
    1,
};

void d(int n) {
  if (n >= MAX)
    return;
  n = n + (n / 1000 % 10) + (n / 100 % 10) + (n / 10 % 10) + (n % 10);
  if (n <= MAX)
    dp[n] = 1;
}

int main() {
  for (size_t i = 1; i <= MAX; i++) {
    d(i);
  }

  for (int i = 1; i <= MAX; i++) {
    if (dp[i] == 0) {
      printf("%d\n", i);
    }
  }
}