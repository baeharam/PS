#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};
int vi[11][11][11][11];
int x,y,ans,didx,_dx,_dy,vx,vy,vdx,vdy;

int solution(string dirs) {
	for(int i=0; i<(int)dirs.size(); ++i){
		char dir = dirs[i];
		switch(dir){
			case 'U': didx = 0; break;
			case 'D': didx = 1; break;
			case 'L': didx = 2; break;
			case 'R': didx = 3; break;
			break;
		}
		_dx = x + dx[didx];
		_dy = y + dy[didx];
		if(_dx < -5 || _dy < -5 || _dx > 5 || _dy > 5) continue;
		vx = x < 0 ? x*-1+5 : x, vy = y < 0 ? y*-1+5 : y;
		vdx = _dx < 0 ? _dx*-1+5 : _dx, vdy = _dy < 0 ? _dy*-1+5 : _dy;
		if(!vi[vx][vy][vdx][vdy]){
			++ans;
			vi[vx][vy][vdx][vdy] = 1;
			vi[vdx][vdy][vx][vy] = 1;
		}
		x = _dx, y = _dy;
	}
	return ans;
}