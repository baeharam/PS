#include <cstdio>
#include <vector>
using namespace std;

struct s{int v,f,c;};
int tc,n,d;

int main(void)
{
  scanf("%d", &tc);
  while(tc--){
    scanf("%d%d",&n,&d);
    vector<s> ss;
    for(int i=0; i<n; i++){
      s _s;
      scanf("%d%d%d",&_s.v,&_s.f,&_s.c);
      ss.push_back(_s);
    }
    int ans = 0;
    for(s _s : ss){
      double nn = d/(double)_s.v;
      ans += (nn*_s.c <= _s.f);
    }
    printf("%d\n",ans);
  }
  return 0;
}