package net.acmicpc.p2292_bee;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.*;
import java.util.*;

public class Main {
    static int lower_bound(List<Integer> l, int x) {
        int s = 0;
        int e = l.size();
        while (s < e) {
            int m = (s+e) / 2;
            if (l.get(m) < x) s = m+1;
            else e = m;
        }
        return e;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //선언

        int N = Integer.parseInt(br.readLine());

        ArrayList<Integer> bees = new ArrayList<>();
        bees.add(1);
        for (int i = 1; true; i++) {
            bees.add(bees.get(i-1) + 6*i);
            if (bees.get(i) > N)
                break;
        }

        int pos = lower_bound(bees, N);
        System.out.println(pos+1);
       
        return; 
    }
}
