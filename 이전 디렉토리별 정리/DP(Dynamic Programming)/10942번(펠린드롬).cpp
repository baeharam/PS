#include <cstdio>
#include <cstring>
using namespace std;

int dp[2001][2001], s, e, m, n, a[2001];

int pelin(int s, int e)
{
	if (a[s] != a[e]) return dp[s][e] = 0;
	if (s == e || s > e) return 1;
	if (dp[s][e] != -1) return dp[s][e];

	return dp[s][e] = pelin(s + 1, e - 1);
}



int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	memset(dp, -1, sizeof(dp));
	while (m--) {
		scanf("%d %d", &s, &e);
		printf("%d\n", pelin(s, e));
	}
	return 0;
}