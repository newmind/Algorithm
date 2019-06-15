package net.acmicpc.p2108_4stats;

/*
https://www.acmicpc.net/problem/10989
counting sort
*/

import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    int[] counting = new int[8000 + 1];

    int sum = 0;
    int max = 0;

    int[] arr = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = Integer.parseInt(br.readLine()) + 4000;
      counting[arr[i]]++;
      sum += arr[i];
      if (arr[i] > max)
        max = arr[i];
    }

    if (N == 1) {
      int a = arr[0] - 4000;
      System.out.println(a + "\n" + a + "\n" + a + "\n0\n");
      return;
    }

    // sum of occurrence
    int maxCount = counting[0];
    int maxOccur = 0; // 3.최빈값
    for (int i = 1; i < counting.length && i <= max; i++) {
      if (counting[i] > maxCount) {
        maxCount = counting[i];
        maxOccur = i;
      }
      counting[i] += counting[i - 1];
    }

    // find second 최빈값
    int findCount = (counting[0] == maxCount) ? 1 : 0;
    for (int i = 1; i < counting.length && i <= max; i++) {
      if (counting[i] - counting[i - 1] == maxCount) {
        findCount++;
        maxOccur = i;
        if (findCount == 2)
          break;
      }
    }

    // counting sort
    int[] result = new int[N];
    for (int i = N - 1; i >= 0; i--) {
      int x = arr[i];
      result[counting[x]-- - 1] = x;
    }

    StringBuilder sb = new StringBuilder();
    // 1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
    sb.append(Math.round((float) sum / N) - 4000).append('\n');

    // 2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
    sb.append(result[N / 2] - 4000).append('\n');

    // 3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값, 같은 값 여러개면 두번째 최빈값
    sb.append(maxOccur - 4000).append('\n');

    // 4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
    sb.append(result[N - 1] - result[0]).append('\n');

    System.out.println(sb.toString());

    return;
  }
}
