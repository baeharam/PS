#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[105][100005];

int solution(int n, vector<int> money) {
	int len = (int)money.size();

	for(int i=0; i<=n; ++i)
		if(!(i % money[0])) dp[0][i] = 1;
	for(int i=1; i<len; ++i){
		int cur = money[i];
		for(int j=0; j<=n; ++j){
			dp[i][j] = dp[i-1][j];
			if(cur <= j) {
				dp[i][j] += dp[i][j-cur];
				dp[i][j] %= mod;
			}
		}
	}

	return dp[len-1][n] % mod;
}

int main(void) {
	solution(100000, {1,2,3});
	return 0;
}