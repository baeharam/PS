#include <cstdio>
#include <algorithm>

int dp[1001][4];

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			scanf("%d", &dp[i][j]);
	}

	for (int i = 2; i <= n; i++) {
		dp[i][1] = std::min(dp[i - 1][2], dp[i - 1][3]) + dp[i][1];
		dp[i][2] = std::min(dp[i - 1][1], dp[i - 1][3]) + dp[i][2];
		dp[i][3] = std::min(dp[i - 1][1], dp[i - 1][2]) + dp[i][3];
	}

	printf("%d", std::min(std::min(dp[n][1], dp[n][2]), dp[n][3]));
	return 0;
}