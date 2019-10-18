#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,ans;
int a[105],sum[105];
int dp[105][105];

int main(void)
{
  scanf("%d%d",&n,&m);
  for(int i=0; i<n; i++){
    scanf("%d",&a[i]);
    sum[i] = a[i];
    if(!i) continue;
    sum[i] += sum[i-1];
  }
  for(int i=0; i<n; i++){
    for(int j=1; j<=m; j++){
      dp[i][j] = -2e9;
    }
  }

  dp[0][1] = a[0];
  for(int i=1; i<n; i++){
    for(int j=1; j<=m; j++){
      dp[i][j] = dp[i-1][j];
      int limit = 2*(j-1)-1;
      for(int k=1; i-k >= limit; k++){
        int _dp = i-k-1<0 ? 0 : dp[i-k-1][j-1];
        int _sum = i-k<0 ? sum[i] : sum[i] - sum[i-k];
        dp[i][j] = max(dp[i][j], _dp + _sum);
      }
      printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
    }
  }
  printf("%d\n",dp[n-1][m]);
  return 0;
}