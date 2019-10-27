#include <cstdio>
#include <cstring>
using namespace std;

int n,m,v;
int dp[45][2];
bool vip[45];

int solve(int nth, int dir)
{
  if(nth > n) return 1;
  int &ret = dp[nth][dir];
  if(ret != -1) return ret;
  ret = 0;
  ret += solve(nth+1, 1);
  if(nth-1 > 0 && !vip[nth-1] && !vip[nth] && dir)
    ret += solve(nth+1, 0);
  return ret;
}

int main(void)
{
  scanf("%d%d",&n,&m);
  while(m--){
    scanf("%d",&v);
    vip[v] = true;
  }
  memset(dp,-1,sizeof(dp));
  printf("%d\n",solve(1,1));
  return 0;
}