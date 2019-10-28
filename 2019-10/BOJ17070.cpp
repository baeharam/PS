#include <cstdio>
#include <queue>
using namespace std;

const int VER = 0;
const int HOR = 1;
const int DIA = 2;
struct pipe {
  int x1,y1,x2,y2;
  int getDir(){
    if(x1 == x2) return HOR;
    else if(y1 == y2) return VER;
    return DIA;
  }
};
int board[18][18];
int dx[3] = {0,1,1}, dy[3] = {1,0,1};
int n,ans;
queue<pipe> q;

int main(void)
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%d",&board[i][j]);
    }
  }
  pipe start = {1,1,1,2};
  q.push(start);
  while(!q.empty()){
    pipe cur = q.front(); q.pop();
    if(cur.getDir() == HOR){
      for(int i=0; i<3; i++){
        if(i==1) continue;
        int _dx = cur.x2 + dx[i], _dy = cur.y2 + dy[i];
        if(_dx <= 0 || _dx > n || _dy <= 0 || _dy > n) continue;
        if(board[_dx][_dy]==1) continue;
        if(i==2 && (board[_dx-1][_dy]==1 || board[_dx][_dy-1]==1)) continue;
        if(_dx == n && _dy == n){
          ans++;
          continue;
        }
        q.push((pipe){cur.x2,cur.y2,_dx,_dy});
      }
    } else if(cur.getDir() == VER){
      for(int i=1; i<3; i++){
        int _dx = cur.x2 + dx[i], _dy = cur.y2 + dy[i];
        if(_dx <= 0 || _dx > n || _dy <= 0 || _dy > n) continue;
        if(board[_dx][_dy]==1) continue;
        if(i==2 && (board[_dx-1][_dy]==1 || board[_dx][_dy-1]==1)) continue;
        if(_dx == n && _dy == n){
          ans++;
          continue;
        }
        q.push((pipe){cur.x2,cur.y2,_dx,_dy});
      }
    } else{
      for(int i=0; i<3; i++){
        int _dx = cur.x2 + dx[i], _dy = cur.y2 + dy[i];
        if(_dx <= 0 || _dx > n || _dy <= 0 || _dy > n) continue;
        if(board[_dx][_dy]==1) continue;
        if(i==2 && (board[_dx-1][_dy]==1 || board[_dx][_dy-1]==1)) continue;
        if(_dx == n && _dy == n){
          ans++;
          continue;
        }
        q.push((pipe){cur.x2,cur.y2,_dx,_dy});
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
