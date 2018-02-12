#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

int dp[501][501];
int cost[501];
int sum[501];

int dpf(int f1, int f2)
{
	if (dp[f1][f2] != 0x33333333) return dp[f1][f2];
	else if (f1 == f2) return dp[f1][f2] = 0;
	else if (f1 + 1 == f2) return dp[f1][f2] = cost[f1] + cost[f2];
	else {
		for (int mid = f1; mid < f2; mid++) {
			int left = dpf(f1,mid);
			int right = dpf(mid+1, f2);
			dp[f1][f2] = std::min(dp[f1][f2], left + right);
		}
		
		return dp[f1][f2] += sum[f2] - sum[f1 - 1];
	}
}

int main(void)
{	
	int tc; std::cin >> tc;
	int last_chapter;

	while (tc--) {
		std::cin >> last_chapter;
		std::memset(dp, 0x33, sizeof(dp));
		for (int i = 1; i <= last_chapter; i++) {
			std::cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		std::cout << dpf(1, last_chapter);
	}

	return 0;
}