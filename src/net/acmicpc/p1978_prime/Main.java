package net.acmicpc.p1978_prime;

/*
https://www.acmicpc.net/problem/1978
소수 찾기
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
출력
주어진 수들 중 소수의 개수를 출력한다.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Main {

  public static boolean[] primes = getPrime(1000);

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

  private static boolean isPrime(short i) {
    return primes[i];
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());

    short countPrime = 0;
    for (int i = 0; i < N; i++) {
      if (isPrime(Short.parseShort(st.nextToken())))
        countPrime++;
    }

    System.out.println(countPrime);
  }

}
