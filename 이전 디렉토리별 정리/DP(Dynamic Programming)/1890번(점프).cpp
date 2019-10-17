#include <cstdio>

long long a[100][100], dp[100][100];
int n;


int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%lld", &a[i][j]);
	}

	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j]!=0 && dp[i][j] != 0) {
				if(i+a[i][j]<n) dp[i + a[i][j]][j] += dp[i][j];
				if(j+a[i][j]<n) dp[i][j + a[i][j]] += dp[i][j];
			}
		}
	}

	if(dp[n-1][n-1]) printf("%lld", dp[n - 1][n - 1]);

	return 0;
}