#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using PP = pair<P,P>;
const int maxn = 1005;
int N,M,K;
int board[maxn][maxn];
int visited[maxn][maxn][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
string s;
queue<PP> q;

int main(void)
{
	cin >> N >> M >> K;
	for(int i=0; i<N; i++){
		cin >> s;
		for(int j=0; j<(int)s.size(); j++)
			board[i][j] = s[j] - '0';
	}

	int ans = 2e9;
	q.push(PP(P(0,0),P(0,0)));
	while(!q.empty()){
		PP cur = q.front(); q.pop();
		int x = cur.first.first;
		int y = cur.first.second;
		int b = cur.second.first;
		int m = cur.second.second;

		if(x == N-1 && y == M-1)
			ans = min(ans, m);

		for(int i=0; i<4; i++){
			int _dx = x + dx[i];
			int _dy = y + dy[i];
			if(_dx < 0 || _dx >= N || _dy < 0 || _dy >= M) continue;
			if(board[_dx][_dy]){
				if(visited[_dx][_dy][b+1] || b+1 > K) continue;
				visited[_dx][_dy][b+1] = 1;
				q.push(PP(P(_dx,_dy), P(b+1,m+1)));
			} else{
				if(visited[_dx][_dy][b]) continue;
				visited[_dx][_dy][b] = 1;
				q.push(PP(P(_dx,_dy), P(b,m+1)));
			}
		}
	}

	cout << (ans == 2e9 ? -1 : ans + 1) << '\n';

	return 0;
}