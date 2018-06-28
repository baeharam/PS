#include <cstdio>

int dp[1001];
int num[1001];

int main(void)
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);

	int max = 0, realmax = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (num[j]<num[i] && dp[j]>max) max = dp[j];
		}
		dp[i] = max + 1; max = 0;
		if (dp[i] > realmax) realmax = dp[i];
	}
	printf("%d", realmax);
	
	return 0;
}