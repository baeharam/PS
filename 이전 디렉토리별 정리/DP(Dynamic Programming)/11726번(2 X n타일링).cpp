#include <iostream>
using namespace std;

int dp[1005];
const int mod = 10007;

int main(void)
{
	int n; cin >> n;
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] % mod + dp[i - 2] % mod;

	cout << dp[n] % mod;
	return 0;
}