#include <cstdio>
#include <queue>
using namespace std;

struct coor{int x,y;};
int B[105][105];
queue<coor> q;
char D[10005];
int N,K,L,R,C,X;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
const int BODY = 4, APPLE = 5, RIGHT = 1;

int main(void)
{
  scanf("%d%d",&N,&K);
  for(int i=0; i<K; i++){
    scanf("%d%d",&R,&C);
    B[R-1][C-1] = APPLE;
  }
  scanf("%d",&L);
  for(int i=0; i<L; i++){
    scanf("%d",&X);
    scanf(" %c",&D[X]);
  }
  int time = 0, dir = RIGHT;
  int cx = 0, cy = 0, tx = 0, ty = 0;
  B[cx][cy] = BODY;
  q.push((coor){cx,cy});
  while(true){
    cx += dx[dir];
    cy += dy[dir];
    if(cx < 0 || cx >= N || cy < 0 || cy >= N) break;
    if(B[cx][cy] == BODY) break;
    if(B[cx][cy] != APPLE){
      B[q.front().x][q.front().y] = 0;
      q.pop();
    }
    q.push((coor){cx, cy});
    B[cx][cy] = BODY;
    time++;
    if(D[time] == 'D') dir = (dir+1)%4;
    else if(D[time] == 'L') dir = (dir+3)%4;
  }
  printf("%d\n",time+1);
  return 0;
}