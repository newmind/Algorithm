package net.acmicpc.p2170_line_length;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); //선언

        int n = Integer.parseInt(bf.readLine()); //Int
        int[][] lines = new int[n][2];
        for (int i = 0; i < lines.length; i++) {
          String s = bf.readLine();
          StringTokenizer st = new StringTokenizer(s); //StringTokenizer인자값에 입력 문자열 넣음
          int a = Integer.parseInt(st.nextToken()); //첫번째 호출
          int b = Integer.parseInt(st.nextToken()); //두번째 호출
          lines[i][0] = a;
          lines[i][1] = b;
        }
        
//        int[][] lines = {{1, 3}, {2, 5}, {3, 5}, {6, 7}};
       
        System.out.println(line_sweeping(lines));
        return; 
    }
    public static int line_sweeping(int [][] lines) {
        Arrays.sort(lines, (a, b)-> a[0]-b[0]);
        int length = 0;
        int x = lines[0][0];
        int y = lines[0][1];
        for (int i = 1; i < lines.length; i++) {
            int x2 = lines[i][0];
            int y2 = lines[i][1];
            if (x2 > y) {
                length += y-x;
                x = x2;
                y = y2;
            } else if (y2 > y){
                y = y2;
            }
        }
        
        length += y-x;
        return length;
    }
}
