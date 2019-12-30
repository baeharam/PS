#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const int maxn = 1000001;
const int mod = 1e9;
int N;
ull ans;
ull dp[maxn];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	dp[1] = 0UL;
	dp[2] = 1UL;

	for(int i=3; i<=N; i++)
		dp[i] = (i-1)*((dp[i-1]+dp[i-2]) % mod) % mod;
	cout << dp[N] % mod << '\n';

	return 0;
}