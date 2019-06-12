package net.acmicpc.p2675_str_print;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 선언
    // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    while (N-- > 0) {
      int multiple = br.read() - '0';
      // br.read();
      char[] str = br.readLine().toCharArray();// .trim();
      for (int i = 1; i < str.length; i++) {
        for (int j = 0; j < multiple; j++)
          // bw.write(c);
          sb.append(str[i]);
      }

      // bw.write('\n');
      sb.append('\n');
    }
    // bw.flush();
    System.out.print(sb.toString());
    return;
  }
}
