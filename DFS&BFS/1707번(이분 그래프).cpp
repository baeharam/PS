#include <cstdio>
#include <vector>
using namespace std;

bool visit[20001], isbi;
int colors[20001];
vector<int> g[20001];
enum {RED, BLUE};
int tc,v,e,v1,v2;

void dfs(int node)
{
    visit[node] = true;
    for(int i=0; i<g[node].size(); i++){
        if(!visit[g[node][i]]){
            colors[g[node][i]] = (colors[node]==RED ? BLUE : RED);
            dfs(g[node][i]);
        }
    }
}


int main(void)
{
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d",&v,&e);
        for(int i=1; i<=v; i++) visit[i]=false;
        for(int i=0; i<e; i++){
            scanf("%d%d",&v1,&v2);
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        for(int i=1; i<=v; i++){
            if(!visit[i]) {
                colors[i]=RED;
                dfs(i);
            }
        }

        isbi=true;
        for(int i=1; i<=v; i++){
            for(int j=0; j<g[i].size(); j++){
                if(colors[i]==colors[g[i][j]]){
                    isbi=false;
                    break;
                }
            }
            if(!isbi) break;
        }
        isbi ? puts("YES") : puts("NO");
        for(int i=1; i<=v; i++) g[i].clear();
    }
    return 0;
}