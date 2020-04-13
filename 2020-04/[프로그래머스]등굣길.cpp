#include <bits/stdc++.h>
using namespace std;

struct info { int x,y,num; };
queue<info> q;
const int mod = 1e9 + 7;
int cc[100][100];
int dp[100][100],nn[100][100];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void bfs(int n, int m) {
	q.push((info){0,0,0});
	nn[0][0] = 0;
	dp[0][0] = 1;
	while(!q.empty()){
		info c = q.front(); q.pop();
		int cx = c.x, cy = c.y, cnum = c.num;
		for(int i=0; i<4; i++){
			int _dx = cx + dx[i], _dy = cy + dy[i];
			if(_dx < 0 || _dx >= n || _dy < 0 || _dy >= m) continue;
			if(cc[_dx][_dy]) continue;
			if(nn[_dx][_dy] == cnum + 1){
				dp[_dx][_dy] += dp[cx][cy];
				dp[_dx][_dy] %= mod;
				continue;
			}
			if(nn[_dx][_dy] != -1) continue;
			nn[_dx][_dy] = cnum + 1;
			dp[_dx][_dy] = dp[cx][cy];
			dp[_dx][_dy] %= mod;
			q.push((info){_dx,_dy,cnum + 1});
		}
	}
}

int solution(int m, int n, vector<vector<int>> puddles) {
	for(int i=0; i<(int)puddles.size(); i++)
		cc[puddles[i][1]-1][puddles[i][0]-1] = 1;
	memset(nn, -1, sizeof(nn));
	bfs(n,m);
	return dp[n-1][m-1] % mod;
}