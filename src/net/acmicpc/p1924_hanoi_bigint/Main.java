package net.acmicpc.p1924_hanoi_bigint;

/*
https://www.acmicpc.net/problem/1924
하노이탑 BigInteger
*/

import java.io.*;
import java.math.BigInteger;

public class Main {

  static void hanoi(int N, char from, char to, char aux) {
    if (N == 1) {
      System.out.println(from + " " + to);
    } else {
      hanoi(N - 1, from, aux, to);
      System.out.println(from + " " + to);
      hanoi(N - 1, aux, to, from);
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    if (N == 1) {
      System.out.println(1);
      return;
    }

    BigInteger r = new BigInteger("1");
    for (int i = 0; i < N; i++) {
      r = r.multiply(new BigInteger("2"));
    }
    r = r.subtract(new BigInteger("1"));

    System.out.println(r);

    if (N <= 20) {
      hanoi(N, '1', '3', '2');
    }
  }
}
