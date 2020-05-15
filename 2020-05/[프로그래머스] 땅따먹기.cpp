#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100000][5];

int f(int r, int c, vector<vector<int>>& land){
	if(r == n) return 0;
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=1; i<=4; ++i){
		if(i == c) continue;
		ret = max(ret, f(r+1, i, land) + land[r][i-1]);
	}
	return ret;
}

int solution(vector<vector<int>> land){
	n = (int)land.size();
	memset(dp, -1, sizeof(dp));
	return f(0,0,land);
}