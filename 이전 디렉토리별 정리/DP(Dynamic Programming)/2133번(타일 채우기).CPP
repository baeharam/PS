#include <cstdio>

int dp[31];

int main(void)
{
	int n; scanf("%d", &n);
	dp[2] = 3;
	if (n % 2 != 0) puts("0");
	else {
		for (int i = 4; i <= n; i += 2) {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = 4; j < i; j += 2) dp[i] += 2 * dp[i - j];
			dp[i] += 2;
		}
	}

	printf("%d", dp[n]);

	return 0;
}