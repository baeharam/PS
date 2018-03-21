#include <iostream>

int dp[10000 + 1][3];

int maxGrape(int index)
{
	int max = 0;
	for (int i = index; i >= 1; i--) {
		if (dp[i][1] > dp[i][2] && dp[i][1] > max) max = dp[i][1];
		else if (dp[i][1] <= dp[i][2] && dp[i][2] > max) max = dp[i][2];
	}
	return max;
}

int main(void)
{
	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> dp[i][1]; dp[i][0]=dp[i][1]; }

	int max = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][2] = dp[i][0] + dp[i - 1][1];
		dp[i][1] = dp[i][0] + maxGrape(i - 2);
	}

	std::cout << maxGrape(n);

	return 0;
}