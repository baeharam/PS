#include <bits/stdc++.h>
using namespace std;

struct pos{
	int sx,sy;
	int ex,ey;
	int move;
};
const int maxn = 55;
int N;
char b[maxn][maxn];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int vi[maxn][maxn][maxn][maxn];
queue<pos> q;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	pos spos = {-1,-1,-1,-1,0};
	for(int i=1; i<=N; i++){
		string s;
		cin >> s;
		for(int j=1; j<=N; j++){
			b[i][j] = s[j-1];
			if(s[j-1] == 'B'){
				if(spos.sx == -1 && spos.sy == -1){
					spos.sx = i;
					spos.sy = j;
				} else{
					spos.ex = i;
					spos.ey = j;
				}
			}
		}
	}

	q.push(spos);
	vi[spos.sx][spos.sy][spos.ex][spos.ey] = 1;

	int ans = 2e9;
	while(!q.empty()){
		pos cur = q.front(); q.pop();
		int sx = cur.sx, sy = cur.sy;
		int ex = cur.ex, ey = cur.ey;
		int move = cur.move;

		bool goal = true;
		for(int i=sx; i<=ex; i++){
			for(int j=sy; j<=ey; j++){
				if(b[i][j] != 'E'){
					goal = false;
					break;
				}
			}
			if(!goal) break;
		}
		if(goal){
			ans = min(ans, move);
			continue;
		}

		int dsx,dsy,dex,dey;
		bool test;
		for(int i=0; i<4; i++){
			dsx = sx + dx[i];
			dsy = sy + dy[i];
			dex = ex + dx[i];
			dey = ey + dy[i];

			test = true;
			for(int x=dsx; x<=dex; x++){
				for(int y=dsy; y<=dey; y++){
					if(x < 1 || x > N || y < 1 || y > N){
						test = false;
						break;
					}
					if(b[x][y] == '1'){
						test = false;
						break;
					}
				}
				if(!test) break;
			}
			if(!test || vi[dsx][dsy][dex][dey]) continue;
			q.push((pos){dsx,dsy,dex,dey,move+1});
			vi[dsx][dsy][dex][dey] = 1;
		}



		if(sx == ex){
			test = true;
			for(int x=sx-1; x<=ex+1; x++){
				for(int y=sy; y<=ey; y++){
					if(b[x][y] == '1'){
						test = false;
						break;
					}
				}
				if(!test) break;
			}
			if(!test) continue;
			dsx = sx - 1, dsy = sy + 1;
			dex = ex + 1, dey = ey - 1;
			for(int x=dsx; x<=dex; x++){
				for(int y=dsy; y<=dey; y++){
					if(x < 1 || x > N || y < 1 || y > N){
						test = false;
						break;
					}
					if(b[x][y] == '1'){
						test = false;
						break;
					}
				}
				if(!test) break;
			}
			if(test && !vi[dsx][dsy][dex][dey]){
				q.push((pos){dsx,dsy,dex,dey,move+1});
				vi[dsx][dsy][dex][dey] = 1;
			}
		}
		else if(sy == ey){
			test = true;
			for(int x=sx; x<=ex; x++){
				for(int y=sy-1; y<=ey+1; y++){
					if(b[x][y] == '1'){
						test = false;
						break;
					}
				}
				if(!test) break;
			}
			if(!test) continue;
			dsx = sx + 1, dsy = sy - 1;
			dex = ex - 1, dey = ey + 1;
			for(int x=dsx; x<=dex; x++){
				for(int y=dsy; y<=dey; y++){
					if(x < 1 || x > N || y < 1 || y > N){
						test = false;
						break;
					}
					if(b[x][y] == '1'){
						test = false;
						break;
					}
				}
				if(!test) break;
			}
			if(test && !vi[dsx][dsy][dex][dey]){
				q.push((pos){dsx,dsy,dex,dey,move+1});
				vi[dsx][dsy][dex][dey] = 1;
			}
		}
	}
	cout << (ans == 2e9 ? 0 : ans) << '\n';
	return 0;
}