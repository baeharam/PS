#include <cstdio>
#include <queue>
using namespace std;

struct pos{int x,y,time; char who;};
const int SIZE = 55;
char board[SIZE][SIZE];
int visited[SIZE][SIZE];
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
int r,c;
queue<pos> q;


int main(void)
{
  scanf("%d%d",&r,&c);
  int sx = 0, sy = 0;
  for(int i=1; i<=r; i++){
    scanf("%s",&board[i][1]);
    for(int j=1; j<=c; j++){
      if(board[i][j] == '*'){
        visited[i][j] = 1;
        q.push((pos){i,j,0,'*'});
      }
      else if(board[i][j] == 'S'){
        sx = i;
        sy = j;
      }
    }
  }
  q.push((pos){sx,sy,0,'S'});
  visited[sx][sy] = 1;
  int ans = 2e9;
  while(!q.empty()){
    pos p = q.front(); q.pop();
    if(board[p.x][p.y] == 'D' && p.who == 'S') ans = min(ans, p.time);
    for(int i=0; i<4; i++){
      int _dx = p.x + dx[i], _dy = p.y + dy[i];
      if(_dx < 1 || _dx > r || _dy < 1 || _dy > c) continue;
      if(visited[_dx][_dy]) continue;
      if(p.who == '*' && (board[_dx][_dy] == 'X' || board[_dx][_dy] == 'D')) continue;
      else if(p.who == 'S' && board[_dx][_dy] == 'X') continue;
      q.push((pos){_dx,_dy,p.time+1,p.who});
      visited[_dx][_dy] = 1;
      if(p.who == '*') board[_dx][_dy] = '*';
    }
  }
  ans == 2e9 ? puts("KAKTUS") : printf("%d\n",ans);
  return 0;
}