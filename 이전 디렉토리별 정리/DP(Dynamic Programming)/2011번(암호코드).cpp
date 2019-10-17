#include <cstdio>
#include <cstring>

int dp[5005][3];
char s[5005];
const int mod = 1000000;


int main(void)
{
	scanf("%s", s);
	int n = strlen(s);

	dp[0][1] = 1; dp[0][2] = 0;

	if (s[0] == 0) {
		puts("0");
		return 0;
	}


	for (int i = 1; i < n; i++) {
		if (s[i] - '0' == 0) {
			if (s[i - 1] - '0' == 0) break;
			else if ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 26) dp[i][2] = dp[i - 1][1];
		}
		else {
			dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
			if ((s[i - 1] - '0') * 10 + (s[i] - '0') <= 26) dp[i][2] = dp[i - 1][1];
		}
		dp[i][1] %= mod; dp[i][2] %= mod;
	}

	printf("%d", (dp[n - 1][1] + dp[n - 1][2])%mod);


	return 0;
}