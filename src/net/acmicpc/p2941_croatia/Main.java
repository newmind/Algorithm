package net.acmicpc.p2941_croatia;

/*
크로아티아 알파벳
https://www.acmicpc.net/problem/2941
*/

import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String str = br.readLine().trim();
    str = str.replace("c=", "A");
    str = str.replace("c-", "B");
    str = str.replace("dz=", "C");
    str = str.replace("d-", "D");
    str = str.replace("lj", "E");
    str = str.replace("nj", "Z");
    str = str.replace("s=", "F");
    str = str.replace("z=", "G");
    System.out.println(str.length());
    return;
  }
}
