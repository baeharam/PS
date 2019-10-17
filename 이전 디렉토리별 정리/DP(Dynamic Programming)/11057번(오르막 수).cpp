#include <cstdio>

int n, sum, dp[1001][10]; // dp[i] = 10-i로 시작하는 숫자
const int mod = 10007;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				sum += dp[i - 1][k]%mod;
			}
			dp[i][j] = sum; sum = 0;
		}
	}
	
	sum = 0;
	for (int i = 0; i <= 9; i++) sum += dp[n][i];
	printf("%d", sum%mod);

	return 0;
}