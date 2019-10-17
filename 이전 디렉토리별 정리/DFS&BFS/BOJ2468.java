package com.haram;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BOJ2468 {

    static boolean visit[][];
    static int space[][];
    static int max;
    static int dx[], dy[];
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        visit = new boolean[n][n];
        space = new int[n][n];
        dx = new int[] {-1, 1, 0, 0};
        dy = new int[] {0, 0, -1, 1};
        max = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int temp = sc.nextInt();
                if(temp>max) max = temp;
                space[i][j] = temp;
            }
        }

        int safe = 0, ans = 0;
        for(int k=0; k<=max; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(!visit[i][j] && space[i][j]>k) {
                        dfs(i, j, k);
                        safe++;
                    }
                }
            }
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    visit[i][j] = false;
                }
            }
            if(safe>ans) ans = safe;
            safe = 0;
        }


        System.out.println(ans);
        sc.close();
    }

    private static void dfs(int x, int y, int height) {
        visit[x][y] = true;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0 || y+dy[i]>=n) continue;
                if(!visit[x+dx[i]][y+dy[i]] && space[x+dx[i]][y+dy[i]]>height)
                    dfs(x+dx[i], y+dy[i], height);
            }
        }
    }


}
