#include <iostream>

int dp[1000000+1];


int main(void)
{
	int n; std::cin >> n;

	while(n>1){
		// 1) 기존에 있는 값과 업데이트 될 값 중에 더 작은값을 적용한다.
		// 2) 값이 0인 경우 아무것도 적용되지 않았기 때문에 무조건 업데이트 시킨다.
		if (dp[n - 1] > dp[n]+1 || dp[n-1]==0) dp[n - 1] = dp[n] + 1;
		if (n % 2 == 0 && (dp[n / 2]>dp[n] + 1 || dp[n/2]==0)) dp[n / 2] = dp[n] + 1;
		if (n % 3 == 0 && (dp[n / 3]>dp[n] + 1 || dp[n/3]==0)) dp[n / 3] = dp[n] + 1;
		n--;
	}

	std::cout << dp[1];

	return 0;

}