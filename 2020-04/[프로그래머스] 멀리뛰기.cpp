#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1234567LL;
ll dp[2001];

ll solution(int n) {
	dp[1] = 1, dp[2] = 2;
	for(int i=3; i<=n; ++i){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= mod;
	}
	return dp[n];
}