package net.acmicpc.p1475_room_no;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] count = new int[10];
        int count69 = 1;
        
        String str = br.readLine().trim();
        for (int i = 0; i < str.length(); i++) {
            int s = (int)str.charAt(i) - '0';
            if (s == 6 || s == 9)
                count69++;
            else
                count[s]++;
        }
        Arrays.sort(count);
        
        int turn = count69/2 > count[9]? count69/2: count[9];
        System.out.print(turn);
        return; 
    }
}
