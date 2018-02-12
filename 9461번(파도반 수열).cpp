#include <iostream>

long long dp[100 + 1];

int main(void)
{
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	dp[6] = 3;

	for (long long i = 7; i <= 100; i++) dp[i] = dp[i - 1] + dp[i - 5];

	long long tc,n; std::cin >> tc;
	while (tc--) {
		std::cin >> n;
		std::cout << dp[n] << '\n';
	}

	return 0;
}