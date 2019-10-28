#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,m,v1,v2,ans;
int vi[105],out[105];
vector<int> g1[105],g2[105];

void dfs(int v, int fix, bool dir)
{
  vi[v] = 1;
  for(int next : (dir ? g1[v] : g2[v])){
    if(vi[next]) continue;
    out[fix]++;
    dfs(next,fix,dir);
  }
}

int main(void)
{
  scanf("%d%d",&n,&m);
  for(int i=0; i<m; i++){
    scanf("%d%d",&v1,&v2);
    g1[v2].push_back(v1);
    g2[v1].push_back(v2);
  }
  for(int i=1; i<=n; i++){
    dfs(i,i,true);
    memset(vi,0,sizeof(vi));
  }
  for(int i=1; i<=n; i++){
    if(out[i] >= (n+1)/2) ans++;
    out[i] = 0;
  }
  for(int i=1; i<=n; i++){
    dfs(i,i,false);
    memset(vi,0,sizeof(vi));
  }
  for(int i=1; i<=n; i++){
    if(out[i] >= (n+1)/2) ans++;
    out[i] = 0;
  }
  printf("%d\n",ans);
  return 0;
}
