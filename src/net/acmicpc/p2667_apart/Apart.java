package net.acmicpc.p2667_apart;

/**
 * 0,1,2 구역의 갯수 구하기, 아파트 두더지굴 문제
 */

import java.util.*;

class Apart {
    public static int dfs(int[][] arr, int x, int y, int food, short c) {
        if (arr[y][x] != food)
            return 0;

        final int N = arr.length;
        int count = 1;
        arr[y][x] = c; // 지나간 곳은 c 으로

        if (y - 1 >= 0)
            count += dfs(arr, x, y - 1, food, c);
        if (x + 1 < N)
            count += dfs(arr, x + 1, y, food, c);
        if (y + 1 < N)
            count += dfs(arr, x, y + 1, food, c);
        if (x - 1 >= 0)
            count += dfs(arr, x - 1, y, food, c);

        return count;
    }

    public static int[] solution(int[][] v) {
        int[] answer = new int[3];
        
        int N = v.length;
        short c = 3;    // 지나간 구분값
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                int food = v[y][x];
                if (food <= 2) {
                    int count = dfs(v, x, y, food, c);
                    if (count > 0) {
                        answer[food]++;
                        c++;
                    }
                }
            }
        }
        // print(arr);
        
        return answer;
    }

    public static void main(String[] args) {
        int[][] v = {{0,0,1,1},{1,1,1,1},{2,2,2,1},{0,0,0,2}};
        printA(solution(v));
    }

    public static void printA(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }

    public static void print(int[][] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
    }
}