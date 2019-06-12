#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
// 별 11

using namespace std;

template <typename T>
void print(std::vector<T> const& input) {
  for (int i = 0; i < input.size(); i++) {
    std::cout << input.at(i);// << ' ';
  }
}
void print(int n) { std::cout << n << '\n'; }

using star_vec = vector<vector<char>>;

char* star[] = {"  *   ", 
                " * *  ", 
                "***** "};

void draw(star_vec& vec, int x, int y, int n) {
  if (n == 3) {
    vec[y][x+2] = '*';
    vec[y+1][x+1] = '*';
    vec[y + 1][x + 3] = '*';
    memset(&vec[y+2][x], '*', 5);
    return;
  }
  draw(vec, x + n / 2, y, n / 2);
  draw(vec, x, y + n / 2, n / 2);
  draw(vec, x + n, y + n / 2, n / 2);
}

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int N = 12;
  cin >> N;

  star_vec vec(N, vector<char>(N * 2, ' '));

  draw(vec, 0, 0, N);
  for (auto& e: vec) {
      print(e);
      cout << '\n';
  }
}