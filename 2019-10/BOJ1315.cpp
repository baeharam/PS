#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct info{ int it, pw, point;};
const int SIZE = 1000;
vector<info> quest;
int n,it,pw,point;
int dp[SIZE+1][SIZE+1];

int f(int ss, int ii, int bpoint)
{
  if(ss >= SIZE || ii >= SIZE) return n;
  int &ret = dp[ss][ii];
  if(ret != -1) return ret;
  int point = 0, num = 0;
  for(info q : quest){
    if(ss >= q.pw || ii >= q.it){
      point += q.point;
      num++;
    }
  }
  if(bpoint == point) return 0;
  int pbegin = 0, pend = point-bpoint;
  ret = num;
  for(int i=pbegin,j=pend; i<=pend && j>=pbegin; i++,j--){
    ret = max(ret, f(ss+i,ii+j,point));
  }
  return ret;
}

int main(void)
{
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d%d%d",&it,&pw,&point);
    quest.push_back((info){it,pw,point});
  }
  memset(dp,-1,sizeof(dp));
  printf("%d\n",f(1,1,0));
  return 0;
}