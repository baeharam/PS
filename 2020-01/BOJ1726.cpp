#include <bits/stdc++.h>
using namespace std;

struct pos{int x,y,dir,order;};
const int maxn = 105;
const int inf = 2e9;
int N,M;
int b[maxn][maxn];
int vi[maxn][maxn][5];
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
queue<pos> q;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> b[i][j];
		}
	}

	pos begin,end;
	cin >> begin.x >> begin.y >> begin.dir;
	cin >> end.x >> end.y >> end.dir;

	q.push(begin);
	vi[begin.x][begin.y][begin.dir] = 1;
	int ans = inf;
	while(!q.empty()){
		pos cur = q.front(); q.pop();
		int x = cur.x , y = cur.y;
		int dir = cur.dir, order = cur.order;
		if(x == end.x && y == end.y && dir == end.dir){
			ans = min(ans, order);
			continue;
		}
		for(int i=1; i<=3; i++){
			int _dx = x + dx[dir]*i;
			int _dy = y + dy[dir]*i;
			if(_dx < 1 || _dx > N || _dy < 1 || _dy > M) break;
			if(b[_dx][_dy] == 1) break;
			if(vi[_dx][_dy][dir]) continue;
			vi[_dx][_dy][dir] = 1;
			q.push((pos){_dx,_dy,dir,order+1});	
		}
		int dir1,dir2;
		switch(dir){
			case 1: dir1=4; dir2=3; break;
			case 2: dir1=3; dir2=4; break;
			case 3: dir1=1; dir2=2; break;
			case 4: dir1=2; dir2=1;
		}
		if(!vi[x][y][dir1]){
			vi[x][y][dir1] = 1;
			q.push((pos){x,y,dir1,order+1});
		}
		if(!vi[x][y][dir2]){
			vi[x][y][dir2] = 1;
			q.push((pos){x,y,dir2,order+1});
		}
	}
	cout << ans << '\n';
	return 0;
}