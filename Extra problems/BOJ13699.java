package com.haram;

import java.util.Scanner;

public class BOJ13699 {
    static long t[];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        t = new long[n+1];
        t[0] = 1L;

        long ans = 0L;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=i-1; j++) {
                t[i] += (t[j] * t[i-1-j]);
            }
        }

        System.out.println(t[n]);

        sc.close();
    }
}
