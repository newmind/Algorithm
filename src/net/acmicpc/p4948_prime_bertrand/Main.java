package net.acmicpc.p4948_prime_bertrand;

/*
https://www.acmicpc.net/problem/4948
소수 찾기
베르트랑 공준
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
*/

import java.io.*;

public class Main {

  public static boolean[] primes = getPrime(123456 * 2);

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

    while (true) {
      int n = Integer.parseInt(br.readLine());
      if (n == 0)
        break;

      int count = 0;
      for (int i = n + 1; i <= n * 2; i++) {
        if (isPrime(i))
          count++;
      }
      bw.write(count + "\n");
    }

    bw.flush();
  }
}
