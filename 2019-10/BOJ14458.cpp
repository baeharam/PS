#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000005];
int n,b,c;
long long ans;

int main(void)
{
  scanf("%d",&n);
  for(int i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%d%d",&b,&c);
  sort(a,a+n);
  ans += n;
  for(int i=0; i<n; i++){
    a[i] -= b;
    if(a[i] < 0) continue;
    ans += (long long)(a[i]%c ? a[i]/c+1 : a[i]/c);
  }
  printf("%lld\n",ans);
  return 0;
}