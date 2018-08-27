#include <cstdio>

int a[1001][1001], dp[1001][1001], n, m, ans;
char s[1001];

int main(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &s[1]);
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j] - '0';
			dp[i][j] = a[i][j];
			if (ans < dp[i][j]) ans = dp[i][j];
		}
	}

	int min = n > m ? m : n;

	for (int k = 2; k <= min; k++) {
		for (int i = k; i <= n; i++) {
			for (int j = k; j <= m; j++) {
				if (i - 1 >= 1 && j - 1 >= 1 && 
					dp[i-1][j-1]>=(k-1)*(k-1) && dp[i-1][j]>= (k - 1)*(k - 1) && dp[i][j-1]>= (k - 1)*(k - 1) && a[i][j]>=1) {
					dp[i][j] = k * k;
					//printf("%d행 %d열 기준 %d x %d 정사각형의 넓이 : %d\n", i, j, k, k, dp[i][j]);
					if (dp[i][j] > ans) ans = dp[i][j];
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}