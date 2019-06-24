package net.acmicpc.p11004_sort_nth;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] nArr = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++)
            nArr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(nArr);

        System.out.print(nArr[k-1]);
    }
}