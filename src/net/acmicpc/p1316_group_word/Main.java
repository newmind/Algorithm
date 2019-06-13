package net.acmicpc.p1316_group_word;

/*
그룹 단어 체커
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.
예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

https://www.acmicpc.net/problem/1316
*/

import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int answer = 0;
    int N = Integer.valueOf(br.readLine());

    while (N-- > 0) {
      char[] s = br.readLine().trim().toCharArray();

      boolean correct = true;
      int[] count = new int[26];
      count[s[0] - 'a']++;
      for (int i = 1; i < s.length; i++) {
        if (s[i] != s[i - 1] && count[s[i] - 'a'] != 0) {
          correct = false;
          break;
        }
        count[s[i] - 'a']++;
      }
      if (correct) {
        answer++;
      }
    }

    System.out.println(answer);
    return;
  }
}
