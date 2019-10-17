#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// i행 j열에서 판다가 살 수 있는 일수
int dp[501][501], forest[501][501], n;


int move(int x, int y)
{
    // 메모이제이션 된 경우
    if(dp[x][y]!=-1) return dp[x][y];

    if(x-1>=0 && forest[x-1][y]>forest[x][y]) 
        dp[x][y] = move(x-1, y) + 1;
    if(x+1<=n && forest[x+1][y]>forest[x][y]) 
        dp[x][y] = max(dp[x][y], move(x+1, y)+1);
    if(y-1>=0 && forest[x][y-1]>forest[x][y]) 
        dp[x][y] = max(dp[x][y], move(x, y-1)+1);
    if(y+1<=n && forest[x][y+1]>forest[x][y]) 
        dp[x][y] = max(dp[x][y], move(x, y+1)+1);

    // 상하좌우 아무데도 못가는 경우
    if(dp[x][y]==-1) dp[x][y] = 1;

    return dp[x][y];
}


int main(void)
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            scanf("%d",&forest[i][j]);
    }
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            ans = max(ans, move(i, j));
    }

    printf("%d\n", ans);
    return 0;
}