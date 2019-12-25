#include <bits/stdc++.h>
using namespace std;

struct command{int num,iter; char type;};
struct info{int x,y; char dir;};
const int maxn = 105;
const int empty = 0;
int A,B,N,M,x,y;
int board[maxn][maxn];
char d;
command cc[maxn];
info pos[maxn];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> N >> M;
	for(int i=1; i<=B; i++){
		for(int j=1; j<=A; j++){
			board[i][j] = empty;
		}
	}
	for(int i=0; i<N; i++){
		cin >> x >> y >> d;
		y = B - y + 1;
		board[y][x] = i+1;
		pos[i+1] = (info){y,x,d};
	}
	for(int i=0; i<M; i++)
		cin >> cc[i].num >> cc[i].type >> cc[i].iter;

	for(int i=0; i<M; i++){
		int num = cc[i].num;
		char type = cc[i].type;
		int iter = cc[i].iter;

		int cx = pos[num].x;
		int cy = pos[num].y;
		char dir = pos[num].dir;

		int nx = cx, ny = cy;
		if(type == 'F'){
			for(int j=0; j<iter; j++){
				switch(dir){
					case 'N': --nx; break;
					case 'E': ++ny; break;
					case 'S': ++nx; break;
					case 'W': --ny;
				}
				if(nx < 1 || nx > B || ny < 1 || ny > A){
					cout << "Robot " << num << " crashes into the wall" << '\n';
					return 0;
				} else if(board[nx][ny] != empty){
					cout << "Robot " << num << " crashes into robot " << board[nx][ny] << '\n';
					return 0;
				}
			}
			pos[num].x = nx;
			pos[num].y = ny;
			board[cx][cy] = empty;
			board[nx][ny] = num;
		} else if(type == 'L' || type == 'R'){
			char newDir = 'T';
			for(int j=0; j<iter; j++){
				switch(dir){
					case 'N': newDir = (type == 'L' ? 'W' : 'E'); break;
					case 'E': newDir = (type == 'L' ? 'N' : 'S'); break;
					case 'S': newDir = (type == 'L' ? 'E' : 'W'); break;
					case 'W': newDir = (type == 'L' ? 'S' : 'N');
				}
				dir = newDir;
			}
			pos[num].dir = dir;
		}
	}
	cout << "OK\n";
	return 0;
}