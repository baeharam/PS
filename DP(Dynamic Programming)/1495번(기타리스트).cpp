#include <cstdio>

int n, s, m, v[101], max;
// i번째 음악을 볼륨 j로 연주할 수 있는가?
bool dp[101][1001];

int main(void)
{
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

	dp[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + v[i] <= m) dp[i][j + v[i]] = true;
				if (j - v[i] >= 0) dp[i][j - v[i]] = true;
			}
		}
	}
	
	max = -1;
	for (int i = 0; i <= m; i++) {
		if (dp[n][i] && i > max)
			max = i;
	}

	printf("%d", max);
	return 0;
}