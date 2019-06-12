package net.acmicpc.p2675_str_print;

import java.util.StringTokenizer;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 선언
    // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    while (N-- > 0) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      // int multiple = br.read() - '0';
      int multiple = Integer.parseInt(st.nextToken());
      // br.read();
      // char[] str = br.readLine().toCharArray();
      char[] str = st.nextToken().toCharArray();
      for (int i = 0; i < str.length; i++) {
        for (int j = 0; j < multiple; j++)
          // bw.write(str[i]);
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
