#include <iostream>

// dp[i][0] = 기존 값
// dp[i][1] = 누적 합
// dp[i][2] = 연속 합의 최댓값
int dp[100000 + 1][3];

int main(void)
{
	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) std::cin >> dp[i][0];
	dp[1][1] = dp[1][2] = dp[1][0];

	// 누적합을 계산할 때는 기존 값과 누적합중에 더 큰값으로 초기화시킨다.
	for (int i = 2; i <= n; i++) {
		int temp = dp[i][0] + dp[i - 1][1];
		if (dp[i][0] > temp) dp[i][1] = dp[i][0];
		else dp[i][1] = temp;
	}

	// 누적합과 이전의 연속합의 최댓값을 비교해서 더 큰 값을 연속합의 최댓값으로 설정한다.
	for (int i = 2; i <= n; i++) {
		if (dp[i][1] > dp[i - 1][2]) dp[i][2] = dp[i][1];
		else dp[i][2] = dp[i - 1][2];
	}

	std::cout << dp[n][2];

	return 0;
}