package net.acmicpc.p1427_reverse_sort;

/*
https://www.acmicpc.net/problem/1427
숫자 하나 거꾸로 정렬
*/

import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    String[] arr = br.readLine().split("");

    Arrays.sort(arr, Comparator.reverseOrder());
    for (int i = 0; i < arr.length; i++) {
      bw.write(arr[i]);
    }

    bw.flush();
    return;
  }
}
