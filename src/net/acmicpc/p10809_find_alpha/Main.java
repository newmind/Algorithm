package net.acmicpc.p10809_find_alpha;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); //선언
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] pos = new int[26];
        for (int i = 0; i < 26; i++) {
            pos[i] = -1;
        }
        // Arrays.fill(pos, -1);

        char[] line = bf.readLine().toCharArray();
        // String line = "baekjoon";
        for (int i = 0; i < line.length; i++) {
            int n = line[i] - 'a';
            if (pos[n] == -1)
                pos[n] = i;
        }

        for (int var : pos) {
            bw.write(var + " ");
        }
        bw.flush();
        return; 
    }
}
