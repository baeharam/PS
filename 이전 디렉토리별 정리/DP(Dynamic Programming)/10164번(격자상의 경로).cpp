#include <cstdio>
#include <cstring>

typedef long long ll;

ll dp[16][16], path;
int n, m, k, ox, oy, tx, ty;

ll go(int x, int y)
{
    // 범위를 넘어서는 경우
    if(x>ox || y>oy) return 0LL;

    // 표시된 지점에 도달한 경우
    if(x==ox && y==oy) return dp[x][y] = 1LL;

    if(dp[x][y]!=-1) return dp[x][y];
    ll &ans = dp[x][y];

    return ans = go(x+1,y) + go(x, y+1);
}


int main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d",&n, &m, &k);

    ox = k ? (k%m ? k/m+1 : k/m) : n;
    oy = k ? (k%m ? k%m : m) : m;
    
    path = go(1,1);

    if(k){
        tx = ox, ty = oy;
        ox = n, oy = m;
        path *= (go(tx+1, ty) + go(tx, ty+1));
    }

    printf("%lld\n", path);
    return 0;
}