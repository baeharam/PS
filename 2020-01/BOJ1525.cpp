#include <bits/stdc++.h>
using namespace std;

struct info{
	int state[3][3];
	int move;
};
int ans[3][3] = {1,2,3,4,5,6,7,8};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<info> q;
map<string, bool> visited;

string getState(int state[][3]){
	string s = "";
	for(int i =0; i<3; i++){
		for(int j=0; j<3; j++){
			s += to_string(state[i][j]);
		}
	}
	return s;
}

int bfs(info begin)
{
	visited[getState(begin.state)] = true;
	q.push(begin);
	info cur,newInfo;
	int x,y;
	bool isAnswer;
	while(!q.empty()){
		cur = q.front(); q.pop();
		isAnswer = true;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(cur.state[i][j] == 0){
					x = i;
					y = j;
				}
				if(cur.state[i][j] != ans[i][j])
					isAnswer = false;
			}
		}
		if(isAnswer) return cur.move;
		for(int i=0; i<4; i++){
			int _dx = x + dx[i];
			int _dy = y + dy[i];
			if(_dx < 0 || _dx >= 3 || _dy < 0 || _dy >= 3) continue;
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					newInfo.state[i][j] = cur.state[i][j];
				}
			}
			swap(newInfo.state[x][y], newInfo.state[_dx][_dy]);
			string ss = getState(newInfo.state);
			if(visited[ss]) continue;
			visited[ss] = true;
			newInfo.move = cur.move + 1;
			q.push(newInfo);
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	info begin;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> begin.state[i][j];
		}
	}
	begin.move = 0;
	cout << bfs(begin) << '\n';
	return 0;
}