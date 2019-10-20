#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int N,ans,call;
int S[25][25],G[25];

void dfs(int u, int num){
  call++;
  G[u] = 1;
  if(num == N/2){
    int ft = 0, st = 0;
    for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
        if(i==j) continue;
        if(G[i] && G[j]) ft += S[i][j];
        else if(!G[i] && !G[j]) st += S[i][j];
      }
    }
    ans = min(ans, abs(st-ft));
  } else{
    for(int i=u+1; i<=N; i++) dfs(i,num+1);
  }
  G[u] = 0;
}

int main(void)
{
  scanf("%d",&N);
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      scanf("%d",&S[i][j]);
    }
  }
  ans = INF;
  for(int i=1; i<=N; i++){
    dfs(i,1);
  }
  printf("%d %d\n",ans, call);
  return 0;
}