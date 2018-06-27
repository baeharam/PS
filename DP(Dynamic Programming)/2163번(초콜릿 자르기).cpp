#include <cstdio>

int dp[301][301];

int main(void)
{
	int n, m; scanf("%d%d", &n, &m);
	dp[1][0] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i>=2 && j == 1) dp[i][j] = dp[i - 1][j] + 1;
			else dp[i][j] = dp[i][j - 1] + dp[i][1] + 1;
			printf("%d x %d = %d°¡Áö\n",i,j,dp[i][j]);
		}
	}
	printf("%d", dp[n][m]);
	return 0;
}