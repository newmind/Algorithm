package net.acmicpc.p1193_zigzag;

import java.io.BufferedReader;
import java.io.*;

/*
분수찾기
https://www.acmicpc.net/problem/1193
*/
public class Main {
    public static void fast_solution(int X) {
        int h = 0;
        int w = 0;
        for (int i = 1; X > 0; i++) {
            h++;
            if (X > i)
                X -= i;
            else {
                w = X;
                break;
            }
        }

        if ((h % 2) == 0) {
            int a = w;
            int b = h - (w - 1);
            System.out.println((a) + "/" + (b));
        } else {
            int a = h - (w - 1);
            int b = w;
            System.out.println((a) + "/" + (b));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int X = Integer.parseInt(br.readLine());
        fast_solution(X);
        return;
    }
}
