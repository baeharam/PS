#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 50005;
int land[SIZE],interval[SIZE];
int d,n,m;

int main(void)
{
  scanf("%d%d%d",&d,&n,&m);
  land[0] = 0; land[n+1] = d;
  for(int i=1; i<=n; i++) scanf("%d",&land[i]);
  sort(land,land+n+2);
  for(int i=1; i<=n+1; i++) interval[i] = land[i] - land[i-1];
  
  int num = (n+1) - m;
  int l = 1, r = d-num+1;
  int ans = 0;
  while(l <= r){
    int m = (l + r) / 2;
    int group = 0, sum = 0;
    int minV = 2e9;
    for(int i=1; i<=n+1; i++){
      sum += interval[i];
      if(sum >= m){
        minV = min(minV, sum);
        if(group < num) group++;
        sum = 0;
      }
    }
    if(group < num) r = m-1;
    else if(group == num){
      l = m+1;
      ans = max(ans, minV);
    }
  }
  printf("%d\n",ans);
  return 0;
}