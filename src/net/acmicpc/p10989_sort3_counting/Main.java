package net.acmicpc.p10989_sort3_counting;

/*
https://www.acmicpc.net/problem/10989
counting sort
*/

import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int N = Integer.parseInt(br.readLine());

    int[] counting = new int[10000 + 1];
    int max = 0;

    // 1.9s user, Arrays.sort() dual pivot
    int[] arr = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = Integer.parseInt(br.readLine());
      counting[arr[i]]++;
      if (arr[i] > max)
        max = arr[i];
    }

    // sum
    for (int i = 1; i < counting.length && i <= max; i++) {
      counting[i] += counting[i - 1];
    }

    int[] result = new int[N];
    for (int i = N - 1; i >= 0; i--) {
      int x = arr[i];
      result[counting[x]-- - 1] = x;
    }

    for (int i = 0; i < N; i++) {
      bw.write(result[i] + "\n");
    }

    bw.flush();
    return;
  }
}
