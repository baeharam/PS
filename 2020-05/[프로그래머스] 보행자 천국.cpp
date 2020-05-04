#include <bits/stdc++.h>
using namespace std;

int h[501][501];
int v[501][501];

int solution(int m, int n, vector<vector<int>> city_map) {
	const int mod = 20170805;
	memset(h,0,sizeof(h));
	memset(v,0,sizeof(v));
	h[1][1] = v[1][1] = 1;
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=n; ++j){
			if(city_map[i-1][j-1] == 1) continue;
			if(city_map[i-1][j-1] == 2){
				h[i][j] = h[i][j-1];
				v[i][j] = v[i-1][j];
			} else{
				h[i][j] += (h[i][j-1] + v[i-1][j]) % mod;
				v[i][j] += (h[i][j-1] + v[i-1][j]) % mod;
			}
		}
	}
	return h[m][n] % mod;
}