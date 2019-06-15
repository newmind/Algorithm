package net.acmicpc.p1181_word_sort;

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

    int N = Integer.parseInt(br.readLine());

    ArrayList<String> arr = new ArrayList<>();
    while (N-- > 0) {
      arr.add(br.readLine());
    }

    Collections.sort(arr, new Comparator<String>() {
      @Override
      public int compare(String a, String b) {
        if (a.length() == b.length())
          return a.compareTo(b);
        else
          return a.length() - b.length();
      }
    });

    String last = arr.get(0);
    bw.write(last + '\n');
    for (int i = 1; i < arr.size(); i++) {
      if (!last.equals(arr.get(i))) {
        last = arr.get(i);
        bw.write(last + '\n');
      }
    }

    bw.flush();
    return;
  }
}
