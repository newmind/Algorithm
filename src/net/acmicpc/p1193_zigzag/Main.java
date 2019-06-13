package net.acmicpc.p1193_zigzag;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        final int limit = 10000000;

        int X = Integer.parseInt(br.readLine());
        X--;
        // int X = 14;
        if (X == 1) {
            System.out.println("1/1");
            return;
        }

        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(0);
        arr.add(1);
        for (int i = 2; arr.get(arr.size()-1) < X; i++) {
            arr.add(i + arr.get(i-1));
        }

        int h = arr.size()-1;
        for (; h > 1; h--) {
            if (X / arr.get(h) == 1) 
                break;
        }
        h++;
        int w = X % h;
        if (w == 0) {
            w++;
        }
        // System.out.println(h + ", " + w);
        if ((h % 2) == 1) {
            h = h - w + 1;
        }
        System.out.println(h + "/" + w);

        return; 
    }
}
