#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct pos{int x,y,time;};
const int SIZE = 55;
char board[SIZE][SIZE];
int visited[SIZE][SIZE];
queue<pos> q;
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
int l,w;

int main(void)
{
  scanf("%d%d",&l,&w);
  for(int i=1; i<=l; i++) scanf("%s",&board[i][1]);
  int ans = 0;
  for(int i=1; i<=l; i++){
    for(int j=1; j<=w; j++){   
      if(board[i][j] == 'W') continue;
      memset(visited,0,sizeof(visited));
      q.push((pos){i,j,0});
      visited[i][j] = 1;
      int m = 0;
      while(!q.empty()){
        pos p = q.front(); q.pop();
        m = max(m, p.time);
        for(int k=0; k<4; k++){
          int _dx = p.x + dx[k], _dy = p.y + dy[k];
          if(_dx < 1 || _dx > l || _dy < 1 || _dy > w) continue;
          if(board[_dx][_dy] == 'W' || visited[_dx][_dy]) continue;
          q.push((pos){_dx,_dy,p.time+1});
          visited[_dx][_dy] = 1;
        }
      }
      ans = max(ans, m);
    }
  }
  printf("%d\n",ans);
  return 0;
}