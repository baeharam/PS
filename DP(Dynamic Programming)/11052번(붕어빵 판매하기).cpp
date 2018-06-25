#include <iostream>
#include <algorithm>
using namespace std;

int pi[10005];
int dp[1005];

int main(void)
{
	int n, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		pi[i] = b;
	}

	for (int i = 1; i <= n; i++) { 
		for (int k = 1; k <= i; k++) {
			dp[i] = max(dp[i], dp[i - k] + pi[k]);
		}
	}

	cout << dp[n];

	return 0;
}