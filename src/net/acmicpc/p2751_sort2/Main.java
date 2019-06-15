package net.acmicpc.p2751_sort2;

/*
https://www.acmicpc.net/problem/2751
merge, heap sort
*/

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int N = Integer.parseInt(br.readLine());

    //// 1.9s user, Arrays.sort() dual pivot
    // int[] arr = new int[N];
    // for (int i = 0; i < N; i++) {
    // arr[i] = Integer.parseInt(br.readLine());
    // }
    // Arrays.sort(arr);
    // for (int i = 0; i < N; i++) {
    // bw.write(arr[i] + "\n");
    // }

    //// collections.sort
    ArrayList<Integer> arr = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      arr.add(Integer.parseInt(br.readLine()));
    }
    Collections.sort(arr);
    for (int i = 0; i < N; i++) {
      bw.write(arr.get(i) + "\n");
    }

    //// 3.0s user, treeset
    // SortedSet<Integer> sset = new TreeSet<>();
    // for (int i = 0; i < N; i++) {
    // sset.add(Integer.parseInt(br.readLine()));
    // }
    // Iterator it = sset.iterator();
    // while (it.hasNext()) {
    // bw.write(it.next() + "\n");
    // }

    bw.flush();
    return;
  }
}
