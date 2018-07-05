#include <cstdio>
#include <algorithm>
using namespace std;

int a[1005][1005], dp[1005][1005];
int n, m, _m;

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			_m = 0;
			if (i - 1 > 0) _m = dp[i - 1][j];
			if (j - 1 > 0) _m = max(_m, dp[i][j - 1]);
			if (i - 1 > 0 && j - 1 > 0) _m = max(_m, dp[i - 1][j - 1]);
			dp[i][j] = a[i][j] + _m;
		}
	}

	printf("%d", dp[n][m]);

	return 0;
}