#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;
int N;
int dp[maxn + 1];

int main(void)
{
	cin >> N;
	dp[4] = 1;
	dp[5] = 2;
	for(int i=6; i<=N; i++)
		dp[i] = dp[i/2 + i%2] + 2;
	cout << dp[N] << '\n';
	return 0;
}