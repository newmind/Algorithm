#include <stdio.h>

int main() {
  int answer = 0;
  bool inWord = false;
  while (int ch = getchar()) {
    if (ch == '\n') break;
    if (ch != ' ') {
      inWord = true;
    }
    if (inWord && ch == ' ') {
      answer++;
      inWord = false;
    }
  }
  if (inWord) answer++;
  printf("%d", answer);
}