#include <cstdio>

int n,m,x,y,k;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int normal[4],side[4];
int b[25][25];
const int E=0,W=1,N=2,S=3;

int main(void)
{
  scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d",&b[i][j]);
    }
  }
  int dir;
  while(k--){
    scanf("%d",&dir);
    dir -= 1;
    int _dx = x+dx[dir], _dy = y+dy[dir];
    if(_dx < 0 || _dx >= n || _dy < 0 || _dy >=m) continue;
    x = _dx; y = _dy;
    if(dir == E){
      int temp = side[0];
      for(int i=1; i<4; i++) side[i-1] = side[i];
      side[3] = temp;
      normal[1] = side[1];
      normal[3] = side[3];
    }else if(dir == W){
      int temp = side[3];
      for(int i=3; i>0; i--) side[i] = side[i-1];
      side[0] = temp;
      normal[1] = side[1];
      normal[3] = side[3];
    }else if(dir == N){
      int temp = normal[0];
      for(int i=1; i<4; i++) normal[i-1] = normal[i];
      normal[3] = temp;
      side[1] = normal[1];
      side[3] = normal[3];
    }else{
      int temp = normal[3];
      for(int i=3; i>0; i--) normal[i] = normal[i-1];
      normal[0] = temp;
      side[1] = normal[1];
      side[3] = normal[3];
    }
    if(b[x][y] == 0) b[x][y] = normal[3];
    else{
      normal[3] = side[3] = b[x][y];
      b[x][y] = 0;
    }
    printf("%d\n",normal[1]);
  }
  return 0;
}