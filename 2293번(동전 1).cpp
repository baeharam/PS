#include <iostream>

int dp[10000 + 1];
int cost[100 + 1];

int main(void)
{
	int n, k; std::cin >> n >> k;

	for (int i = 1; i <= n; i++) std::cin >> cost[i];

	dp[0] = 1; // 자기자신 만큼의 가치를 만들어내는 경우 인덱스가 0이 되어서 1로 미리 초기화.

	for (int i = 1; i <= n; i++) {
		for (int j = cost[i]; j <= k; j++)	
			dp[j] += dp[j - cost[i]];
	}

	std::cout << dp[k];
	return 0;
}