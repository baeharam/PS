#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int solution(int n, vector<vector<int>> results){
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = 1e9;
		}
	}
	
	for(vector<int> r : results)
		dp[r[0]][r[1]] = 1;

	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(dp[i][k] + dp[k][j] < dp[i][j]){
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n; ++i){
		bool conn = true;
		for(int j=1; j<=n; ++j){
			if(i == j) continue;
			if(dp[i][j] == 1e9 && dp[j][i] == 1e9){
				conn = false;
				break;
			}
		}
		if(conn) ++ans;
	}
	return ans;
}