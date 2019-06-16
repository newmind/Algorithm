package net.acmicpc.p9020_prime_goldbach;

/*
https://www.acmicpc.net/problem/9020
소수 찾기
골드바흐의 추측
골드바흐의 추측은 유명한 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다.
이러한 수를 골드바흐 수라고 한다. 또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다.
예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다. 10000보다 작거나 같은
모든 짝수 n에 대한 골드바흐 파티션은 존재한다.
2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오.
만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.
*/

import java.io.*;
import java.util.*;

public class Main {

  public static boolean[] primes = getPrime(10000);

  private static boolean[] getPrime(int N) {
    boolean[] arr = new boolean[N + 1];
    arr[0] = arr[1] = false;
    for (int i = 2; i < N + 1; i++) {
      arr[i] = true;
    }
    for (int i = 2; i * i <= N; i++) {
      if (arr[i]) {
        for (int j = i * i; j <= N; j += i) {
          arr[j] = false;
        }
      }
    }
    return arr;
  }

  private static boolean isPrime(int i) {
    return primes[i];
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int T = Integer.parseInt(br.readLine());
    while (T-- > 0) {
      int n = Integer.parseInt(br.readLine());

      for (int i = n / 2; i >= 2; i--) {
        int j = n - i;
        if (isPrime(i) && isPrime(j) && i + j == n) {
          sb.append(i).append(' ').append(j).append('\n');
          break;
        }
      }
    }
    System.out.println(sb.toString());
  }
}

class InputReader {

  private final InputStream stream;
  private final byte[] buf = new byte[8192];
  private int curChar, snumChars;

  public InputReader(InputStream st) {
    this.stream = st;
  }

  public int read() {
    if (snumChars == -1)
      throw new InputMismatchException();
    if (curChar >= snumChars) {
      curChar = 0;
      try {
        snumChars = stream.read(buf);
      } catch (IOException e) {
        throw new InputMismatchException();
      }
      if (snumChars <= 0)
        return -1;
    }
    return buf[curChar++];
  }

  public int nextInt() {
    int c = read();
    while (isSpaceChar(c)) {
      c = read();
    }
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    int res = 0;
    do {
      res *= 10;
      res += c - '0';
      c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
  }

  public long nextLong() {
    int c = read();
    while (isSpaceChar(c)) {
      c = read();
    }
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    long res = 0;
    do {
      res *= 10;
      res += c - '0';
      c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
  }

  public int[] nextIntArray(int n) {
    int a[] = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = nextInt();
    }
    return a;
  }

  public String readString() {
    int c = read();
    while (isSpaceChar(c)) {
      c = read();
    }
    StringBuilder res = new StringBuilder();
    do {
      res.appendCodePoint(c);
      c = read();
    } while (!isSpaceChar(c));
    return res.toString();
  }

  public String nextLine() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    StringBuilder res = new StringBuilder();
    do {
      res.appendCodePoint(c);
      c = read();
    } while (!isEndOfLine(c));
    return res.toString();
  }

  public boolean isSpaceChar(int c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
  }

  private boolean isEndOfLine(int c) {
    return c == '\n' || c == '\r' || c == -1;
  }
}
