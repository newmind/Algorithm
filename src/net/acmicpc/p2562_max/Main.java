package net.acmicpc.p2562_max;

/*
https://www.acmicpc.net/problem/1181
단어 정렬
길이가 짧은 것부터
길이가 같으면 사전 순으로
*/

import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int N = 9;

    ArrayList<Integer> arr = new ArrayList<>();
    while (N-- > 0) {
      arr.add(Integer.parseInt(br.readLine()));
    }

    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (max < arr.get(i)) {
        max = arr.get(i);
        maxIndex = i;
      }
    }
    bw.write(max + "\n");
    bw.write(maxIndex + 1 + "\n");
    bw.flush();
    return;
  }
}
