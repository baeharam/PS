#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
const char bomb = 'Z';
char board[12][6];
int vi[12][6];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<P> q;

vector<P> bfs(P cur)
{
	vi[cur.first][cur.second] = 1;
	q.push(cur);
	vector<P> ret;
	ret.push_back(cur);
	while(!q.empty()){
		P now = q.front(); q.pop();
		int x = now.first;
		int y = now.second;
		for(int i=0; i<4; i++){
			int _dx = x + dx[i];
			int _dy = y + dy[i];
			if(_dx < 0 || _dx >= 12 || _dy < 0 || _dy >= 6) continue;
			if(vi[_dx][_dy] || board[x][y] != board[_dx][_dy]) continue;
			vi[_dx][_dy] = 1;
			q.push({_dx,_dy});
			ret.push_back({_dx,_dy});
		}
	}
	return ret;
}

bool isBombed() {
	for(int i=0; i<12; i++){
		for(int j=0; j<6; j++){
			if(board[i][j] == bomb)
				return true;
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i=0; i<12; i++)
		cin >> board[i];

	int ans = 0;
	while(true){
		set<int> bpos;
		memset(vi, 0, sizeof(vi));
		for(int i=0; i<12; i++){
			for(int j=0; j<6; j++){
				if(board[i][j] == '.' || board[i][j] == bomb) continue;
				vector<P> ret = bfs({i,j});
				if((int)ret.size() >= 4){
					for(P pos : ret){
						bpos.insert(pos.second);
						board[pos.first][pos.second] = bomb;
					}
				}
			}
		}
		if(!isBombed()) break;
		ans++;
		for(int y : bpos){
			vector<char> up;
			for(int i=11; i>=0; i--){
				if(board[i][y] == bomb){
					board[i][y] = '.';
				} else {
					up.push_back(board[i][y]);
					board[i][y] = '.';
				}
			}
			int row = 11;
			for(int down : up){
				board[row][y] = down;
				--row;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}