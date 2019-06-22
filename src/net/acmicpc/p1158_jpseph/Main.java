package net.acmicpc.p1158_jpseph;

/**
 * 조세퍼스 문제
 * boj.kr/1158
 */

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 선언
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.valueOf(st.nextToken());
    int K = Integer.valueOf(st.nextToken());

    ArrayList<Integer> arr = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      arr.add(i + 1);
    }

    sb.append('<');
    K--;
    int i = 0;
    while (arr.size() > 0) {
      i += K;
      i %= arr.size();
      sb.append(arr.get(i));
      arr.remove(i);
      sb.append(", ");
    }
    sb.replace(sb.length() - 2, sb.length(), ">");

    System.out.println(sb.toString());
    return;
  }
}
