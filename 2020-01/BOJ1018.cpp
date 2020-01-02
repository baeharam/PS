#include <bits/stdc++.h>
using namespace std;

struct info{
	int x,y,count;
	char before;
};
const int maxn = 55;
char b[maxn][maxn];
int vi[maxn][maxn];
int dx[2] = {1,0};
int dy[2] = {0,1};
int N,M;
queue<info> q;

int bfs(int x, int y, bool flag)
{
	vi[x][y] = 1;
	int count = !((flag && b[x][y] == 'B') || (!flag && b[x][y] == 'W'));
	char before;
	if(!flag && b[x][y] == 'B') before = 'W';
	else if(flag && b[x][y] == 'W') before = 'B';
	else before = b[x][y];
	q.push((info){x,y,count,before});

	count = 0;
	while(!q.empty()){
		info cur = q.front(); q.pop();
		int cx = cur.x;
		int cy = cur.y;
		count += cur.count;
		char before = cur.before;
		if(x == N && y == M) break;
		for(int i=0; i<2; i++){
			int _dx = cx + dx[i];
			int _dy = cy + dy[i];
			if(_dx > x + 7 || _dy > y + 7) continue;
			if(vi[_dx][_dy]) continue;
			vi[_dx][_dy] = 1;
			int newCount = !(before != b[_dx][_dy]);
			char newBefore =  b[_dx][_dy];
			if(before == b[_dx][_dy]) newBefore = (before == 'B' ? 'W' : 'B');
			q.push((info){_dx,_dy,newCount,newBefore});
		}
	}
	return count;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for(int i=1; i<=N; i++){
		string s;
		cin >> s;
		for(int j=1; j<=M; j++)
			b[i][j] = s[j-1];
	}

	int ans = 2e9;
	for(int i=1; i<=N-8+1; i++){
		for(int j=1; j<=M-8+1; j++){
			memset(vi, 0, sizeof(vi));
			ans = min(ans, bfs(i,j,true));
			memset(vi, 0, sizeof(vi));
			ans = min(ans, bfs(i,j,false));
		}
	}
	cout << ans << '\n';
	return 0;
}