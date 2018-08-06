#include <cstdio>
int dp[100001][4], n;
const int mod = 9901;

int main(void)
{
	scanf("%d", &n);

	dp[1][1] = dp[1][2] = dp[1][3] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
	}
	printf("%d", (dp[n][1] + dp[n][2] + dp[n][3]) % mod);
	return 0;
}