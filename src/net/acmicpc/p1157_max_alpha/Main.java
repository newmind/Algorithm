package net.acmicpc.p1157_max_alpha;

/*
단어 공부
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.
https://www.acmicpc.net/problem/1157
*/
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 선언

    int[] count = new int[26];
    int lastMaxI = -1;
    int lastMax = 0;
    int maxI = -1;
    int max = 0;

    char[] s = br.readLine().toCharArray();

    for (int i = 0; i < s.length; i++) {
      int c = s[i] >= 'a' ? s[i] - 'a' : s[i] - 'A';
      count[c]++;
      if (count[c] > max) {
        maxI = c;
        max = count[c];
      } else if (count[c] > lastMax) {
        lastMaxI = c;
        lastMax = count[c];
      }
    }

    System.out.println(max == lastMax ? "?" : (char) (maxI + 'A'));
    return;
  }
}
