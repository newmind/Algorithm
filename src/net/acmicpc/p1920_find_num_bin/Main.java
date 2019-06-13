package net.acmicpc.p1920_find_num_bin;

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
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] nums = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(nums);

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int x = Integer.parseInt(st.nextToken());
            if (Arrays.binarySearch(nums, x) < 0)
                bw.write('0');
            else
                bw.write('1');
            bw.newLine();
        }
        bw.flush();
    }
}
