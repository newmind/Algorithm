package net.acmicpc.p1654_lan_cable;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.*;
import java.util.*;

public class Main {
    static int lower_bound(int[] l, long x) {
        int s = 0;
        int e = l.length;
        while (s < e) {
            int m = (s+e) / 2;
            if (l[m] < x) s = m+1;
            else e = m;
        }
        return e;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int[] nums = new int[K];
        for (int i = 0; i < K; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(nums);

        long max_len = 0;
        long s = 0; 
        long e = (long)nums[K-1] + 1; 
        while (s < e) {
            long mid_len = (s+e) / 2;

            int count = 0;
            int lower = lower_bound(nums, mid_len);
            for (int i = lower; i < nums.length; i++) {
                count += nums[i] / mid_len;
                if (count >= N) {
                    if (mid_len > max_len)
                        max_len = mid_len;
                    break;
                }
            }
           
            if (count >= N) s = mid_len+1;
            else  e = mid_len;
        }
        
        System.out.println(max_len);
    }
}
