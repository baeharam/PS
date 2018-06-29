#include <cstdio>
#include <algorithm>

int dp[10001];
int coin[101];

int main(void)
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &coin[i]);
	// 주어진 동전의 가치를 만족시키지 못하는 경우에 중요함
	for (int i = 1; i <= k; i++) dp[i] = 100001;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++)
			dp[j] = std::min(dp[j], dp[j - coin[i]] + 1);
	}

	dp[k]!=100001 ? printf("%d", dp[k]) : puts("-1");
	return 0;
}