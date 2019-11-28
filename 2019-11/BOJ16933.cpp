#include <bits/stdc++.h>
using namespace std;

struct P{
	int x,y;
	int b,m;
	bool flag;
};
const int maxn = 1005;
int N,M,K;
int board[maxn][maxn];
int visited[maxn][maxn][11][2];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
string s;
queue<P> q;

int main(void)
{
	cin >> N >> M >> K;
	for(int i=0; i<N; i++){
		cin >> s;
		for(int j=0; j<(int)s.size(); j++)
			board[i][j] = s[j] - '0';
	}

	int ans = 2e9;
	visited[0][0][0][0] = 1;
	q.push((P){0,0,0,0,false});
	while(!q.empty()){
		P cur = q.front(); q.pop();
		int x = cur.x;
		int y = cur.y;
		int b = cur.b;
		int m = cur.m;
		bool flag = cur.flag;

		if(x == N-1 && y == M-1)
			ans = min(ans, m);

		for(int i=0; i<5; i++){
			int _dx = x + dx[i];
			int _dy = y + dy[i];
			if(_dx < 0 || _dx >= N || _dy < 0 || _dy >= M) continue;
			if(i == 0){
				if(visited[_dx][_dy][b][!flag]) continue;
				visited[_dx][_dy][b][!flag] = 1;
				q.push((P){_dx,_dy,b,m+1,!flag});
				continue;
			}
			if(board[_dx][_dy]){
				if(b+1 > K || flag) continue;
				if(visited[_dx][_dy][b+1][!flag]) continue;
				visited[_dx][_dy][b+1][!flag] = 1;
				q.push((P){_dx,_dy,b+1,m+1,!flag});
			} else{
				if(visited[_dx][_dy][b][!flag]) continue;
				visited[_dx][_dy][b][!flag] = 1;
				q.push((P){_dx,_dy,b,m+1,!flag});
			}
		}
	}

	cout << (ans == 2e9 ? -1 : ans + 1) << '\n';

	return 0;
}