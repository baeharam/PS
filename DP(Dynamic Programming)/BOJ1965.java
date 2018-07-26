package ps;

import java.util.Scanner;

public class BOJ1965 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int a[] = new int[n+1];
		int dp[] = new int[n+1];
		
		for(int i=1; i<=n; i++) {
			a[i] = sc.nextInt();
			dp[i] = 1;
		}
		
		int max = dp[1];
		for(int i=2; i<=n; i++) {
			for(int j=i-1; j>=1; j--) {
				if(a[i]>a[j])
					dp[i] = Math.max(dp[i], dp[j] + 1);
			}
			if(max<dp[i]) max = dp[i];
		}
		
		System.out.println(max);
		
		sc.close();
	}
}
