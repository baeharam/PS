#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int cn,gn;
int cc[35],gg[10];
int dp[35][15005];

// dp[idx][weight] = idx번째 까지의 추를 사용했을 때 weight이라는 무게를 만들 수 있는가?
void f(int idx, int weight)
{
  if(idx > cn) return;
  int &ret = dp[idx][weight];
  if(ret != -1) return;
  ret = 1;
  f(idx+1, weight+cc[idx]);
  f(idx+1, weight);
  f(idx+1, abs(weight-cc[idx]));
}

int main(void)
{
  scanf("%d",&cn);
  for(int i=0; i<cn; i++) scanf("%d",&cc[i]);
  scanf("%d",&gn);
  for(int i=0; i<gn; i++) scanf("%d",&gg[i]);
  memset(dp,-1,sizeof(dp));
  f(0,0);
  for(int i=0; i<gn; i++) 
    dp[cn][gg[i]]!=-1 ? printf("Y ") : printf("N ");
  return 0;
}