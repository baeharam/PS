#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct edge{
  int u,v,cost;
  bool operator<(const edge& rhs) const {
    return cost < rhs.cost;
  }
};
typedef long long ll;
const int MOD = 1e9;
const int SIZE = 1e5;
vector<edge> e;
int n,m;
int p[SIZE+1];
ll ss[SIZE+1];
ll ans,sum;

int find(int v){
  if(v == p[v]) return v;
  return p[v] = find(p[v]);
}

void uni(int v1, int v2){
  int p1 = find(v1), p2 = find(v2);
  if(p1 == p2) return;
  if(ss[p1] > ss[p2]){
    p[p2] = p1;
    ss[p1] += ss[p2];
  }
  else {
    p[p1] = p2;
    ss[p2] += ss[p1];
  }
}

int main(void)
{
  scanf("%d%d",&n,&m);
  e.resize(m);
  for(int i=0; i<m; i++){
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].cost);
    sum += (ll)e[i].cost;
  }
  for(int i=1; i<=n; i++){
    p[i] = i;
    ss[i] = 1LL;
  }
  sort(e.begin(),e.end());
  for(int i=m-1; i>=0; i--){
    int u = e[i].u, v = e[i].v, cost = e[i].cost;
    int pu = find(u), pv = find(v);
    if(pu != pv){
      ans += (ss[pu]*ss[pv])*sum;
      ans %= MOD;
      uni(u,v);
    }
    sum -= cost;
  }
  printf("%lld\n",ans);
  return 0;
}