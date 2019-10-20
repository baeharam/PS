#include <cstdio>
#include <algorithm>
using namespace std;

int dp[305][305];
int path[305][305];
int n,m,k,p1,p2,s;
const int INF = -2e9;

int main(void)
{
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0; i<k; i++){
    scanf("%d%d%d",&p1,&p2,&s);
    path[p1][p2] = max(path[p1][p2], s);
  }
  for(int i=1; i<=n; i++){
    if(i > 1) dp[i][0] = INF;
    for(int j=1; j<=n; j++){
      dp[i][j] = i<=j ? INF : 0;
    }
  }
  for(int i=2; i<=n; i++){
    int mm = i==n ? m-1 : m-2;
    int limit = (i-1>=mm ? mm : i-1);
    for(int j=1; j<=limit; j++){
      for(int k=1; k<i; k++){
        if(dp[i-k][j-1] == INF || path[i-k][i] == 0){
          if(dp[i][j]) continue;
          dp[i][j] = INF;
        }
        else dp[i][j] = max(dp[i][j], dp[i-k][j-1] + path[i-k][i]);
        printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
      }
    }
  }
  int ans = 0;
  for(int i=1; i<=m; i++) ans = max(ans, dp[n][i]);
  printf("%d\n",ans);
  return 0;
}