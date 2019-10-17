#include <cstdio>
#include <algorithm>

int a[100001][4], dp[4];
int n,c1,c2,c3;

int main(void)
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=3; j++) scanf("%d", &a[i][j]);

    dp[1]=a[1][1];
    dp[2]=a[1][2];
    dp[3]=a[1][3];

    for(int i=2; i<=n; i++){
        c1=dp[1]; c2=dp[2]; c3=dp[3];
        dp[1] = a[i][1] + std::max(c1, c2);
        dp[2] = a[i][2] + std::max(c1, std::max(c2, c3));
        dp[3] = a[i][3] + std::max(c2, c3);
    }

    printf("%d ", std::max(dp[1], std::max(dp[2], dp[3])));

    dp[1]=a[1][1];
    dp[2]=a[1][2];
    dp[3]=a[1][3];

    for(int i=2; i<=n; i++){
        c1=dp[1]; c2=dp[2]; c3=dp[3];
        dp[1] = a[i][1] + std::min(c1, c2);
        dp[2] = a[i][2] + std::min(c1, std::min(c2, c3));
        dp[3] = a[i][3] + std::min(c2, c3);
    }

    
    printf("%d", std::min(dp[1], std::min(dp[2], dp[3])));

    return 0;
}