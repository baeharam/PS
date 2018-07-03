#include <cstdio>
#include <algorithm>

int tc, n, s[3][100005], dp[100005][4], r;

int main(void)
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int k = 1; k <= 2; k++) {
			for (int i = 1; i <= n; i++) {
				scanf("%d", &s[k][i]);
			}
		}

		dp[1][1] = s[1][1]; dp[1][2] = s[2][1]; dp[1][3] = 0;

		for (int i = 2; i <= n; i++) {
			dp[i][1] = std::max(dp[i - 1][3], dp[i - 1][2]) + s[1][i];
			dp[i][2] = std::max(dp[i - 1][3], dp[i - 1][1]) + s[2][i];
			dp[i][3] = std::max(dp[i - 1][1], dp[i - 1][2]);
		}

		printf("%d\n", std::max(dp[n][1], std::max(dp[n][2], dp[n][3])));
	}
	return 0;
}