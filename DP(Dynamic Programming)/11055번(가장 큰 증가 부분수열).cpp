#include <cstdio>
#include <algorithm>

int dp[1001], a[1001], n, ans;


int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = a[i];
		for (int j = 1; j < i; j++) {
			if(a[j]<a[i])
				dp[i] = std::max(dp[i], dp[j] + a[i]);
		}
		ans = std::max(ans, dp[i]);
	}

	printf("%d", ans);

	return 0;
}