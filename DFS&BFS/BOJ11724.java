package com.company;
import java.util.ArrayList;
import java.util.Scanner;

public class BOJ11724 {

    private static ArrayList<ArrayList<Integer>> g;
    private static boolean visit[];


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        g = new ArrayList<ArrayList<Integer>>(n+1);
        visit = new boolean[n+1];

        for(int i=0; i<=n; i++)
            g.add(new ArrayList<>());

        for(int i=0; i<m; i++) {
            int v1 = sc.nextInt();
            int v2 = sc.nextInt();
            g.get(v1).add(v2);
            g.get(v2).add(v1);
        }
        sc.close();

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(!visit[i]) {
                dfs(i);
                ans++;
            }
        }
        System.out.println(ans);
    }

    private static void dfs(int s) {
        visit[s] = true;
        for(int i : g.get(s)){
            if(!visit[i])
                dfs(i);
        }
    }

}
