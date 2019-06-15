package net.acmicpc.p2667_apart;

/*
https://www.acmicpc.net/problem/2667
단지번호붙이기 (두더지굴))
*/

import java.io.*;
import java.util.*;

public class Main {

  private static int dfs(short[][] arr, int x, int y, short c) {
    if (arr[y][x] == 0)
      return 0;

    final int N = arr.length;
    int count = 1;
    arr[y][x] = c; // 지나간 곳은 c 으로

    if (y - 1 >= 0 && arr[y - 1][x] == 1)
      count += dfs(arr, x, y - 1, c);
    if (x + 1 < N && arr[y][x + 1] == 1)
      count += dfs(arr, x + 1, y, c);
    if (y + 1 < N && arr[y + 1][x] == 1)
      count += dfs(arr, x, y + 1, c);
    if (x - 1 >= 0 && arr[y][x - 1] == 1)
      count += dfs(arr, x - 1, y, c);

    return count;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int N = Integer.parseInt(br.readLine());
    short[][] arr = new short[N][N];

    for (int y = 0; y < N; y++) {
      String s = br.readLine();
      for (int x = 0; x < N; x++) {
        arr[y][x] = (short) (s.charAt(x) - '0');
      }
    }

    short c = 2;
    ArrayList<Integer> result = new ArrayList<>();
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (arr[y][x] == 1) {
          int count = dfs(arr, x, y, c);
          if (count > 0) {
            result.add(count);
            c++;
          }
        }
      }
    }
    // print(arr);

    result.sort(Comparator.naturalOrder());

    bw.write(result.size() + "\n");
    for (int e : result) {
      bw.write(e + "\n");
    }

    bw.flush();

    return;
  }

  public static void print(short[][] arr) {
    int n = arr.length;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(arr[i][j]);
      }
      System.out.println();
    }
  }
}
