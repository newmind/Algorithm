package net.acmicpc.p5622_dial;

/*
다이얼
https://www.acmicpc.net/problem/5622
*/

import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int answer = 0;
    int[] seconds = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

    char[] dial = br.readLine().toCharArray();
    for (int i = 0; i < dial.length; i++) {
      answer += seconds[dial[i] - 'A'];
    }
    System.out.println(answer);
    return;
  }
}
