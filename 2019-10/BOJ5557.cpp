#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
int n;
ll dp[105][25];
int a[105];

ll solve(int nth, int mid)
{
  if(mid < 0 || mid > 20) return 0;
  if(nth == n) return mid==a[n];
  ll &ret = dp[nth][mid];
  if(ret != -1) return ret;
  ret = solve(nth+1, mid+a[nth]) + solve(nth+1, mid-a[nth]);
  return ret;
}

int main(void)
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++) scanf("%d",&a[i]);
  memset(dp,-1,sizeof(dp));
  printf("%lld\n", solve(2,a[1]));
  return 0;
}