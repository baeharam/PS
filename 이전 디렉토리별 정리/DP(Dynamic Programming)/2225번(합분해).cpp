#include <cstdio>

int dp[201][201], n, k;
const int mod = 1000000000;

int main(void)
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 1) dp[i][j] = 1;
			else for (int l = 0; l <= j; l++) dp[i][j] = dp[i][j] % mod + dp[i - 1][l] % mod;
		}
	}
	printf("%d", dp[k][n] % mod);
	return 0;
}