#include <cstdio>

int n,m,r,c,d;
int b[55][55],clean[55][55];
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int main(void)
{
  scanf("%d%d%d%d%d",&n,&m,&r,&c,&d);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d",&b[i][j]);
    }
  }

  int ans = 0;
  while(true){
    clean[r][c] = 1;
    ans++;
    int _r = 0, _c = 0;
    int rnum = 0;
    bool isStop = false;
    while(true){
      if(rnum == 4){
        int back = (d + 2) % 4;
        _r = r + dx[back], _c = c + dy[back];
        if(_r < 0 || _r >= n || _c < 0 || _c >= m || b[_r][_c]==1){
          isStop = true;
          break;
        } else {
          r = _r;
          c = _c;
          rnum = 0;
          continue;
        }
      }
      int left = (d + 3) % 4;
      _r = r + dx[left], _c = c + dy[left];
      if(_r < 0 || _r >= n || _c < 0 || _c >= m || clean[_r][_c] || b[_r][_c]==1){
        rnum++;
        d = left;
        continue;
      } else {
        rnum = 0;
        r = _r;
        c = _c;
        d = left;
        break;
      }
    }
    if(isStop) break;
  }
  printf("%d\n",ans);
  return 0;
}