package net.acmicpc.p2581_prime_range;

/*
https://www.acmicpc.net/problem/2581
소수 찾기, 합, 최소값
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

    int M = Integer.parseInt(br.readLine());
    int N = Integer.parseInt(br.readLine());

    ArrayList<Integer> result = new ArrayList<>();
    int sum = 0;
    for (int i = M; i <= N; i++) {
      if (isPrime(i)) {
        result.add(i);
        sum += i;
      }
    }
    if (sum == 0)
      System.out.println(-1);
    else {
      System.out.println(sum);
      System.out.println(result.get(0));
    }
  }
}
