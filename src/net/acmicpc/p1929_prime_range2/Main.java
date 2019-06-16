package net.acmicpc.p1929_prime_range2;

/*
https://www.acmicpc.net/problem/1929
소수 찾기
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
*/

import java.io.*;

public class Main {

  public static boolean[] primes = getPrime(1000000);

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

    String[] input = br.readLine().split(" ");
    int M = Integer.parseInt(input[0]);
    int N = Integer.parseInt(input[1]);

    for (int i = M; i <= N; i++) {
      if (isPrime(i)) {
        bw.write(i + "\n");
      }
    }
    bw.flush();
  }
}
